#pragma once
#include "ArrGame.h"
namespace QueensGame {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	private:
		ArrGame* objGame;
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			objGame = new ArrGame();
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Timer^ timer1;
	private: System::Windows::Forms::Button^ buttonJuegaPC;
	private: System::Windows::Forms::Button^ buttonBack;

	protected:
	private: System::ComponentModel::IContainer^ components;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->buttonJuegaPC = (gcnew System::Windows::Forms::Button());
			this->buttonBack = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Tick += gcnew System::EventHandler(this, &MyForm::timer1_Tick);
			// 
			// buttonJuegaPC
			// 
			this->buttonJuegaPC->Location = System::Drawing::Point(490, 278);
			this->buttonJuegaPC->Margin = System::Windows::Forms::Padding(2);
			this->buttonJuegaPC->Name = L"buttonJuegaPC";
			this->buttonJuegaPC->Size = System::Drawing::Size(117, 28);
			this->buttonJuegaPC->TabIndex = 0;
			this->buttonJuegaPC->Text = L"Computer Plays";
			this->buttonJuegaPC->UseVisualStyleBackColor = true;
			this->buttonJuegaPC->Click += gcnew System::EventHandler(this, &MyForm::buttonJuegaPC_Click);
			// 
			// buttonBack
			// 
			this->buttonBack->Location = System::Drawing::Point(506, 327);
			this->buttonBack->Margin = System::Windows::Forms::Padding(2);
			this->buttonBack->Name = L"buttonBack";
			this->buttonBack->Size = System::Drawing::Size(86, 37);
			this->buttonBack->TabIndex = 1;
			this->buttonBack->Text = L"Back";
			this->buttonBack->UseVisualStyleBackColor = true;
			this->buttonBack->Click += gcnew System::EventHandler(this, &MyForm::buttonBack_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(639, 506);
			this->Controls->Add(this->buttonBack);
			this->Controls->Add(this->buttonJuegaPC);
			this->Margin = System::Windows::Forms::Padding(2);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::MyForm_MouseClick);
			this->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::MyForm_MouseMove);
			this->ResumeLayout(false);

		}
#pragma endregion
		int x;
		int y;
	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {
		this->Text = L"8 Queens" + "  X = " + x + "   Y = " + y + "   " + objGame->The_time(); //280 tips = 30 seg *close
		Graphics^ g = this->CreateGraphics();
		BufferedGraphicsContext^ espaceBuffer = BufferedGraphicsManager::Current;
		BufferedGraphics^ buffer = espaceBuffer->Allocate(g, this->ClientRectangle);
		buffer->Graphics->Clear(Color::WhiteSmoke);
		objGame->DrawTable(buffer->Graphics);
		objGame->Draw(buffer->Graphics);
		objGame->Check(0);
		if (objGame->The_time() == 280)
		{
			objGame->Com_PutQueen();
		}
		if (objGame->The_turn() == 1 && objGame->End() != 1)
		{
			objGame->Com_PutQueen();
		}
		if (objGame->End() == 1)
		{
			timer1->Enabled = false;
			MessageBox::Show("The Game Ended");
			if (objGame->Hu_points() > objGame->Com_points())
			{
				MessageBox::Show("You human, won.");
			}
			else if (objGame->Hu_points() == objGame->Com_points())
			{
				MessageBox::Show("A draw!");
			}
			else if (objGame->Hu_points() < objGame->Com_points())
			{
				MessageBox::Show("You lose.");
			}
		}
		buffer->Render(g);
		delete buffer;
		delete espaceBuffer;
		delete g;
	}
	private: System::Void MyForm_MouseMove(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		x = e->X;
		y = e->Y;
	}
	private: System::Void MyForm_MouseClick(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		if (x > 16 && x < 71 && y > 17 && y < 77) //row 1 //55x 
		{
			if (objGame->Huma_PutQueen(0, 0) == false)//19,23
			{
				MessageBox::Show("You lose 5 points.");
			}
		}
		else if (x > 71 && x < 124 && y > 17 && y < 77)//53x
		{
			if (objGame->Huma_PutQueen(1, 0) == false)
			{
				MessageBox::Show("You lose 5 points.");
			}
		}
		else if (x > 124 && x < 178 && y > 17 && y < 77)//54x
		{
			if (objGame->Huma_PutQueen(2, 0) == false)
			{
				MessageBox::Show("You lose 5 points.");
			}
		}
		else if (x > 178 && x < 231 && y > 17 && y < 77)//53x
		{
			if (objGame->Huma_PutQueen(3, 0) == false)
			{
				MessageBox::Show("You lose 5 points.");
			}
		}
		else if (x > 231 && x < 286 && y > 17 && y < 77)//55x
		{
			if (objGame->Huma_PutQueen(4, 0) == false)
			{
				MessageBox::Show("You lose 5 points.");
			}
		}
		else if (x > 286 && x < 340 && y > 17 && y < 77)//54x
		{
			if (objGame->Huma_PutQueen(5, 0) == false)
			{
				MessageBox::Show("You lose 5 points.");
			}
		}
		else if (x > 340 && x < 394 && y > 17 && y < 77)//54x
		{
			if (objGame->Huma_PutQueen(6, 0) == false)
			{
				MessageBox::Show("You lose 5 points.");
			}
		}
		else if (x > 394 && x < 449 && y > 17 && y < 77)//55x 
		{
			if (objGame->Huma_PutQueen(7, 0) == false)
			{
				MessageBox::Show("You lose 5 points.");
			}
		}
		else if (x > 16 && x < 71 && y > 77 && y < 135) //fila 2
		{
			if (objGame->Huma_PutQueen(0, 1) == false)
			{
				MessageBox::Show("You lose 5 points.");
			}
		}
		else if (x > 71 && x < 124 && y > 77 && y < 135)
		{
			if (objGame->Huma_PutQueen(1, 1) == false)
			{
				MessageBox::Show("You lose 5 points.");
			}
		}
		else if (x > 124 && x < 178 && y > 77 && y < 135)
		{
			if (objGame->Huma_PutQueen(2, 1) == false)
			{
				MessageBox::Show("You lose 5 points.");
			}
		}
		else if (x > 178 && x < 231 && y > 77 && y < 135)
		{
			if (objGame->Huma_PutQueen(3, 1) == false)
			{
				MessageBox::Show("You lose 5 points.");
			}
		}
		else if (x > 231 && x < 286 && y > 77 && y < 135)
		{
			if (objGame->Huma_PutQueen(4, 1) == false)
			{
				MessageBox::Show("You lose 5 points.");
			}
		}
		else if (x > 286 && x < 340 && y > 77 && y < 135)
		{
			if (objGame->Huma_PutQueen(5, 1) == false)
			{
				MessageBox::Show("You lose 5 points.");
			}
		}
		else if (x > 340 && x < 394 && y > 77 && y < 135)
		{
			if (objGame->Huma_PutQueen(6, 1) == false)
			{
				MessageBox::Show("You lose 5 points.");
			}
		}
		else if (x > 394 && x < 449 && y > 77 && y < 135)
		{
			if (objGame->Huma_PutQueen(7, 1) == false)
			{
				MessageBox::Show("You lose 5 points.");
			}
		}
		else if (x > 16 && x < 71 && y > 135 && y < 193) //fila 3
		{
			if (objGame->Huma_PutQueen(0, 2) == false)
			{
				MessageBox::Show("You lose 5 points.");
			}
		}
		else if (x > 71 && x < 124 && y > 135 && y < 193)
		{
			if (objGame->Huma_PutQueen(1, 2) == false)
			{
				MessageBox::Show("You lose 5 points.");
			}
		}
		else if (x > 124 && x < 178 && y > 135 && y < 193)
		{
			if (objGame->Huma_PutQueen(2, 2) == false)
			{
				MessageBox::Show("You lose 5 points.");
			}
		}
		else if (x > 178 && x < 231 && y > 135 && y < 193)
		{
			if (objGame->Huma_PutQueen(3, 2) == false)
			{
				MessageBox::Show("You lose 5 points.");
			}
		}
		else if (x > 231 && x < 286 && y > 135 && y < 193)
		{
			if (objGame->Huma_PutQueen(4, 2) == false)
			{
				MessageBox::Show("You lose 5 points.");
			}
		}
		else if (x > 286 && x < 340 && y > 135 && y < 193)
		{
			if (objGame->Huma_PutQueen(5, 2) == false)
			{
				MessageBox::Show("You lose 5 points.");
			}
		}
		else if (x > 340 && x < 394 && y > 135 && y < 193)
		{
			if (objGame->Huma_PutQueen(6, 2) == false)
			{
				MessageBox::Show("You lose 5 points.");
			}
		}
		else if (x > 394 && x < 449 && y > 135 && y < 193)
		{
			if (objGame->Huma_PutQueen(7, 2) == false)
			{
				MessageBox::Show("You lose 5 points.");
			}
		}
		else if (x > 16 && x < 71 && y > 193 && y < 253)//fila 4
		{
			if (objGame->Huma_PutQueen(0, 3) == false)
			{
				MessageBox::Show("You lose 5 points.");
			}
		}
		else if (x > 71 && x < 124 && y > 193 && y < 253)
		{
			if (objGame->Huma_PutQueen(1, 3) == false)
			{
				MessageBox::Show("You lose 5 points.");
			}
		}
		else if (x > 124 && x < 178 && y > 193 && y < 253)
		{
			if (objGame->Huma_PutQueen(2, 3) == false)
			{
				MessageBox::Show("You lose 5 points.");
			}
		}
		else if (x > 178 && x < 231 && y > 193 && y < 253)
		{
			if (objGame->Huma_PutQueen(3, 3) == false)
			{
				MessageBox::Show("You lose 5 points.");
			}
		}
		else if (x > 231 && x < 286 && y > 193 && y < 253)
		{
			if (objGame->Huma_PutQueen(4, 3) == false)
			{
				MessageBox::Show("You lose 5 points.");
			}
		}
		else if (x > 286 && x < 340 && y > 193 && y < 253)
		{
			if (objGame->Huma_PutQueen(5, 3) == false)
			{
				MessageBox::Show("You lose 5 points.");
			}
		}
		else if (x > 340 && x < 394 && y > 193 && y < 253)
		{
			if (objGame->Huma_PutQueen(6, 3) == false)
			{
				MessageBox::Show("You lose 5 points.");
			}
		}
		else if (x > 394 && x < 449 && y > 193 && y < 253)
		{
			if (objGame->Huma_PutQueen(7, 3) == false)
			{
				MessageBox::Show("You lose 5 points.");
			}
		}
		else if (x > 16 && x < 71 && y > 253 && y < 309)//fila 5
		{
			if (objGame->Huma_PutQueen(0, 4) == false)
			{
				MessageBox::Show("You lose 5 points.");
			}
		}
		else if (x > 71 && x < 124 && y > 253 && y < 309)
		{
			if (objGame->Huma_PutQueen(1, 4) == false)
			{
				MessageBox::Show("You lose 5 points.");
			}
		}
		else if (x > 124 && x < 178 && y > 253 && y < 309)
		{
			if (objGame->Huma_PutQueen(2, 4) == false)
			{
				MessageBox::Show("You lose 5 points.");
			}
		}
		else if (x > 178 && x < 231 && y > 253 && y < 309)
		{
			if (objGame->Huma_PutQueen(3, 4) == false)
			{
				MessageBox::Show("You lose 5 points.");
			}
		}
		else if (x > 231 && x < 286 && y > 253 && y < 309)
		{
			if (objGame->Huma_PutQueen(4, 4) == false)
			{
				MessageBox::Show("You lose 5 points.");
			}
		}
		else if (x > 286 && x < 340 && y > 253 && y < 309)
		{
			if (objGame->Huma_PutQueen(5, 4) == false)
			{
				MessageBox::Show("You lose 5 points.");
			}
		}
		else if (x > 340 && x < 394 && y > 253 && y < 309)
		{
			if (objGame->Huma_PutQueen(6, 4) == false)
			{
				MessageBox::Show("You lose 5 points.");
			}
		}
		else if (x > 394 && x < 449 && y > 253 && y < 309)
		{
			if (objGame->Huma_PutQueen(7, 4) == false)
			{
				MessageBox::Show("You lose 5 points.");
			}
		}
		else if (x > 16 && x < 71 && y > 309 && y < 369)//fila 6
		{
			if (objGame->Huma_PutQueen(0, 5) == false)
			{
				MessageBox::Show("You lose 5 points.");
			}
		}
		else if (x > 71 && x < 124 && y > 309 && y < 369)
		{
			if (objGame->Huma_PutQueen(1, 5) == false)
			{
				MessageBox::Show("You lose 5 points.");
			}
		}
		else if (x > 124 && x < 178 && y > 309 && y < 369)
		{
			if (objGame->Huma_PutQueen(2, 5) == false)
			{
				MessageBox::Show("You lose 5 points.");
			}
		}
		else if (x > 178 && x < 231 && y > 309 && y < 369)
		{
			if (objGame->Huma_PutQueen(3, 5) == false)
			{
				MessageBox::Show("You lose 5 points.");
			}
		}
		else if (x > 231 && x < 286 && y > 309 && y < 369)
		{
			if (objGame->Huma_PutQueen(4, 5) == false)
			{
				MessageBox::Show("You lose 5 points.");
			}
		}
		else if (x > 286 && x < 340 && y > 309 && y < 369)
		{
			if (objGame->Huma_PutQueen(5, 5) == false)
			{
				MessageBox::Show("You lose 5 points.");
			}
		}
		else if (x > 340 && x < 394 && y > 309 && y < 369)
		{
			if (objGame->Huma_PutQueen(6, 5) == false)
			{
				MessageBox::Show("You lose 5 points.");
			}
		}
		else if (x > 394 && x < 449 && y > 309 && y < 369)
		{
			if (objGame->Huma_PutQueen(7, 5) == false)
			{
				MessageBox::Show("You lose 5 points.");
			}
		}
		else if (x > 16 && x < 71 && y > 369 && y < 428) //fila 7
		{
			if (objGame->Huma_PutQueen(0, 6) == false)
			{
				MessageBox::Show("You lose 5 points.");
			}
		}
		else if (x > 71 && x < 124 && y > 369 && y < 428)
		{
			if (objGame->Huma_PutQueen(1, 6) == false)
			{
				MessageBox::Show("You lose 5 points.");
			}
		}
		else if (x > 124 && x < 178 && y > 369 && y < 428)
		{
			if (objGame->Huma_PutQueen(2, 6) == false)
			{
				MessageBox::Show("You lose 5 points.");
			}
		}
		else if (x > 178 && x < 231 && y > 369 && y < 428)
		{
			if (objGame->Huma_PutQueen(3, 6) == false)
			{
				MessageBox::Show("You lose 5 points.");
			}
		}
		else if (x > 231 && x < 286 && y > 369 && y < 428)
		{
			if (objGame->Huma_PutQueen(4, 6) == false)
			{
				MessageBox::Show("You lose 5 points.");
			}
		}
		else if (x > 286 && x < 340 && y > 369 && y < 428)
		{
			if (objGame->Huma_PutQueen(5, 6) == false)
			{
				MessageBox::Show("You lose 5 points.");
			}
		}
		else if (x > 340 && x < 394 && y > 369 && y < 428)
		{
			if (objGame->Huma_PutQueen(6, 6) == false)
			{
				MessageBox::Show("You lose 5 points.");
			}
		}
		else if (x > 394 && x < 449 && y > 369 && y < 428)
		{
			if (objGame->Huma_PutQueen(7, 6) == false)
			{
				MessageBox::Show("You lose 5 points.");
			}
		}
		else if (x > 16 && x < 71 && y > 428 && y < 485) //fila 8
		{
			if (objGame->Huma_PutQueen(0, 7) == false)
			{
				MessageBox::Show("You lose 5 points.");
			}
		}
		else if (x > 71 && x < 124 && y > 428 && y < 485)
		{
			if (objGame->Huma_PutQueen(1, 7) == false)
			{
				MessageBox::Show("You lose 5 points.");
			}
		}
		else if (x > 124 && x < 178 && y > 428 && y < 485)
		{
			if (objGame->Huma_PutQueen(2, 7) == false)
			{
				MessageBox::Show("You lose 5 points.");
			}
		}
		else if (x > 178 && x < 231 && y > 428 && y < 485)
		{
			if (objGame->Huma_PutQueen(3, 7) == false)
			{
				MessageBox::Show("You lose 5 points.");
			}
		}
		else if (x > 231 && x < 286 && y > 428 && y < 485)
		{
			if (objGame->Huma_PutQueen(4, 7) == false)
			{
				MessageBox::Show("You lose 5 points.");
			}
		}
		else if (x > 286 && x < 340 && y > 428 && y < 485)
		{
			if (objGame->Huma_PutQueen(5, 7) == false)
			{
				MessageBox::Show("You lose 5 points.");
			}
		}
		else if (x > 340 && x < 394 && y > 428 && y < 485)
		{
			if (objGame->Huma_PutQueen(6, 7) == false)
			{
				MessageBox::Show("You lose 5 points.");
			}
		}
		else if (x > 394 && x < 449 && y > 428 && y < 485)
		{
			if (objGame->Huma_PutQueen(7, 7) == false)
			{
				MessageBox::Show("You lose 5 points.");
			}
		}
	}

	private: System::Void buttonBack_Click(System::Object^ sender, System::EventArgs^ e) {
		objGame->Load();
	}
	private: System::Void buttonJuegaPC_Click(System::Object^ sender, System::EventArgs^ e) {
		objGame->Com_PutQueen();
	}
	};
}
