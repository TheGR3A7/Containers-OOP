#define _CRT_SECURE_NO_WARNINGS
#include "Text.h"
#include <iostream>
#include <string.h>

using namespace std;

Text::Text(char* text) 
{
    if (text != nullptr) 
        strcpy(this->text, text);
}

void Text::Print_Short()
{
    int length = GetValue();
    if (length <= 10)
        cout << text;
    else 
        cout << text[0] << text[1] << text[2] << "..." << text[length - 3] << text[length - 2] << text[length - 1];
}

void Text::Print_Full() 
{
    cout << "Full Text: " << text << std::endl;
}

IManageable* Text::Copy()
{
    Text* new_text = new Text(this->text); 
    return new_text;
}

bool Text::Is_Equal(IManageable* object) 
{
    Text* other_text = (Text*)object;
    return strcmp(text, other_text->text) == 0;
}

float Text::GetValue() 
{
    return strlen(text);
}