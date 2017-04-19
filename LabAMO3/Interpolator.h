#pragma once
ref class Interpolator
{
public:
	Interpolator();
	double newton(double t, int n, double *x, double *y);
};

