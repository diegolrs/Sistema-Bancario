#include <opencv2/objdetect.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/opencv.hpp>
#include <iostream> 

int main(int argc, const char** argv)
{
	cv::VideoCapture webCam(0);
	cv::Mat frame;

	const int FRAMES_MINIMOS_PARA_VALIDACAO = 130;

	int framesVermelhos, framesVerdes, framesAzuis;
	framesVermelhos = framesVerdes = framesAzuis = 0;

	if (!webCam.isOpened()) // Caso falhe em iniciar webam
		return 1;
	

	while (webCam.read(frame)) // webCam >> frame
	{
		cv::imshow("WebCam", frame); // Mostra o frame lido do webcam

		// BGR COLOR
		// RED
		cv::Mat OutputImage;
		cv::inRange(frame, cv::Scalar(10, 10, 120), cv::Scalar(40, 40, 255), OutputImage);

		// BLUE
		cv::Mat OutputImage2;
		cv::inRange(frame, cv::Scalar(120, 10, 10), cv::Scalar(255, 40, 40), OutputImage2);

		// GREEN
		cv::Mat OutputImage3;
		cv::inRange(frame, cv::Scalar(10, 120, 10), cv::Scalar(40, 255, 40), OutputImage3);


		int x1, x2, x3;
		x1 = cv::countNonZero(OutputImage);
		x2 = cv::countNonZero(OutputImage2);
		x3 = cv::countNonZero(OutputImage3);

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
			std::cout << "Vermelho ";
			framesVermelhos = 0;
			framesAzuis = 0;
			framesVerdes = 0;
		}

		if (framesAzuis >= FRAMES_MINIMOS_PARA_VALIDACAO)
		{
			std::cout << "Azul ";
			framesVermelhos = 0;
			framesAzuis = 0;
			framesVerdes = 0;
		}

		if (framesVerdes >= FRAMES_MINIMOS_PARA_VALIDACAO)
		{
			std::cout << "Verde ";
			framesVermelhos = 0;
			framesAzuis = 0;
			framesVerdes = 0;
		}

		if (cv::waitKey(1000 / 1000) >= 0) // Delay + Pressiona um botão pra sair
		{
			break;
		}
	}
	cv::waitKey(0);
}
