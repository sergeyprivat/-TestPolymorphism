// Test.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <iostream>
#include "ConcretaClass1.h"
#include "concrete2.h"
#include "OverrideMethodObj2.h"


using namespace std;

class Entity;
class Tank;

class Body{
public:
	Body(Entity *entity) { this->ent = entity; x = 0; };
	void setX(int x_) { x = x_; };
	int getX() { return x; };
	~Body() {};
private:
	int x;
	Entity *ent;

};

class Entity {
public:
	void setBody(Body *body_) { body = body_; };
	Body  *getBody() const{ return body; };
	~Entity() {};
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
	Tank newTank;

	
	
	cout << " Tank " << newTank.getBody()->getX() << endl;
	newTank.getBody()->setX(10);
	cout << " Tank " << newTank.getBody()->getX() << endl;

	cin >> key;

	
    return 0;
}

