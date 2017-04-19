#include "MyForm1.h"
#include <sstream>

using namespace System;
using namespace System::Windows::Forms;


System::Void LabAMO3::MyForm1::button1_Click(System::Object ^ sender, System::EventArgs ^ e)
{	
	try
	{
		std::ostringstream ostr;

		ostr << interpolator.newton(Double::Parse(textBox1->Text), nodes, xInterpolationArr, yInterpolationArr);

		textBox3->Text = gcnew String(ostr.str().c_str());

		std::ostringstream ostr2;

		ostr2 << fabs(exp(-(Double::Parse(textBox1->Text) + 1)/ Double::Parse(textBox1->Text)) - interpolator.newton(Double::Parse(textBox1->Text), nodes, xInterpolationArr, yInterpolationArr));

		std::ostringstream ostr3;

		ostr3 << exp(-(Double::Parse(textBox1->Text) + 1)/ Double::Parse(textBox1->Text));

		textBox2->Text = gcnew String(ostr3.str().c_str());

		textBox4->Text = gcnew String(ostr2.str().c_str());

	} catch(FormatException ^e) {
		textBox4->Text = "";
		textBox3->Text = "";
		textBox2->Text = "";
		textBox1->Text = "Incorrect input";
	}
}

System::Void LabAMO3::MyForm1::MyForm_Load(System::Object ^ sender, System::EventArgs ^ e)
{
	xInterpolationArr = new double[nodes];
	yInterpolationArr = new double[nodes];

	for (int i(0); i < nodes; i++)
	{
		xInterpolationArr[i] = 1 + i * 0.2;
		yInterpolationArr[i] = exp(-(xInterpolationArr[i]+1)/xInterpolationArr[i]);
	}

	for (double i(1.0); i <= 3; i += 0.1)
	{
		chart1->Series["function"]->Points->AddXY(i, exp(-(i + 1) / i));
		chart1->Series["interpolation"]->Points->AddXY(i, interpolator.newton(i, nodes, xInterpolationArr, yInterpolationArr));
		chart2->Series["delta"]->Points->AddXY(i, fabs(exp(-(i + 1) / i) - interpolator.newton(i, nodes, xInterpolationArr, yInterpolationArr)));
	}
}

System::Void LabAMO3::MyForm1::sinxToolStripMenuItem_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	MyForm^ sin = gcnew MyForm;
	this->Visible = false;
	sin->ShowDialog(this);
	this->Close();
}

