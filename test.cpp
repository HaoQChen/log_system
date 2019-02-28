#include <map>

#include <dlib/image_io.h>
#include <dlib/gui_widgets.h>

#include "log_system.h"

using namespace dlib;
using namespace std;
using namespace logsystem;



void help(const std::map<string, int>& order_map)
{
    cout << "you can put in ";
    for(auto order : order_map){
        cout << "\"" << order.first << "\" ";
    }
    cout << "to execute relative order" << endl;
}


int main(int argc, char** argv) try
{  
    string order;
    string n, p, pho;
    matrix<rgb_pixel> img;
    int i_order;
    UserManage um;
    int result = 0;
    image_window win;

    std::map<string, int> order_map;
    order_map["su"] = 1;
    order_map["fsi"] = 2;
    order_map["q"] = 3;
    order_map["who"] = 4;
    order_map["so"] = 5;
    order_map["psi"] = 6;
    order_map["da"] = 7;
    help(order_map);
    while(1){
        getline(std::cin, order);
        auto om_find = order_map.find(order);
        if(om_find == order_map.end())
            i_order = 0;
        else
            i_order = om_find->second;
        switch(i_order){
            case 1://signup
                cout << "Please enter name!" << endl;
                getline(std::cin, n);
                cout << "Please enter password!" << endl;
                getline(std::cin, p);
                cout << "Please enter photo path!" << endl;
                getline(std::cin, pho);
                load_image(img, pho);
                if(img.size() == 0){
                    cout << "invalid photo" << endl;
                    break;
                }
                win.set_image(img);
                result = um.signUp(n, img, p);
                cout << "sign up result is: " << result << endl;
                break;
            case 2://facesignin
                cout << "Please enter photo path!" << endl;
                getline(std::cin, pho);
                
                load_image(img, pho);
                if(img.size() == 0){
                    cout << "invalid photo" << endl;
                    break;
                }
                win.set_image(img);
                result = um.signInByFace(img);
                cout << "sign in result is: " << result << ". means: " << um.getCurrentUserName() << endl;
                break;
            case 3://quit
                return 0;
            case 4://who
                cout << "current user is: " << um.getCurrentUserName() << endl;
                break;
            case 5://sign out
                um.signOut();
                break;
            case 6://password sign in
                cout << "Please enter name!" << endl;
                getline(std::cin, n);
                cout << "Please enter password!" << endl;
                getline(std::cin, p);
                result = um.signInByPassword(n, p);
                cout << "sign in result is: " << result << ". means: " << um.getCurrentUserName() << endl;
                break;
            case 7://delete account
                cout << "If you are sure to delete your account, please end \"ok\"" << endl;
                getline(std::cin, n);
                if(n == "ok")
                    um.deleteAccount();
                break;
            default:
                help(order_map);
        }
    }
    return 0;
}catch (std::exception& e){
    cout << e.what() << endl;
}