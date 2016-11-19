#include "opencv2/opencv.hpp"
using namespace cv;

int threshold(Mat image)
{

   Mat img_hsv;
    cvtColor(image, img_hsv, CV_BGR2HSV);
     std::vector<cv::Mat> channels;
     split(img_hsv, channels);

     Mat hueOrig = channels.at(0).clone();
     Mat threshLower, threshUpper;
     Mat result;

     threshold(hueOrig, threshLower, 60, 255, CV_THRESH_BINARY);
     threshold(hueOrig, threshUpper, 180, 255, CV_THRESH_BINARY_INV);

     result = threshLower & threshUpper;

    imshow("Thresholded", result);
}
int main()
{
    VideoCapture cap(1);
   if(!cap.isOpened())  // check if we succeeded
       return -1;

    Mat edges;
    namedWindow("edges",1);for(;;)
    while(true)
    {
        Mat frame;
        cap >> frame; // get a new frame from camera
        cvtColor(frame, edges, COLOR_BGR2GRAY);
        GaussianBlur(edges, edges, Size(7,7), 1.5, 1.5);
        Canny(edges, edges, 0, 30, 3);
        imshow("edges", edges);
        threshold(frame);

        if(waitKey(30) >= 0)
          break;
   }
    // the camera will be deinitialized automatically in VideoCapture destructor
    return 0;
}
