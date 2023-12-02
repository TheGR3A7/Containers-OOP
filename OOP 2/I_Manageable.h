#pragma once
#include "I_Printable.h"
#include "I_Copyable.h"
#include "I_Value.h"

class IManageable : public IPrintable, public ICopyable, public IValue 
{
	public:
		
};