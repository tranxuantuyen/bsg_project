#include"fft.h"
#include <stdlib.h> 
#define MAX 200
#define PI 3.1415

int log2(int N)   
{
	int k = N, i = 0;
	while (k) {
		k >>= 1;
		i++;
	}
	return i - 1;
}

int check(int n)   
{
	return n > 0 && (n & (n - 1)) == 0;
}

int reverse(int N, int n)    
{
	int j, p = 0;
	for (j = 1; j <= log2(N); j++) {
		if (n & (1 << (log2(N) - j)))
			p |= 1 << (j - 1);
	}
	return p;
}

void ordina(Complex* f1, int N) 
{
	Complex f2[MAX];
	for (int i = 0; i < N; i++)
		f2[i] = f1[reverse(N, i)];
	for (int j = 0; j < N; j++)
		f1[j] = f2[j];
}

void transform(Complex* f, int N) 
{
	ordina(f, N);    
	Complex *W;
	W = (Complex *)malloc(N / 2 * sizeof(Complex));
	W[0].real = 1.0;		W[0].image = 0.0;
	W[1] = conv_from_polar(1.0, -2. * PI / N);
	for (int i = 2; i < N / 2; i++)
		W[i] = pow(W[1], i);

	int n = 1;
	int a = N / 2;
	for (int j = 0; j < log2(N); j++) {
		for (int i = 0; i < N; i++) {
			if (!(i & n)) {
				Complex temp = f[i];
				Complex Temp = multiply(W[(i * a) % (n * a)], f[i + n]);
				f[i] = add(temp, Temp);
				f[i + n] = sub(temp, Temp);
			}
		}
		n *= 2;
		a = a / 2;
	}
}
