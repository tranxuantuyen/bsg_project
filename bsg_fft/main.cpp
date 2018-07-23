#include <iostream>

#include"Complex.h"
#include"fft.h"

using namespace std;

// #define M_PI 3.1415926535897932384




int main()
{
	int N = 8;
	Complex vec[8] = { { 4, 0 },{ 2, 0 },{ 0, 0 },{ -2, 0 },{ -4, 0 },{ 2, 0 },{ 0, 0 },{ -2, 0 } };

	transform(vec, N);
	cout << "Result: "<< endl;
	for (int j = 0; j < N; j++)
		cout << vec[j].real << ", " << vec[j].image << endl;
	return 0;

}