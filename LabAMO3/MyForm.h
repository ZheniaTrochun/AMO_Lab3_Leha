#pragma once
#include <math.h>
#include "Interpolator.h"

namespace LabAMO3 {

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
	public:
		MyForm(void)
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
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::MenuStrip^  menuStrip1;
	protected:
	private: System::Windows::Forms::ToolStripMenuItem^  sinxToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  otherToolStripMenuItem;
	private: System::Windows::Forms::DataVisualization::Charting::Chart^  chart1;
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::TextBox^  textBox2;
	private: System::Windows::Forms::TextBox^  textBox3;
	private: System::Windows::Forms::Button^  button1;

	private: double *yInterpolationArr;
	private: int nodes = 11;
	private: double *xInterpolationArr;
	private: Interpolator interpolator;
	private: System::Windows::Forms::TextBox^  textBox4;
	private: System::Windows::Forms::DataVisualization::Charting::Chart^  chart2;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label4;

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
			System::Windows::Forms::DataVisualization::Charting::ChartArea^  chartArea1 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Legend^  legend1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
			System::Windows::Forms::DataVisualization::Charting::Series^  series1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::Series^  series2 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::ChartArea^  chartArea2 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Legend^  legend2 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
			System::Windows::Forms::DataVisualization::Charting::Series^  series3 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->sinxToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->otherToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->chart1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->chart2 = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->menuStrip1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart2))->BeginInit();
			this->SuspendLayout();
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->sinxToolStripMenuItem,
					this->otherToolStripMenuItem
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(838, 24);
			this->menuStrip1->TabIndex = 0;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// sinxToolStripMenuItem
			// 
			this->sinxToolStripMenuItem->Name = L"sinxToolStripMenuItem";
			this->sinxToolStripMenuItem->Size = System::Drawing::Size(47, 20);
			this->sinxToolStripMenuItem->Text = L"sin(x)";
			// 
			// otherToolStripMenuItem
			// 
			this->otherToolStripMenuItem->Name = L"otherToolStripMenuItem";
			this->otherToolStripMenuItem->Size = System::Drawing::Size(83, 20);
			this->otherToolStripMenuItem->Text = L"e^(-(x+1)/x)";
			this->otherToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::otherToolStripMenuItem_Click);
			// 
			// chart1
			// 
			chartArea1->Name = L"ChartArea1";
			this->chart1->ChartAreas->Add(chartArea1);
			legend1->Name = L"Legend1";
			this->chart1->Legends->Add(legend1);
			this->chart1->Location = System::Drawing::Point(0, 27);
			this->chart1->Name = L"chart1";
			series1->ChartArea = L"ChartArea1";
			series1->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Spline;
			series1->Legend = L"Legend1";
			series1->Name = L"function";
			series2->ChartArea = L"ChartArea1";
			series2->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Line;
			series2->Legend = L"Legend1";
			series2->Name = L"interpolation";
			this->chart1->Series->Add(series1);
			this->chart1->Series->Add(series2);
			this->chart1->Size = System::Drawing::Size(589, 327);
			this->chart1->TabIndex = 1;
			this->chart1->Text = L"chart1";
			this->chart1->DoubleClick += gcnew System::EventHandler(this, &MyForm::chart1_DoubleClick);
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(653, 144);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(123, 20);
			this->textBox1->TabIndex = 2;
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(653, 254);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(123, 20);
			this->textBox2->TabIndex = 3;
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(653, 196);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(123, 20);
			this->textBox3->TabIndex = 4;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(667, 393);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(94, 28);
			this->button1->TabIndex = 5;
			this->button1->Text = L"Calculate";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// textBox4
			// 
			this->textBox4->Location = System::Drawing::Point(653, 312);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(123, 20);
			this->textBox4->TabIndex = 6;
			// 
			// chart2
			// 
			chartArea2->Name = L"ChartArea1";
			this->chart2->ChartAreas->Add(chartArea2);
			legend2->Name = L"Legend1";
			this->chart2->Legends->Add(legend2);
			this->chart2->Location = System::Drawing::Point(0, 350);
			this->chart2->Name = L"chart2";
			series3->ChartArea = L"ChartArea1";
			series3->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Spline;
			series3->Legend = L"Legend1";
			series3->Name = L"delta";
			this->chart2->Series->Add(series3);
			this->chart2->Size = System::Drawing::Size(589, 223);
			this->chart2->TabIndex = 7;
			this->chart2->Text = L"chart2";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(650, 128);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(12, 13);
			this->label1->TabIndex = 8;
			this->label1->Text = L"x";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(650, 180);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(70, 13);
			this->label2->TabIndex = 9;
			this->label2->Text = L"interpolated y";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(650, 238);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(12, 13);
			this->label3->TabIndex = 10;
			this->label3->Text = L"y";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(650, 296);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(43, 13);
			this->label4->TabIndex = 11;
			this->label4->Text = L"mistake";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(838, 573);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->chart2);
			this->Controls->Add(this->textBox4);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->chart1);
			this->Controls->Add(this->menuStrip1);
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"MyForm";
			this->Text = L"sin(x)";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart2))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void chart1_DoubleClick(System::Object^  sender, System::EventArgs^  e) {
		this->chart1->ChartAreas["ChartArea1"]->AxisX->ScaleView->Zoom(1, 1.1);
		chart1->ChartAreas["ChartArea1"]->AxisY->ScaleView->Zoom(0.5, 0.55);
		chart1->ChartAreas["ChartArea1"]->CursorX->IsUserEnabled = true;
		chart1->ChartAreas["ChartArea1"]->CursorX->IsUserSelectionEnabled = true;
		chart1->ChartAreas["ChartArea1"]->AxisX->ScaleView->Zoomable = true;
		chart1->ChartAreas["ChartArea1"]->AxisX->ScrollBar->IsPositionedInside = false;
		chart1->ChartAreas["ChartArea1"]->CursorY->IsUserEnabled = true;
		chart1->ChartAreas["ChartArea1"]->CursorY->IsUserSelectionEnabled = true;
		chart1->ChartAreas["ChartArea1"]->AxisY->ScaleView->Zoomable = true;
		chart1->ChartAreas["ChartArea1"]->AxisY->ScrollBar->IsPositionedInside = false;
	}
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e);
private: System::Void otherToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e);
};
}
