#pragma once
class IManageable;

class ICopyable
{
public:
	virtual IManageable* Copy() = 0;
	virtual bool Is_Equal(IManageable* object) = 0;
};