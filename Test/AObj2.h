#pragma once
#include "IObj2.h"
class AObj2 :
	public IObj2

{
public:
	virtual void methodIObj2() = 0;
	void methodAObj2();
	AObj2();
	~AObj2();
};

