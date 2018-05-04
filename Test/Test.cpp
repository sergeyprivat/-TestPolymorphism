// Test.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <iostream>
#include "ConcretaClass1.h"
#include "concrete2.h"
#include "OverrideMethodObj2.h"
#include <map>


using namespace std;

class Entity;
class Tank;

class Body{
public:
	Body(Entity *entity) { this->ent = entity; x = 0; };
	void setX(int x_) { x = x_; };
	int getX() { return x; };
	virtual ~Body() {};
private:
	int x;
	Entity *ent;

};

class Entity {
public:
	void setBody(Body *body_) { body = body_; };
	Body  *getBody() const{ return body; };
	virtual ~Entity() {};
private:
	Body *body;
};

class Tank : public Entity{
public:
	Tank() {
		Body *tankBody = new Body(this);

		setBody(tankBody);
	}
	
	~Tank() {};

private:

};



int main()
{
	char key;
	cout << "main" << endl;

vector<IObj*> vectorObj;
	IObj * concr = new ConcretaClass1;

	vectorObj.push_back(concr);

	vectorObj[0]->method1();
	vectorObj[0]->method2();

	vector<IObj2*> vectorObj2;

	concrete2* concr2 = new concrete2();
	vectorObj2.push_back(concr2);

	OverrideMethodObj2* overMethod2= new OverrideMethodObj2();

	vectorObj2.push_back(overMethod2);

	vectorObj2[0]->methodIObj2();
	vectorObj2[1]->methodIObj2();
	cout << "Tank" << endl;
	Tank newTank1;
	Tank newTank2;
	Tank newTank3;

	
	
	cout << " Tank " << newTank1.getBody()->getX() << endl;
	newTank1.getBody()->setX(10);
	newTank2.getBody()->setX(20);
	newTank3.getBody()->setX(30);
	

	cout << " ------------------------------------- "  << endl;
	map <string, Tank *> myMap;
	myMap = { { "Beta", &newTank1 }, ///явная инициализация map
	{ "Alpha", &newTank2 },
	{ "Gamma", &newTank3 },
	{"Zeta", nullptr} };

	map<string, Tank *>::iterator it = myMap.find("alpha");
	if (myMap["Alpha"])
	{
		cout << " Tank " << myMap["Alpha"]->getBody()->getX() << endl;
	}

	
	if (myMap["Gamma"])
	{
		cout << " Tank " << myMap["Gamma"]->getBody()->getX() << endl;
	}


	cin >> key;

	
    return 0;
}

