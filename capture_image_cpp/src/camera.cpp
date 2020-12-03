#include "camera.hpp"

Camera::Camera(CameraConfig configuration)
{
    config = configuration;
    url =  create_url_capture();
    connect();
    fps = cap.get(CAP_PROP_FPS);
    cout<<"Câmera: "<<config.marca_modelo<<"; ID: "<<config.id<<"; URL: "<<url<<"; FPS: "<<fps<<endl;
    cout<<"Conexão: "<<is_connection_open()<<endl;

}

Camera::Camera(int camera)
{
    usb_camera = camera;
    connect();
    fps = cap.get(CAP_PROP_FPS);
    cout<<"Câmera: "<<config.ip<<endl;
    cout<<"Conexão: "<<is_connection_open()<<endl;

}

void Camera::update_config(CameraConfig configuration)
{
    config = configuration;
}

void Camera::connect()
{
    cout<<"Connecting cam:"<<usb_camera<<endl;
    cap.open(usb_camera);
}

void Camera::disconnect()
{
    cout<<"Disconnecting cam"<<endl;
    cap.release();
}

bool Camera::is_connection_open()
{
    return cap.isOpened();
}

void Camera::capture_image(Mat* frame)
{
    // Mat frame;
    //cap.read(frame);
    cap>>*frame;
    // return frame;
}

string Camera::create_url_capture()
{
    string _url;
    if (config.marca_modelo == "hikvision")
    {
        _url = "http://"+config.user+":" + config.password + "@" + config.ip + "/Streaming/channels/101/preview";
    }

    if (config.marca_modelo == "pumatronix")
    {
        _url = "http://" + config.ip + "/api/mjpegvideo.cgi?Quality=50&Resolution=640x480";
    }
    return _url;
}