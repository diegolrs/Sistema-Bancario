#pragma once

#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/objdetect.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp> 
#include <stdint.h>
#include <string>
#include <msclr/marshal_cppstd.h>
#include <fstream>
#include <locale>         // std::locale, std::isalpha

std::string usuario;
std::string extensaoPadraoArquivo = ".txt";
std::string boasVindas = "Bem-vindo(a) Sr(a) ";

namespace Project1 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;



	/// <summary>
	/// Sumário para MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			// Lendo do arquivo ------------------------------
			std::ifstream myfile(usuario + extensaoPadraoArquivo);
			if (myfile.is_open())
			{
				std::string arquivoeEntrada;
				getline(myfile, arquivoeEntrada);
				myfile.close();
				// Convertendo de std::string para system::string
				String^ entradaConvertida = gcnew String(arquivoeEntrada.c_str());
				label_valorAtual->Text = entradaConvertida; // inicia com o valor do arquivo
			}
			else {
				std::ofstream arquivoSaida(usuario + extensaoPadraoArquivo);
				arquivoSaida << "0";
				arquivoSaida.close();
				label_valorAtual->Text = "0"; // inicia com o valor do arquivo
			}
			
			if(usuario == "Verde")
				label_log->ForeColor = System::Drawing::Color::Green;
			if(usuario == "Vermelho")
				label_log->ForeColor = System::Drawing::Color::Red;
			if(usuario == "Azul")
				label_log->ForeColor = System::Drawing::Color::Blue;

			String^ usuarioEmSystemSTD = gcnew String((boasVindas + usuario).c_str());

			label_log->Text = usuarioEmSystemSTD; // inicia nulo
			
			//
			//TODO: Adicione o código do construtor aqui
			//
		}

	protected:
		/// <summary>
		/// Limpar os recursos que estão sendo usados.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label_titulo;
	private: System::Windows::Forms::Label^ label_valorAtual;
	private: System::Windows::Forms::Button^ button_Depositar;
	protected:



	private: System::Windows::Forms::TextBox^ textBox_entrada;


	private: System::Windows::Forms::Label^ label_log;

	private: System::Windows::Forms::Label^ label_saldo;


	private: System::Windows::Forms::Button^ button_enviarArquivo;
	private: System::Windows::Forms::Button^ button_Sacar;
	private: System::Windows::Forms::Button^ button_sairSemSalvar;
	private: System::Windows::Forms::Button^ button_salvarESair;

	protected:

	private:
		/// <summary>
		/// Variável de designer necessária.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necessário para suporte ao Designer - não modifique 
		/// o conteúdo deste método com o editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->label_titulo = (gcnew System::Windows::Forms::Label());
			this->label_valorAtual = (gcnew System::Windows::Forms::Label());
			this->button_Depositar = (gcnew System::Windows::Forms::Button());
			this->textBox_entrada = (gcnew System::Windows::Forms::TextBox());
			this->label_log = (gcnew System::Windows::Forms::Label());
			this->label_saldo = (gcnew System::Windows::Forms::Label());
			this->button_enviarArquivo = (gcnew System::Windows::Forms::Button());
			this->button_Sacar = (gcnew System::Windows::Forms::Button());
			this->button_sairSemSalvar = (gcnew System::Windows::Forms::Button());
			this->button_salvarESair = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// label_titulo
			// 
			this->label_titulo->AutoSize = true;
			this->label_titulo->BackColor = System::Drawing::Color::Transparent;
			this->label_titulo->Font = (gcnew System::Drawing::Font(L"Roboto Medium", 25, System::Drawing::FontStyle::Bold));
			this->label_titulo->ForeColor = System::Drawing::SystemColors::Window;
			this->label_titulo->Location = System::Drawing::Point(305, 42);
			this->label_titulo->Name = L"label_titulo";
			this->label_titulo->Size = System::Drawing::Size(301, 41);
			this->label_titulo->TabIndex = 0;
			this->label_titulo->Text = L"Sistema Bancário";
			// 
			// label_valorAtual
			// 
			this->label_valorAtual->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->label_valorAtual->AutoSize = true;
			this->label_valorAtual->BackColor = System::Drawing::Color::Transparent;
			this->label_valorAtual->Font = (gcnew System::Drawing::Font(L"Roboto Medium", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label_valorAtual->ForeColor = System::Drawing::SystemColors::Window;
			this->label_valorAtual->Location = System::Drawing::Point(441, 138);
			this->label_valorAtual->Name = L"label_valorAtual";
			this->label_valorAtual->Size = System::Drawing::Size(139, 29);
			this->label_valorAtual->TabIndex = 1;
			this->label_valorAtual->Text = L"Valor atual";
			this->label_valorAtual->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// button_Depositar
			// 
			this->button_Depositar->BackColor = System::Drawing::Color::Transparent;
			this->button_Depositar->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button_Depositar.BackgroundImage")));
			this->button_Depositar->FlatAppearance->BorderSize = 0;
			this->button_Depositar->FlatAppearance->MouseDownBackColor = System::Drawing::Color::DarkMagenta;
			this->button_Depositar->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Purple;
			this->button_Depositar->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button_Depositar->Font = (gcnew System::Drawing::Font(L"Roboto Medium", 10, System::Drawing::FontStyle::Bold));
			this->button_Depositar->ForeColor = System::Drawing::SystemColors::Window;
			this->button_Depositar->Location = System::Drawing::Point(308, 266);
			this->button_Depositar->Name = L"button_Depositar";
			this->button_Depositar->Size = System::Drawing::Size(141, 41);
			this->button_Depositar->TabIndex = 2;
			this->button_Depositar->Text = L"Depositar";
			this->button_Depositar->UseVisualStyleBackColor = false;
			this->button_Depositar->Click += gcnew System::EventHandler(this, &MyForm::button_Depositar_Click);
			// 
			// textBox_entrada
			// 
			this->textBox_entrada->Font = (gcnew System::Drawing::Font(L"Roboto Medium", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox_entrada->Location = System::Drawing::Point(306, 208);
			this->textBox_entrada->Name = L"textBox_entrada";
			this->textBox_entrada->Size = System::Drawing::Size(300, 27);
			this->textBox_entrada->TabIndex = 3;
			// 
			// label_log
			// 
			this->label_log->BackColor = System::Drawing::Color::Black;
			this->label_log->Font = (gcnew System::Drawing::Font(L"Roboto Medium", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label_log->ForeColor = System::Drawing::Color::DarkMagenta;
			this->label_log->Location = System::Drawing::Point(202, 356);
			this->label_log->Name = L"label_log";
			this->label_log->Size = System::Drawing::Size(490, 33);
			this->label_log->TabIndex = 6;
			this->label_log->Text = L"Logs";
			this->label_log->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label_saldo
			// 
			this->label_saldo->AutoSize = true;
			this->label_saldo->BackColor = System::Drawing::Color::Transparent;
			this->label_saldo->Font = (gcnew System::Drawing::Font(L"Roboto Medium", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label_saldo->ForeColor = System::Drawing::SystemColors::Window;
			this->label_saldo->Location = System::Drawing::Point(321, 138);
			this->label_saldo->Name = L"label_saldo";
			this->label_saldo->Size = System::Drawing::Size(124, 29);
			this->label_saldo->TabIndex = 7;
			this->label_saldo->Text = L"Saldo: R$";
			// 
			// button_enviarArquivo
			// 
			this->button_enviarArquivo->BackColor = System::Drawing::Color::Transparent;
			this->button_enviarArquivo->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button_enviarArquivo.BackgroundImage")));
			this->button_enviarArquivo->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->button_enviarArquivo->Cursor = System::Windows::Forms::Cursors::NoMove2D;
			this->button_enviarArquivo->FlatAppearance->BorderColor = System::Drawing::Color::White;
			this->button_enviarArquivo->FlatAppearance->BorderSize = 0;
			this->button_enviarArquivo->FlatAppearance->MouseDownBackColor = System::Drawing::Color::MidnightBlue;
			this->button_enviarArquivo->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Indigo;
			this->button_enviarArquivo->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button_enviarArquivo->Font = (gcnew System::Drawing::Font(L"Roboto Medium", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button_enviarArquivo->ForeColor = System::Drawing::SystemColors::Window;
			this->button_enviarArquivo->Location = System::Drawing::Point(1, 281);
			this->button_enviarArquivo->Name = L"button_enviarArquivo";
			this->button_enviarArquivo->Size = System::Drawing::Size(199, 55);
			this->button_enviarArquivo->TabIndex = 10;
			this->button_enviarArquivo->Text = L"Salvar alterações";
			this->button_enviarArquivo->UseVisualStyleBackColor = false;
			this->button_enviarArquivo->Click += gcnew System::EventHandler(this, &MyForm::button_enviarArquivo_Click);
			// 
			// button_Sacar
			// 
			this->button_Sacar->AutoEllipsis = true;
			this->button_Sacar->BackColor = System::Drawing::Color::Transparent;
			this->button_Sacar->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button_Sacar.BackgroundImage")));
			this->button_Sacar->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->button_Sacar->FlatAppearance->BorderSize = 0;
			this->button_Sacar->FlatAppearance->MouseDownBackColor = System::Drawing::Color::DarkMagenta;
			this->button_Sacar->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Purple;
			this->button_Sacar->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button_Sacar->Font = (gcnew System::Drawing::Font(L"Roboto Medium", 10, System::Drawing::FontStyle::Bold));
			this->button_Sacar->ForeColor = System::Drawing::SystemColors::Window;
			this->button_Sacar->Location = System::Drawing::Point(456, 266);
			this->button_Sacar->Name = L"button_Sacar";
			this->button_Sacar->Size = System::Drawing::Size(150, 41);
			this->button_Sacar->TabIndex = 4;
			this->button_Sacar->Text = L"Sacar";
			this->button_Sacar->UseVisualStyleBackColor = false;
			this->button_Sacar->Click += gcnew System::EventHandler(this, &MyForm::button_Sacar_Click);
			// 
			// button_sairSemSalvar
			// 
			this->button_sairSemSalvar->BackColor = System::Drawing::Color::Transparent;
			this->button_sairSemSalvar->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button_sairSemSalvar.BackgroundImage")));
			this->button_sairSemSalvar->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->button_sairSemSalvar->Cursor = System::Windows::Forms::Cursors::NoMove2D;
			this->button_sairSemSalvar->FlatAppearance->BorderColor = System::Drawing::Color::White;
			this->button_sairSemSalvar->FlatAppearance->BorderSize = 0;
			this->button_sairSemSalvar->FlatAppearance->MouseDownBackColor = System::Drawing::Color::MidnightBlue;
			this->button_sairSemSalvar->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Indigo;
			this->button_sairSemSalvar->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button_sairSemSalvar->Font = (gcnew System::Drawing::Font(L"Roboto Medium", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button_sairSemSalvar->ForeColor = System::Drawing::SystemColors::Window;
			this->button_sairSemSalvar->Location = System::Drawing::Point(1, 227);
			this->button_sairSemSalvar->Name = L"button_sairSemSalvar";
			this->button_sairSemSalvar->Size = System::Drawing::Size(199, 55);
			this->button_sairSemSalvar->TabIndex = 11;
			this->button_sairSemSalvar->Text = L"Sair sem salvar";
			this->button_sairSemSalvar->UseVisualStyleBackColor = false;
			this->button_sairSemSalvar->Click += gcnew System::EventHandler(this, &MyForm::button_sairSemSalvar_Click);
			// 
			// button_salvarESair
			// 
			this->button_salvarESair->BackColor = System::Drawing::Color::Transparent;
			this->button_salvarESair->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button_salvarESair.BackgroundImage")));
			this->button_salvarESair->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->button_salvarESair->Cursor = System::Windows::Forms::Cursors::NoMove2D;
			this->button_salvarESair->FlatAppearance->BorderColor = System::Drawing::Color::White;
			this->button_salvarESair->FlatAppearance->BorderSize = 0;
			this->button_salvarESair->FlatAppearance->MouseDownBackColor = System::Drawing::Color::MidnightBlue;
			this->button_salvarESair->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Indigo;
			this->button_salvarESair->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button_salvarESair->Font = (gcnew System::Drawing::Font(L"Roboto Medium", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button_salvarESair->ForeColor = System::Drawing::SystemColors::Window;
			this->button_salvarESair->Location = System::Drawing::Point(1, 335);
			this->button_salvarESair->Name = L"button_salvarESair";
			this->button_salvarESair->Size = System::Drawing::Size(199, 55);
			this->button_salvarESair->TabIndex = 12;
			this->button_salvarESair->Text = L"Salvar e sair";
			this->button_salvarESair->UseVisualStyleBackColor = false;
			this->button_salvarESair->Click += gcnew System::EventHandler(this, &MyForm::button_salvarESair_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(7, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ControlDarkDark;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->ClientSize = System::Drawing::Size(690, 390);
			this->Controls->Add(this->button_salvarESair);
			this->Controls->Add(this->button_sairSemSalvar);
			this->Controls->Add(this->button_enviarArquivo);
			this->Controls->Add(this->label_saldo);
			this->Controls->Add(this->label_log);
			this->Controls->Add(this->button_Sacar);
			this->Controls->Add(this->textBox_entrada);
			this->Controls->Add(this->button_Depositar);
			this->Controls->Add(this->label_valorAtual);
			this->Controls->Add(this->label_titulo);
			this->Cursor = System::Windows::Forms::Cursors::PanNW;
			this->Font = (gcnew System::Drawing::Font(L"Roboto Medium", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MaximizeBox = false;
			this->MaximumSize = System::Drawing::Size(690, 390);
			this->MinimumSize = System::Drawing::Size(690, 390);
			this->Name = L"MyForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Sistema Bancário LP1";
			this->TransparencyKey = System::Drawing::Color::WhiteSmoke;
			this->ResumeLayout(false);
			this->PerformLayout();

		}

	// Ao clicar em Depositar
	#pragma endregion
	private: System::Void button_Depositar_Click(System::Object^ sender, System::EventArgs^ e) {
		label_log->ForeColor = System::Drawing::Color::DarkMagenta;
		String^ valorAtualString = label_valorAtual->Text; // Pegando texto de label_valorAtual

	// Tratando os valores da TextBox ---------------------------------
		bool chamouExceptionDeErro = 0; // Valor não é válido
		msclr::interop::marshal_context context;
		std::string valorAtualStdString = context.marshal_as<std::string>(textBox_entrada->Text);

		// String nula
		if (valorAtualStdString == "") {
			label_log->Text = "Erro! Valor vazio!";
			valorAtualStdString = "0";
			chamouExceptionDeErro = 1;
		}
		else {
			for (int i = 0; i < valorAtualStdString.size(); i++)
			{
				// Trocar ponto pot vírgula
				if (valorAtualStdString[i] == '.') {
					valorAtualStdString[i] = ',';
				}
			}
		}

		std::locale loc;

		if (!chamouExceptionDeErro) {
			for (int i = 0; i < valorAtualStdString.size(); i++)
			{
				if (std::isalpha(valorAtualStdString[i], loc)) {
					valorAtualStdString = "0";
					label_log->Text = "Insira apenas números!";
					chamouExceptionDeErro = 1;
				}
			}
		

			// --------------------------------------------------------------------

			double valorAtualDouble = System::Convert::ToDouble(valorAtualString); // Convertendo a string em double
			String^ valorTextBoxString = gcnew String(valorAtualStdString.c_str()); // Pegando texto de string::std
			double valorTextBoxDouble = System::Convert::ToDouble(valorTextBoxString); // Convertendo a string em double

			valorAtualDouble += valorTextBoxDouble; // Soma o valor atual com o valor da TextBox

			int valorAtualInt = valorAtualDouble;
			double diferenca = valorAtualDouble - valorAtualInt;

			if (diferenca < 0)
				diferenca *= -1;

			int cont = 1;
			if (diferenca != 0)
				while (diferenca < 1000) {
					diferenca *= 10;
					cont *= 10;
				}

			int decimais = diferenca;

			double saidaFinal = (1.0) * valorAtualInt + ((1.0) * decimais / cont);

			valorAtualString = System::Convert::ToString(saidaFinal); // Convertendo double em string	

			// Não há casas decimais
			if (decimais == 0)
				valorAtualString += ",0000";
			else
			{
				/* É necessário para menor perda de dados
				 * na conversão pra string!
				*/
					// Número tem três zeros no final
						if (decimais % 100000 == 0) {
						valorAtualString += "000";
						}
						else {
							// Número tem dois zeros no final
							if (decimais % 10000 == 0) {
								valorAtualString += "00";
							}
							else {
								// Número tem um zero no final
								if (decimais % 1000 == 0) {
									valorAtualString += "0";
								}

							}
						}
			}
		}

		if (!chamouExceptionDeErro) {
			label_valorAtual->Text = valorAtualString; // Seta resultado no valor atual
			label_log->Text = "Depósito efetuado com sucesso!";
		}
			
	}


	private: System::Void button_Sacar_Click(System::Object^ sender, System::EventArgs^ e) {
		label_log->ForeColor = System::Drawing::Color::DarkMagenta;
		String^ valorAtualString = label_valorAtual->Text; // Pegando texto de label_valorAtual
		// tirei coversor double daqui

		// Tratando os valores da TextBox ---------------------------------
		bool chamouExceptionDeErro = 0; // Valor não é válido
		msclr::interop::marshal_context context;
		std::string valorAtualStdString = context.marshal_as<std::string>(textBox_entrada->Text);

		// String nula
		if (valorAtualStdString == "") {
			label_log->Text = "Erro! Valor vazio!";
			valorAtualStdString = "0";
			chamouExceptionDeErro = 1;
		}
		else {
			for (int i = 0; i < valorAtualStdString.size(); i++)
			{
				// Trocar ponto pot vírgula
				if (valorAtualStdString[i] == '.') {
					valorAtualStdString[i] = ',';
				}
			}
		}

		std::locale loc;

		if (!chamouExceptionDeErro) {
			for (int i = 0; i < valorAtualStdString.size(); i++)
			{
				if (std::isalpha(valorAtualStdString[i], loc)) {
					valorAtualStdString = "0";
					label_log->Text = "Insira apenas números!";
					chamouExceptionDeErro = 1;
				}
			}

			// --------------------------------------------------------------------

			double valorAtualDouble = System::Convert::ToDouble(valorAtualString); // Convertendo a string em double
			String^ valorTextBoxString = gcnew String(valorAtualStdString.c_str());  // Pegando texto de string::std
			double valorTextBoxDouble = System::Convert::ToDouble(valorTextBoxString); // Convertendo a string em double
			valorAtualDouble -= valorTextBoxDouble; // Subtraui o valor atual com o valor da TextBox



			if (valorAtualDouble < 0)
				valorAtualDouble = 0;

			int valorAtualInt = valorAtualDouble;
			double diferenca = valorAtualDouble - valorAtualInt;

			if (diferenca != 0)
				while (diferenca < 10)
					diferenca *= 10;

			int decimais = diferenca;

			double saidaFinal = (1.0) * valorAtualInt + ((1.0) * decimais / 100);

			valorAtualString = System::Convert::ToString(saidaFinal); // Convertendo double em string	

			// Não há casas decimais
			if (decimais == 0)
				valorAtualString += ",00";
			else
			{
				switch (decimais) {
				case 10: case 20: case 30: case 40:
				case 50: case 60: case 70: case 80:
				case 90:
					valorAtualString += "0";
					break;
				}
			}

		}

		if (!chamouExceptionDeErro) {
			valorAtualStdString = context.marshal_as<std::string>(valorAtualString);

			label_valorAtual->Text = valorAtualString; // Seta resultado no valor atual
			label_log->Text = "Saque efetuado com sucesso!";
		}
	}

	private: System::Void button_OpenCv_WebCam_Click(System::Object^ sender, System::EventArgs^ e) {

		//ativarWebCam(); // Funcao ativar webCam

	}
	   
	private: System::Void button_enviarArquivo_Click(System::Object^ sender, System::EventArgs^ e) {
		label_log->ForeColor = System::Drawing::Color::DarkMagenta;
		// Convertendo de system::string para std::string
		msclr::interop::marshal_context context;
		std::string valorAtualStdString = context.marshal_as<std::string>(label_valorAtual->Text);
		std::ofstream arquivoSaida(usuario + extensaoPadraoArquivo);
		arquivoSaida << valorAtualStdString;
		arquivoSaida.close();
		label_log->Text = "As operações foram salvas!";
	}


	private: System::Void button_sairSemSalvar_Click(System::Object^ sender, System::EventArgs^ e) {
		label_log->ForeColor = System::Drawing::Color::DarkMagenta;
		this->Close();
	}

	void converte() {
			   msclr::interop::marshal_context context;
			   std::string valorAtualStdString = context.marshal_as<std::string>(label_valorAtual->Text);
	}

	private: System::Void button_salvarESair_Click(System::Object^ sender, System::EventArgs^ e) {
		label_log->ForeColor = System::Drawing::Color::DarkMagenta;
		// Convertendo de system::string para std::string
		msclr::interop::marshal_context context;
		std::string valorAtualStdString = context.marshal_as<std::string>(label_valorAtual->Text);
		std::ofstream arquivoSaida(usuario + extensaoPadraoArquivo);
		arquivoSaida << valorAtualStdString;
		arquivoSaida.close();
		label_log->Text = "As operações foram salvas!";

		this->Close();
	}
	};
}