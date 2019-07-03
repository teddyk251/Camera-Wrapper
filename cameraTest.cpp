#include <iostream>
#include "camera.cpp"

Camera *Camera::instance = 0;

using namespace std;

int main()
{
    Camera *cam = cam->getInstance(0,300,400);
    cam->openCamera();
    cam->saveImage();
    cam->closeCamera();
    return 0;
}