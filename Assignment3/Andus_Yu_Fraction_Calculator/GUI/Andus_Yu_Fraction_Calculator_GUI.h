#pragma once

#include "Andus_Yu_Fraction_Calculator.h"

namespace Andus_Yu_Fraction_Calculator_GUI {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for GUI
	/// </summary>
	public ref class GUI : public System::Windows::Forms::Form
	{
	public:
		GUI(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~GUI()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^  textBox1;
	protected:
	private: System::Windows::Forms::TextBox^  textBox2;
	private: System::Windows::Forms::TextBox^  textBox3;
	private: System::Windows::Forms::TextBox^  textBox4;
	private: System::Windows::Forms::ComboBox^  comboBox1;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::TextBox^  textBox5;
	private: System::Windows::Forms::TextBox^  textBox6;










	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->textBox5 = (gcnew System::Windows::Forms::TextBox());
			this->textBox6 = (gcnew System::Windows::Forms::TextBox());
			this->SuspendLayout();
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(38, 74);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(108, 22);
			this->textBox1->TabIndex = 0;
			this->textBox1->Text = L"Numer 1";
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &GUI::textBox1_TextChanged);
			this->textBox1->KeyDown += gcnew KeyEventHandler(this, &GUI::keyPress);
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(242, 74);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(108, 22);
			this->textBox2->TabIndex = 1;
			this->textBox2->Text = L"Numer 2";
			this->textBox2->TextChanged += gcnew System::EventHandler(this, &GUI::textBox2_TextChanged);
			this->textBox2->KeyDown += gcnew KeyEventHandler(this, &GUI::keyPress);
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(38, 130);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(108, 22);
			this->textBox3->TabIndex = 2;
			this->textBox3->Text = L"Denom 1";
			this->textBox3->TextChanged += gcnew System::EventHandler(this, &GUI::textBox3_TextChanged);
			this->textBox3->KeyDown += gcnew KeyEventHandler(this, &GUI::keyPress);
			// 
			// textBox4
			// 
			this->textBox4->Location = System::Drawing::Point(242, 130);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(108, 22);
			this->textBox4->TabIndex = 3;
			this->textBox4->Text = L"Denom 2";
			this->textBox4->TextChanged += gcnew System::EventHandler(this, &GUI::textBox4_TextChanged);
			this->textBox4->KeyDown += gcnew KeyEventHandler(this, &GUI::keyPress);
			// 
			// comboBox1
			// 
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Items->AddRange(gcnew cli::array< System::Object^  >(4) { L"+", L"-", L"*", L"/" });
			this->comboBox1->Location = System::Drawing::Point(161, 99);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(65, 24);
			this->comboBox1->TabIndex = 4;
			this->comboBox1->SelectedIndex = 0;
			this->comboBox1->KeyDown += gcnew KeyEventHandler(this, &GUI::keyPress);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(369, 100);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 5;
			this->button1->Text = L"=";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &GUI::button1_Click);
			// 
			// textBox5
			// 
			this->textBox5->Location = System::Drawing::Point(494, 73);
			this->textBox5->Name = L"textBox5";
			this->textBox5->ReadOnly = true;
			this->textBox5->Size = System::Drawing::Size(100, 22);
			this->textBox5->TabIndex = 6;
			this->textBox5->KeyDown += gcnew KeyEventHandler(this, &GUI::keyPress);
			// 
			// textBox6
			// 
			this->textBox6->Location = System::Drawing::Point(494, 130);
			this->textBox6->Name = L"textBox6";
			this->textBox6->ReadOnly = true;
			this->textBox6->Size = System::Drawing::Size(100, 22);
			this->textBox6->TabIndex = 7;
			this->textBox6->KeyDown += gcnew KeyEventHandler(this, &GUI::keyPress);
			// 
			// GUI
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(635, 234);
			this->Controls->Add(this->textBox6);
			this->Controls->Add(this->textBox5);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->comboBox1);
			this->Controls->Add(this->textBox4);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox1);
			this->Name = L"GUI";
			this->Text = L"Andus Yu Fraction calculator";
			this->Load += gcnew System::EventHandler(this, &GUI::GUI_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
private: System::Void GUI_Load(System::Object^  sender, System::EventArgs^  e) {
}

private: System::Void keyPress(System::Object^ sender, System::Windows::Forms::KeyEventArgs^  e) {
	if (e ->KeyCode == Keys::Enter) {
		calculate();
	}
	if (e->Alt && e->KeyCode == Keys::C) {
		this->Close();
	}
}

private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
	calculate();
}

private: void calculate() {
	std::vector<int> numer(2);
	std::vector<int> denom(2);

	std::string str;
	// When the equals button is pressed
	try {
		numer[0] = Convert::ToInt32(textBox1->Text);
		numer[1] = Convert::ToInt32(textBox2->Text);
		denom[0] = Convert::ToInt32(textBox3->Text);
		denom[1] = Convert::ToInt32(textBox4->Text);
	}
	catch (FormatException^ e) {
		MessageBox::Show("Invalid Parameters");
		return;
	}

	// Check if the denominator is 0
	if (denom[0] == 0 || denom[1] == 0) {
		MessageBox::Show("Denominator must not be 0!");
		return;
	}

	// Create the fraction objects
	Fraction f1(numer[0], denom[0]);
	Fraction f2(numer[1], denom[1]);
	Fraction result;

	int selected = comboBox1->SelectedIndex;

	if (selected == 0) { // Addition
		result = f1 + f2;
	}
	else if (selected == 1) { // Subtraction
		result = f1 - f2;
	}
	else if (selected == 2) { // Multiplication
		result = f1 * f2;
	}
	else if (selected == 3) { // Division
		result = f1 / f2;
	}

	// Set the answer textboxes
	textBox5->Text = System::Convert::ToString(result.numerator());
	if (result.denominator() == 1 || result.numerator() == 0) { // Check if the denominator is equal to 1 or if the numerator is equal to 0
		textBox6->Text = ""; // Display nothing/set to blank
	}
	else {
		textBox6->Text = System::Convert::ToString(result.denominator()); // Set to the denominator
	}
}
private: System::Void textBox1_TextChanged(System::Object^  sender, System::EventArgs^  e) {
	textBox5->Text = ""; // Display nothing/set to blank
	textBox6->Text = ""; // Display nothing/set to blank
}
private: System::Void textBox2_TextChanged(System::Object^  sender, System::EventArgs^  e) {
	textBox5->Text = ""; // Display nothing/set to blank
	textBox6->Text = ""; // Display nothing/set to blank
}
private: System::Void textBox3_TextChanged(System::Object^  sender, System::EventArgs^  e) {
	textBox5->Text = ""; // Display nothing/set to blank
	textBox6->Text = ""; // Display nothing/set to blank
}
private: System::Void textBox4_TextChanged(System::Object^  sender, System::EventArgs^  e) {
	textBox5->Text = ""; // Display nothing/set to blank
	textBox6->Text = ""; // Display nothing/set to blank
}
};

}
