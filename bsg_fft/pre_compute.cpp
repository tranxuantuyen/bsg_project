#include<math.h>
#include"pre_compute.h"
#define MAX 200
#define PI 3.14
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


int log2(int N)    /*function to calculate the log2(.) of int numbers*/
{
	int k = N, i = 0;
	while (k) {
		k >>= 1;
		i++;
	}
	return i - 1;
}

int check(int n)    //checking if the number of element is a power of 2
{
	return n > 0 && (n & (n - 1)) == 0;
}

int reverse(int N, int n)    //calculating revers number
{
	int j, p = 0;
	for (j = 1; j <= log2(N); j++) {
		if (n & (1 << (log2(N) - j)))
			p |= 1 << (j - 1);
	}
	return p;
}

void ordina(Complex* f1, int N) //using the reverse order in the array
{
	Complex f2[MAX];
	for (int i = 0; i < N; i++)
		f2[i] = f1[reverse(N, i)];
	for (int j = 0; j < N; j++)
		f1[j] = f2[j];
}

