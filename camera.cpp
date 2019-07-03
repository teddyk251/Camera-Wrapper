#include "opencv2/imgproc.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/core.hpp"

using namespace cv;

class Camera
{
    private:
    int deviceId;
    VideoCapture cap;
    
    public:
    Camera(int device=0,double width=300, double height=300)
    {
        deviceId = device;
        VideoCapture cap(device);
        cap.set(CV_CAP_PROP_FRAME_WIDTH,width);
        cap.set(CV_CAP_PROP_FRAME_HEIGHT,height);


    }
    
};