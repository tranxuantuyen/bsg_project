
#include"Complex.h"

Complex add(Complex left, Complex right) {
	Complex result;
	result.real = left.real + right.real;
	result.image = left.image + right.image;
	return result;
}

Complex sub(Complex left, Complex right) {
	Complex result;
	result.real = left.real - right.real;
	result.image = left.image - right.image;
	return result;
}

Complex conv_from_polar(double r, double radians) {
	Complex result;
	result.real = r * cos(radians);
	result.image = r * sin(radians);
	return result;
}

Complex multiply(Complex left, Complex right) {
	Complex result;
	result.real = left.real*right.real - left.image*right.image;
	result.image = left.real*right.image + left.image*right.real;
	return result;
}

Complex pow(Complex v, int n) {
	int i = 1;
	Complex temp = v;
	for (i = 2; i <= n; i++)
	{
		v = multiply(v, temp);
	}
	return v;
}
