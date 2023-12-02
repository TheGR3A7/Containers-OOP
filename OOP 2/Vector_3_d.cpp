#define _CRT_SECURE_NO_WARNINGS
#include "Vector_3_d.h"
#include <iostream>
#include <math.h>

using namespace std;

Vector_3_d::Vector_3_d(int x1, int y1, int x2, int y2, int z1, int z2)
{
    this->x1 = x1;
    this->x2 = x2;
    this->y1 = y1;
    this->y2 = y2;
    this->z1 = z1;
    this->z2 = z2;
}

void Vector_3_d::Print_Short()
{
    cout << "Short Vector: {" << x2 - x1 << ", " << y2 - y1 << ", " << z2 - z1 << "}";
}

void Vector_3_d::Print_Full()
{
    cout << "Short Vector: {" << x1 << ", " << y1 << ", " << z1 << "}, {" << x2 << ", " << y2 << ", " << z2 << "}" << endl;
}

IManageable* Vector_3_d::Copy()
{
    Vector_3_d* new_vector = new Vector_3_d(x1, y1, z1, x2, y2, z2);
    return new_vector;
}

bool Vector_3_d::Is_Equal(IManageable* object)
{
    Vector_3_d* object2 = (Vector_3_d*)object;
    return(x1 == object2->x1 && x2 == object2->x2 && y1 == object2->y1 && y2 == object2->y2 && z1 == object2->z1 && z2 == object2->z2);
    
}

float Vector_3_d::GetValue()
{
    return sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1) + (z2 - z1) * (z2 - z1));
}