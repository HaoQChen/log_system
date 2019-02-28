#ifndef _LOG_SYSTEM_H_
#define _LOG_SYSTEM_H_

#include <string>
#include <vector>

#include <dlib/opencv.h>

#include <dlib/image_io.h>
#include <dlib/dnn.h>
#include <dlib/clustering.h>
#include <dlib/image_processing/frontal_face_detector.h>


namespace logsystem
{
    using namespace dlib;
    using namespace std;
//template for face detection and recognition
    template <template <int,template<typename>class,int,typename> class block, int N, template<typename>class BN, typename SUBNET>
    using residual = add_prev1<block<N,BN,1,tag1<SUBNET>>>;

    template <template <int,template<typename>class,int,typename> class block, int N, template<typename>class BN, typename SUBNET>
    using residual_down = add_prev2<avg_pool<2,2,2,2,skip1<tag2<block<N,BN,2,tag1<SUBNET>>>>>>;

    template <int N, template <typename> class BN, int stride, typename SUBNET> 
    using block  = BN<con<N,3,3,1,1,relu<BN<con<N,3,3,stride,stride,SUBNET>>>>>;

    template <int N, typename SUBNET> using ares      = relu<residual<block,N,affine,SUBNET>>;
    template <int N, typename SUBNET> using ares_down = relu<residual_down<block,N,affine,SUBNET>>;

    template <typename SUBNET> using alevel0 = ares_down<256,SUBNET>;
    template <typename SUBNET> using alevel1 = ares<256,ares<256,ares_down<256,SUBNET>>>;
    template <typename SUBNET> using alevel2 = ares<128,ares<128,ares_down<128,SUBNET>>>;
    template <typename SUBNET> using alevel3 = ares<64,ares<64,ares<64,ares_down<64,SUBNET>>>>;
    template <typename SUBNET> using alevel4 = ares<32,ares<32,ares<32,SUBNET>>>;

    using anet_type = loss_metric<fc_no_bias<128,avg_pool_everything<
                                alevel0<
                                alevel1<
                                alevel2<
                                alevel3<
                                alevel4<
                                max_pool<3,3,2,2,relu<affine<con<32,7,7,2,2,
                                input_rgb_image_sized<150>
                                >>>>>>>>>>>>;


    class Person{
    public:

        Person(const std::string n, const std::string p, const dlib::matrix<float,0,1>& fd) : name_(n), password_(p), face_descriptor_(fd){}
        
        void save2XML(cv::FileStorage& fs);//because of toMat function, could not use const modify

        // const std::string& getPassword(){ return password_; }
        // const dlib::matrix<float,0,1>& getFaceDescription(){ return face_descriptor_; }

        double faceCosineDistanceWith(matrix<float,0,1>& face_desc) const;

        bool isPasswordRight(const string p) const {return (p == password_);}

        std::string name_;
    private:
        std::string password_;
        dlib::matrix<float,0,1> face_descriptor_;
    };//class Person



    class UserManage{
    public:
        UserManage(const string poud = "./users_data.xml", const double fst = 0.9);

        //return 0 when everything is ok
        //return -1 when already have the same name
        //return -2 can not get the face description
        int signUp(const std::string n, const dlib::matrix<dlib::rgb_pixel>& img, const std::string p = "123456");

        void deleteUser();

        //return >=0 when everything is ok, return the index of users_
        //return -1 did not match a user by kFaceSimilarityThreshold_
        //return -2 can not get the face description
        int signInByFace(const dlib::matrix<dlib::rgb_pixel>& img);//return the index of users_

        //return >=0 when everything is ok, return the index of users_
        //return -1 can not find the user name in the list
        //return -2 password does not match
        int signInByPassword(const std::string n, const std::string p);

        int signOut();

        void deleteAccount()
        {
            if(current_signin_ >= 0){
                users_.erase(users_.begin()+current_signin_);
                current_signin_ = -1;
                save2XML();
            }
        }

        ~UserManage(){}

        //return index of users_ 
        //-1 means not find
        int findByName(const std::string n) const
        {
            for(int i = 0; i < users_.size(); ++i){
                if(users_[i].name_ == n)
                    return i;
            }
            return -1;
        }

        const string getCurrentUserName() const
        {
            if(current_signin_ < 0)
                return string("Nobody");
            else
                return users_[current_signin_].name_;
        }

        bool isSomeoneSignin() const {return (current_signin_ >= 0);}

    private:
        void save2XML();
        void readFromXML();

        std::vector<Person> users_;
        const string kPathOfUsersData_;
        const double kFaceSimilarityThreshold_;
        int current_signin_;//index of users_
    };//class FaceLog


}//ns logsystem

#endif//_LOG_SYSTEM_H_