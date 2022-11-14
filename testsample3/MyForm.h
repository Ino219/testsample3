#pragma once
#include"Field.h"
#include"block.h"

namespace testsample3 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	using namespace testsample3;
	using namespace block_h;

	/// <summary>
	/// MyForm の概要
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: ここにコンストラクター コードを追加します
			//
			bmp = gcnew Bitmap(pictureBox1->Width, pictureBox1->Height);
			pictureBox1->Image = bmp;
			gr = Graphics::FromImage(pictureBox1->Image);
			//枠線の色と太さを指定
			pn = gcnew Pen(Color::Black, 1);
			//塗りつぶしの色を指定
			sb = gcnew SolidBrush(Color::SeaGreen);

		}

	protected:
		/// <summary>
		/// 使用中のリソースをすべてクリーンアップします。
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::PictureBox^  pictureBox1;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::Timer^  timer1;
	private: System::Windows::Forms::Button^  button4;
	private: System::ComponentModel::IContainer^  components;
	protected:

	private:
		/// <summary>
		/// 必要なデザイナー変数です。
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// デザイナー サポートに必要なメソッドです。このメソッドの内容を
		/// コード エディターで変更しないでください。
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->button4 = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// pictureBox1
			// 
			this->pictureBox1->BackColor = System::Drawing::Color::Khaki;
			this->pictureBox1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->pictureBox1->Location = System::Drawing::Point(12, 30);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(150, 200);
			this->pictureBox1->TabIndex = 0;
			this->pictureBox1->TabStop = false;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(187, 30);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 1;
			this->button1->Text = L"down/↓";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(187, 74);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(75, 23);
			this->button2->TabIndex = 2;
			this->button2->Text = L"left/←";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(187, 121);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(75, 23);
			this->button3->TabIndex = 3;
			this->button3->Text = L"right/→";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm::button3_Click);
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Interval = 1000;
			this->timer1->Tick += gcnew System::EventHandler(this, &MyForm::timer1_Tick);
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(187, 166);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(75, 23);
			this->button4->TabIndex = 4;
			this->button4->Text = L"rotate";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &MyForm::button4_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(284, 261);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->pictureBox1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
		Bitmap^ bmp;
		Graphics^ gr;
		Pen^ pn;
		SolidBrush^ sb;
		block^ b1;
	private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e) {
		//blockにblock1インスタンスを代入
		b1 = gcnew block1();
		//フラグの変更
		b1->create_block(3);
		
		paint_graphics();

		pictureBox1->Refresh();
	}
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
		gr->Clear(Color::Khaki);

		b1->down_bl();

		paint_graphics();

		pictureBox1->Refresh();

	}
private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
	gr->Clear(Color::Khaki);

	b1->left_bl();

	paint_graphics();

	pictureBox1->Refresh();
}
private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {
	gr->Clear(Color::Khaki);

	b1->right_bl();

	paint_graphics();

	pictureBox1->Refresh();
}
		 private: Void paint_graphics() {
			 //フラグがtrueのフィールド番号を描画する
			 for (int i = 0; i < b1->get_flg_list()->Count; i++) {
				 //フラグがtrueのフィールド番号を代入
				 int tmp = b1->get_flg_list()[i];
				 int t_x = b1->get_fld_x(tmp);
				 int t_y = b1->get_fld_y(tmp);
				 gr->FillRectangle(sb, Rectangle(t_x, t_y, b1->get_space(), b1->get_space()));
				 gr->DrawRectangle(pn, t_x, t_y, b1->get_space(), b1->get_space());
			 }
		 }
private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) {

	gr->Clear(Color::Khaki);

	b1->down_bl();

	paint_graphics();

	pictureBox1->Refresh();

}
private: System::Void button4_Click(System::Object^  sender, System::EventArgs^  e) {
	gr->Clear(Color::Khaki);

	b1->rotate();

	paint_graphics();

	pictureBox1->Refresh();
}
};
}
