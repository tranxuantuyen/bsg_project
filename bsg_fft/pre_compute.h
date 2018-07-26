

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

int log2(int N);

int check(int n);

int reverse(int N, int n);


void ordina(Complex* f1, int N);
