#include "Interpolator.h"



Interpolator::Interpolator()
{
}

double Interpolator::newton(double t, int n, double *x, double *y)
{
	double res = y[0], F, den;
	int i, j, k;
	for (i = 1; i < n; i++)
	{
		F = 0;
		for (j = 0; j <= i; j++)
		{
			den = 1;
			for (k = 0; k <= i; k++)
			{
				if (k != j) den *= (x[j] - x[k]);
			}
			F += y[j] / den;
		}
		for (k = 0; k < i; k++) F *= (t - x[k]);
		res += F;
	}
	return res;
}
