#define _CRT_SECURE_NO_WARNINGS
#include "Complex.h"
#include <iostream>
#include <math.h>

using namespace std;

Complex::Complex(int real, int imaginary)
{
	this->real = real;
	this->imaginary = imaginary;
}

void Complex::Print_Short()
{
	char sign;
	if (imaginary < 0)
		sign = '-';
	else 
		sign = '+';
	cout << real << " " << sign << " " << imaginary << "i";
}

void Complex::Print_Full()
{
	char sign;
	if (imaginary < 0)
		sign = '-';
	else
		sign = '+';
	cout << real << " " << sign << " " << imaginary << "i, " << GetValue();
}

IManageable* Complex::Copy()
{
	Complex* new_compl = new Complex(real, imaginary);
	return new_compl;
}

bool Complex::Is_Equal(IManageable* object)
{
	Complex* object2 = (Complex*)object;
	return real == object2->real && imaginary == object2->imaginary;
}

float Complex::GetValue()
{
	return sqrt(real * real + imaginary * imaginary);
}
