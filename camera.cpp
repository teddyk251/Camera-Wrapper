#include "opencv2/imgproc.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/core.hpp"
#include <iostream>

using namespace cv;
using namespace std;

class Camera
{
    private:
    int deviceId;
    VideoCapture cap;
    static Camera* instance;

    Camera(int device=0,double width=300, double height=300)
    {
        
        deviceId = device;
        VideoCapture cap1(device);
        this->cap = cap1;
        cap.set(CV_CAP_PROP_FRAME_WIDTH,width);
        cap.set(CV_CAP_PROP_FRAME_HEIGHT,height);
    }
    
    public:
    static Camera* getInstance(int device=0, double width=300, double height=300){
        if(!instance)
        {
            instance = new Camera(device,width,height);
            return instance;
        }
    }
    void openCamera()
    {
        if(!this->cap.isOpened()){
            cap.open(deviceId);
        }
    }
    Mat readCamera()
    {
        if(this->cap.isOpened())
        {
            Mat image;
            cap.read(image);
            return image;
        }
    }
    void closeCamera()
    {
        if(this->cap.isOpened())
        {
            cap.release();
        }
    }
    void saveImage()
    {
        for(;;)
        {
            Mat image = readCamera();
            imwrite("image.png",image);
            imshow("Camera",image);
            if(waitKey(30) >= 0)
                break;
        }
        destroyAllWindows();
    }
    
};