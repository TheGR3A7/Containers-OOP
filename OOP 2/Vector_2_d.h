#pragma once
#include "I_Manageable.h"

class Vector_2_d : public IManageable
{
private:
	int x1, x2, y1, y2;
public:
	Vector_2_d(int x1, int y1, int x2, int y2);
	void Print_Short();
	void Print_Full();
	IManageable* Copy();
	bool Is_Equal(IManageable* object);
	float GetValue();
};