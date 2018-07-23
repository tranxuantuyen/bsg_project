#ifndef COMPLEX_H
#define COMPLEX_H


#include<math.h>
struct Complex
{
	double real;
	double image;
};

Complex add(Complex left, Complex right);

Complex sub(Complex left, Complex right);

Complex conv_from_polar(double r, double radians);

Complex multiply(Complex left, Complex right);

Complex pow(Complex v, int n);

#endif
