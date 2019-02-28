#include <vector>
#include <dlib/image_processing/frontal_face_detector.h>
#include <dlib/graph_utils.h>//cosine_distance


#include <dlib/opencv.h>

#include "log_system.h"

using namespace std;
using namespace dlib;
using namespace cv;



#define DEBUG_OUT 1



namespace logsystem
{

    static bool GetFaceDescriptor(const dlib::matrix<dlib::rgb_pixel>& img, matrix<float,0,1>& fd)
    {
        frontal_face_detector detector = get_frontal_face_detector();

        shape_predictor sp;
        deserialize("../dlib/data/shape_predictor_5_face_landmarks.dat") >> sp;

        anet_type net;
        deserialize("../dlib/data/dlib_face_recognition_resnet_model_v1.dat") >> net;
        
        std::vector<dlib::rectangle> dets = detector(img);
        if(dets.size() != 1)//more than or less than one face
            return false;

        auto shape = sp(img, dets[0]);
        matrix<rgb_pixel> face_chip;
        extract_image_chip(img, get_face_chip_details(shape,150,0.25), face_chip);
        matrix<rgb_pixel> face = move(face_chip);

        fd = net(face);
        return true;
    }

    void Person::save2XML(cv::FileStorage& fs) 
    {
        fs << "name" << name_;
        fs << "password" << password_;
        fs << "face_description" << toMat(face_descriptor_);
    }

    double Person::faceCosineDistanceWith(matrix<float,0,1>& face_desc) const
    {
        cosine_distance cos_dis;
        return cos_dis(face_descriptor_, face_desc);
    }


    UserManage::UserManage(const string poud, const double fst) : kPathOfUsersData_(poud), kFaceSimilarityThreshold_(fst)
    {
        current_signin_ = -1;
        readFromXML();
    }

    void UserManage::save2XML()
    {
        FileStorage fs(kPathOfUsersData_, FileStorage::WRITE);
        fs << "userCount" << (int)users_.size();
        for(int i = 0; i < users_.size(); ++i){
            fs << string("No_") + to_string(i + 1) << "{";
            users_[i].save2XML(fs);
            fs << "}";
        }
        fs.release();
    }

    void UserManage::readFromXML()
    {
        FileStorage fs;
        if(fs.open(kPathOfUsersData_, FileStorage::READ)){
            int user_count = (int)fs["userCount"];
            for(int i = 0; i < user_count; ++i){
                string n = (string)fs[string("No_") + to_string(i + 1)]["name"];
                string p = (string)fs[string("No_") + to_string(i + 1)]["passpord"];
                Mat mfd;
                fs[string("No_") + to_string(i + 1)]["face_description"] >> mfd;
                cv_image<float> cfd(mfd);
                matrix<float> dfd(dlib::mat(cfd));
                users_.push_back(Person(n, p, dfd));
            }
        }
        fs.release();
    }

    int UserManage::signUp(const std::string n, const dlib::matrix<dlib::rgb_pixel>& img, const std::string p)
    {
        for(int i = 0; i < users_.size(); ++i){
            if(users_[i].name_ == n)//name can not be same with one of the users
                return -1;
        }
        matrix<float,0,1> face_desc;
        if(!GetFaceDescriptor(img, face_desc))
            return -2;

        users_.push_back(Person(n, p, face_desc));
        save2XML();
        return 0;
    }

    int UserManage::signOut()
    {
        current_signin_ = -1;
        return 0;
    }

    //return the index of users_
    int UserManage::signInByFace(const dlib::matrix<dlib::rgb_pixel>& img)
    {
        matrix<float,0,1> face_desc;
        if(!GetFaceDescriptor(img, face_desc))
            return -2;
        double max_similarity = 0.0;
        int max_index = -1;
        for(int i = 0; i < users_.size(); ++i){
            double fcd = 1.0 - users_[i].faceCosineDistanceWith(face_desc);
            if(fcd > max_similarity){
                max_similarity = fcd;
                max_index = i;
            }
        }
        if(max_similarity > kFaceSimilarityThreshold_){
#ifdef DEBUG_OUT
            cout << "max_similarity is: " << max_similarity << endl;
#endif//DEBUG_OUT
            current_signin_ = max_index;
            return max_index;
        }
        else
            return -1;
    }

    int UserManage::signInByPassword(const std::string n, const std::string p)
    {
        int index = findByName(n);
        if(0 > index)
            return -1;
        if(users_[index].isPasswordRight(p)){
            current_signin_ = index;
            return index;
        }
        else
            return -2;
    }

}//namespace logsystem