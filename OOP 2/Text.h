#pragma once
#include "I_Manageable.h"

class Text : public IManageable 
{
private:
	char text[100] = { 0 };
public:
    Text(char* text);
    void Print_Short();
    void Print_Full();
    IManageable* Copy();
    bool Is_Equal(IManageable* object);
    float GetValue();
};
