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
	cv::VideoCapture webCam(0);
	Mat frame;
	namedWindow("image", CV_WINDOW_FREERATIO);

	const int FRAMES_MINIMOS_PARA_VALIDACAO = 130;

	int framesVermelhos, framesVerdes, framesAzuis;
	framesVermelhos = framesVerdes = framesAzuis = 0;


	if (!webCam.isOpened()) // Caso falhe em iniciar webam
	{
		return 1;
	}

	while (webCam.read(frame)) // webCam >> frame
	{
		imshow("WebCam", frame); // Mostra o frame lido do webcam

		// BGR COLOR
		// RED
		Mat OutputImage;
		inRange(frame, Scalar(10, 10, 100), Scalar(50, 50, 255), OutputImage);

		// BLUE
		Mat OutputImage2;
		inRange(frame, Scalar(100, 10, 10), Scalar(255, 50, 50), OutputImage2);

		// GREEN
		Mat OutputImage3;
		inRange(frame, Scalar(10, 100, 10), Scalar(50, 255, 50), OutputImage3);


		int x1, x2, x3;
		x1 = countNonZero(OutputImage);
		x2 = countNonZero(OutputImage2);
		x3 = countNonZero(OutputImage3);

		if (x1 > x2 && x1 > x3)
		{
			framesVermelhos++;
			framesAzuis = 0;
			framesVerdes = 0;
		}
		else if (x2 > x1 && x2 > x3)
		{
			framesAzuis++;
			framesVermelhos = 0;
			framesVerdes = 0;
		}
		else if (x3 > x1 && x3 > x2)
		{
			framesVerdes++;
			framesVermelhos = 0;
			framesAzuis = 0;
		}

		if (framesVermelhos >= FRAMES_MINIMOS_PARA_VALIDACAO)
		{
			cout << "Vermelho ";
			framesVermelhos = 0;
			framesAzuis = 0;
			framesVerdes = 0;
		}

		if (framesAzuis >= FRAMES_MINIMOS_PARA_VALIDACAO)
		{
			cout << "Azul ";
			framesVermelhos = 0;
			framesAzuis = 0;
			framesVerdes = 0;
		}

		if (framesVerdes >= FRAMES_MINIMOS_PARA_VALIDACAO)
		{
			cout << "Verde ";
			framesVermelhos = 0;
			framesAzuis = 0;
			framesVerdes = 0;
		}

		namedWindow("Ouput", CV_WINDOW_FREERATIO);

		if (cv::waitKey(1000 / 1000) >= 0) // Delay + Pressiona um botão pra sair
		{
			break;
		}
	}
	waitKey(0);
}
