#ifndef FFT_H
#define FFT_H
#include"Complex.h";


int log2(int N);

int check(int n);

int reverse(int N, int n);

void ordina(Complex* f1, int N);

void transform(Complex* f, int N);


#endif
