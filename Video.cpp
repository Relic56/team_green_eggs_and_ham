#include <opencv2/opencv>
#include "Video.hpp"

using namespace cv;

Video::Video()
{

}

void Video::init(int camID)
{
    VideoCapture cap(camID);
    if(!cap.isOpened())
    {
	std::cout<<"No camera found";
	return -1;
    }
}

Mat Video::getFrame()
{
    cam >> img;
    return img;
}
