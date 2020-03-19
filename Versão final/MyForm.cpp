/* Canto Superior Direito -> Solution Explorer -> Seu Projeto -> Properties -> Linker -> Advanced -> Entry Point -> Colocar "main"

Ainda No Linker -> System -> Windows(/SUBSYSTEM:WINDOWS) */

#include "MyForm.h"
#include <iostream>
#include <opencv2/opencv.hpp>
#include <stdint.h>
#include <opencv2/objdetect.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/core/core.hpp>


using namespace System;
using namespace System::Windows::Forms;

const int FPS = 1000; // Altera o delay de waitKey(1000 / FPS)
/* Nota:  Quanto maior a constante FPS for,
menor é o delay na equação "waitkey(1000 / FPS)" */

bool ativarWebCam() {
	cv::VideoCapture webCam(0);
	cv::Mat frame;

	const int FRAMES_MINIMOS_PARA_VALIDACAO = 50;

	int framesVermelhos, framesVerdes, framesAzuis;
	framesVermelhos = framesVerdes = framesAzuis = 0;


	if (!webCam.isOpened()) // Caso falhe em iniciar webam
	{
		usuario = "Usuario invalido";
		return 1;
	}

	while (webCam.read(frame)) // webCam >> frame
	{
		cv::imshow("WebCam", frame); // Mostra o frame lido do webcam

		// BGR COLOR
		// RED
		cv::Mat OutputImage;
		cv::inRange(frame, cv::Scalar(10, 10, 100), cv::Scalar(50, 50, 255), OutputImage);

		// BLUE
		cv::Mat OutputImage2;
		cv::inRange(frame, cv::Scalar(100, 10, 10), cv::Scalar(255, 50, 50), OutputImage2);

		// GREEN
		cv::Mat OutputImage3;
		cv::inRange(frame, cv::Scalar(10, 100, 10), cv::Scalar(50, 255, 50), OutputImage3);


		int x1, x2, x3;
		x1 = cv::countNonZero(OutputImage);
		x2 = cv::countNonZero(OutputImage2);
		x3 = cv::countNonZero(OutputImage3);

		if (x1 > x2&& x1 > x3)
		{
			framesVermelhos++;
			framesAzuis = 0;
			framesVerdes = 0;
		}
		else if (x2 > x1&& x2 > x3)
		{
			framesAzuis++;
			framesVermelhos = 0;
			framesVerdes = 0;
		}
		else if (x3 > x1&& x3 > x2)
		{
			framesVerdes++;
			framesVermelhos = 0;
			framesAzuis = 0;
		}

		if (framesVermelhos >= FRAMES_MINIMOS_PARA_VALIDACAO)
		{
			framesVermelhos = 0;
			framesAzuis = 0;
			framesVerdes = 0;
			usuario = "Vermelho";
			break;
		}

		if (framesAzuis >= FRAMES_MINIMOS_PARA_VALIDACAO)
		{
			framesVermelhos = 0;
			framesAzuis = 0;
			framesVerdes = 0;
			usuario = "Azul";
			break;
		}

		if (framesVerdes >= FRAMES_MINIMOS_PARA_VALIDACAO)
		{
			framesVermelhos = 0;
			framesAzuis = 0;
			framesVerdes = 0;
			usuario = "Verde";
			break;
		}

		if (cv::waitKey(1000 / 1000) >= 0) // Delay + Pressiona um botão pra sair
		{
			usuario = "Usuario invalido";
			break;
		}

	}

	cv::imshow("WebCam", cv::imread("imagens/vazio.jpg") );
}

void startFront() {

	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	//NOME DO SEU PROJETO::NOME DO SEU FORM form;
	Project1::MyForm form;

	Application::Run(% form);
}

[STAThread] // Pode Ser int main Ou void main
int main(array<String^>^ arg) {
	ativarWebCam();

	if(usuario != "Usuario invalido")
		startFront();

	return 0;
}