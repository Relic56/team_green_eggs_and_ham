#include <opencv2/opencv>

using namespace cv;

class Video
{
    public:
	Video();
	void init(int camID);
	Mat getFrame();
    private
	VideoCapture cam;
	Mat img;
};

