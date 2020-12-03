#include <iostream>
#include "camera.hpp"

int main( int argc, char **argv)
{
    Camera cam(0);

    while(cam.is_connection_open())
    {
        Mat frame;
        cam.capture_image(&frame);
        imshow("Teste", frame);
        if(waitKey(1)==113)
        {
            cout<<"Esc key is pressed by user. Stopping the video"<<endl;
            break;
        }
    }
    cout<<"Video Stoped"<<endl;
    return 0;
}
