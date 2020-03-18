// CPP program to detects face in a video 

// Include required header files from OpenCV directory 
#include <opencv2/objdetect.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/opencv.hpp>
#include <iostream> 

using namespace std;
using namespace cv;


int main(int argc, const char** argv)
{
	Mat image = imread("imagens/imagem3.jpg", 1);
	namedWindow("image", CV_WINDOW_FREERATIO);
	imshow("image", image);
	waitKey(0);

	// RED
	Mat OutputImage;
	inRange(image, Scalar(10, 10, 100), Scalar(100, 100, 255), OutputImage);

	// BLUE
	Mat OutputImage2;
	inRange(image, Scalar(100, 10, 10), Scalar(255, 100, 100), OutputImage2);

	int x1, x2;
	x1 = countNonZero(OutputImage);
	x2 = countNonZero(OutputImage2);

	if (x1 > x2)
		cout << "Vermelho";
	else
		cout << "Azul";

	namedWindow("Ouput", CV_WINDOW_FREERATIO);
	imshow("Output", OutputImage2);
	waitKey(0);
}