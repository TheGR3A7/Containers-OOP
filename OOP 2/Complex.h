#pragma once
#include "I_Manageable.h"

class Complex : public IManageable
{
private:
    float real, imaginary;
public:
    Complex(int real, int imaginary);
    void Print_Short();
    void Print_Full();
    IManageable* Copy();
    bool Is_Equal(IManageable* object);
    float GetValue();
};