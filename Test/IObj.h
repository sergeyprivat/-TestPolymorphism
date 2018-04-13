#pragma once
class IObj
{
public:
	virtual void method1() = 0;
	virtual void method2() = 0;
	IObj();
	~IObj();
};

