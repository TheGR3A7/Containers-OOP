#define _CRT_SECURE_NO_WARNINGS
#include "Vector_2_d.h"
#include <iostream>
#include <math.h>

using namespace std;

Vector_2_d::Vector_2_d(int x1, int y1, int x2, int y2)
{
    this->x1 = x1;
    this->x2 = x2;
    this->y1 = y1;
    this->y2 = y2;
}

void Vector_2_d::Print_Short() 
{
    cout << "Short Vector: {" << x2 - x1 << ", " << y2 - y1 << "}";
}

void Vector_2_d::Print_Full() 
{
    cout << "Full Vector: {" << x1 << ", " << y1 << "}, {" << x2 << ", " << y2 << "}";
}

IManageable* Vector_2_d::Copy()
{
    Vector_2_d* new_vector = new Vector_2_d(x1, y1, x2, y2);
    return new_vector;
}

bool Vector_2_d::Is_Equal(IManageable* object) 
{
    Vector_2_d* object2 = (Vector_2_d*)object;
    return(x1 == object2->x1 && x2 == object2->x2 && y1 == object2->y1 && y2 == object2->y2);
}

float Vector_2_d::GetValue()
{
    return sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
}
