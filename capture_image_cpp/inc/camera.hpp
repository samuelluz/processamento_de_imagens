#ifndef __CAMERA__
#define __CAMERA__

#include <string>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

struct CameraConfig
{
    string id = "0";
    string ip = "0";
    string tipo = "usb";
    string marca_modelo = "";
    string user = "";
    string password = "";
};

class Camera{

    public:
        Camera(CameraConfig);
        Camera(int);
        void update_config(CameraConfig);
        void connect();
        void disconnect();
        bool is_connection_open();
        void capture_image(Mat*);

        string create_url_capture();
        
        CameraConfig config;
        VideoCapture cap;
        double fps;
        string url;
        int usb_camera;
};

#endif