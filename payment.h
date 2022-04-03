#ifndef PAYMENT_H
#define PAYMENT_H
#include <iostream>
#include "menu.h"
using namespace std;

class payment
{
public:
	virtual bool pay(int x) {};
	virtual string name() const {};
	static string readPIN();
	static bool isCorrectPIN( string PIN, int len );
};

#endif
