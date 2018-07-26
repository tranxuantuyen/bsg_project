#include <iostream>
#include <stdlib.h> 

#include "pre_compute.h"

#define MAX 200
#define PI 3.14

using namespace std;


void firstHalf(Complex* f, int N)
{
	Complex *W;
	W = (Complex *)malloc(N / 2 * sizeof(Complex));				////////////
	W[0].real = 1.0;		W[0].image = 0.0;					// Chuan bi cac he so Wn (cac hach Euler)
	W[1] = conv_from_polar(1.0, -2. * PI / N);					//
	for (int i = 2; i < N / 2; i++)								//	
		W[i] = pow(W[1], i);									//////////////////////				
	////////////////////////////////////////////////////////////////////////////
	int n = 1;															//////
	int a = N / 2;											/// Ham firstHalf duoc su dung de tinh N / 2 
	for (int j = 0; j < log2(N) - 1; j++) {					//diem dau cua chuoi input dau vao. 
		for (int i = 0; i < N / 2; i++) {					//Sau buoc nay, N/2 diem dau da duoc bien doi sang mien pho
			if (!(i & n)) {									//con N/2 diem cuoi van giu nguyen
				Complex temp = f[i];									/////////
				Complex Temp = multiply(W[(i * a) % (n * a)], f[i + n]);//////
				f[i] = add(temp, Temp);
				f[i + n] = sub(temp, Temp);
			}
		}
		n *= 2;
		a = a / 2;
	}

}

void secondHalf(Complex* f, int N)
{
	Complex *W;
	W = (Complex *)malloc(N / 2 * sizeof(Complex));
	W[0].real = 1.0;		W[0].image = 0.0;				/////////// Giong firstHalf.
	W[1] = conv_from_polar(1.0, -2. * PI / N);
	for (int i = 2; i < N / 2; i++)
		W[i] = pow(W[1], i);
	/////////////////////////////////////////////////////////////////////////////
	int n = 1;
	int a = N / 2;											//Ham secondHalf dung de tinh N/2 so sau cua chuoi N input dau vao
	for (int j = 0; j < log2(N) - 1; j++) {					//Sau khi firstHalf va secondHalf chay xong,
		for (int i = N / 2; i < N; i++) {					// ca N/2 input dau va N/2 input sau deu trai qua log2(N) - 1 
			if (!(i & n)) {									//stages cua gian do butterfly. 
				Complex temp = f[i];								//Buoc cuoi se la dua 2 chuoi con nay
				Complex Temp = multiply(W[(i * a) % (n * a)], f[i + n]);/// vao ham merge de chay stage cuoi cung	
				f[i] = add(temp, Temp);
				f[i + n] = sub(temp, Temp);
			}
		}
		n *= 2;
		a = a / 2;
	}
}



void merge(Complex* f, int N)
{
	Complex *W;
	W = (Complex *)malloc(N / 2 * sizeof(Complex));
	W[0].real = 1.0;		W[0].image = 0.0;
	W[1] = conv_from_polar(1.0, -2. * PI / N);  ///////Giong tren 
	for (int i = 2; i < N / 2; i++)
		W[i] = pow(W[1], i);
	//////////////////////////////////////////////////////////
	int n = N / 2;
	int a = 1;
	for (int i = 0; i < N; i++) {						//Ham merge ket hop 2 chuoi N/2 phan tu o 2 buoc tren de co ket qua cuoi cung. 
		if (!(i & n)) {									///////////////
			Complex temp = f[i];						//Chinh la stage cuoi cung trong gian do Butterfly
			Complex Temp = multiply(W[(i * a) % (n * a)], f[i + n]);//////////
			f[i] = add(temp, Temp);						// (voi N input thi se co tat ca log2(N) stages)
			f[i + n] = sub(temp, Temp);
		}
	}
}

int main()
{
	int N = 8;																						//  Khoi tao du lieu 
	Complex f[8] = { { 4, 0 },{ 2, 0 },{ 0, 0 },{ -2, 0 },{ -4, 0 },{ 2, 0 },{ 0, 0 },{ -2, 0 } };	// N can la luy thua cua 2

	/////////////////////////////////////////////////////////////////////////
	ordina(f, 8);	//Sap xep lai vi tri cua day input

	firstHalf(f, N); // Thuc hien tinh toan cho N/2 diem dau, du kien assign cho processor 1

	secondHalf(f, N); //Thuc hien tinh toan cho N/2 diem sau, du kien assign cho processor 2
	
	merge(f, N); // Merge 2 chuoi N/2 phan tu o tren, assign cho processor 3

	/*
		if(id == 1)
			firstHalf(f, N);
		else if(id == 2)
			....
	*/
	/////////////////////////////////////////////////////////////////////

	cout << "Result" << endl;
	for (int j = 0; j < 8; j++)
		cout << f[j].real << " " << f[j].image << endl;
	return 0;

}