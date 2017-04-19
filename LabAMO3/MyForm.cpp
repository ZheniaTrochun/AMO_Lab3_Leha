#include "MyForm.h"
#include "MyForm1.h"
#include <sstream>

using namespace System;
using namespace System::Windows::Forms;


[STAThread]
void Main(array<String^>^ args)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	LabAMO3::MyForm form;
	Application::Run(%form);
}

System::Void LabAMO3::MyForm::button1_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	try
	{
		std::ostringstream ostr;

		ostr << interpolator.newton(Double::Parse(textBox1->Text), nodes, xInterpolationArr, yInterpolationArr);

		textBox3->Text = gcnew String(ostr.str().c_str());

		std::ostringstream ostr2;

		ostr2 << fabs(sin(Double::Parse(textBox1->Text)) - interpolator.newton(Double::Parse(textBox1->Text), nodes, xInterpolationArr, yInterpolationArr));

		std::ostringstream ostr3;

		ostr3 << sin(Double::Parse(textBox1->Text));

		textBox2->Text = gcnew String(ostr3.str().c_str());

		textBox4->Text = gcnew String(ostr2.str().c_str());
	}
	catch (FormatException ^e) {
		textBox4->Text = "";
		textBox3->Text = "";
		textBox2->Text = "";
		textBox1->Text = "Incorrect input";
	}
}

System::Void LabAMO3::MyForm::MyForm_Load(System::Object ^ sender, System::EventArgs ^ e)
{
	xInterpolationArr = new double[nodes];
	yInterpolationArr = new double[nodes];

	for (int i(0); i < nodes; i++)
	{
		xInterpolationArr[i] = 1 + i * 0.2;
		yInterpolationArr[i] = sin(xInterpolationArr[i]);
	}
	
	for (double i(1.01); i < 3; i += 0.1)
	{
		chart1->Series["function"]->Points->AddXY(i, sin(i));
		chart1->Series["interpolation"]->Points->AddXY(i, interpolator.newton(i, nodes, xInterpolationArr, yInterpolationArr));
		chart2->Series["delta"]->Points->AddXY(i, fabs(sin(i) - interpolator.newton(i, nodes, xInterpolationArr, yInterpolationArr)));
	}
}

System::Void LabAMO3::MyForm::otherToolStripMenuItem_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	MyForm1^ exp = gcnew MyForm1;
	this->Visible = false;
	exp->ShowDialog(this);
	this->Close();
}
