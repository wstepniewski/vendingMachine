#ifndef DRINK_H
#define DRINK_H
#include <iostream>
#include <cstring>
#include <utility>
using namespace std;

class drink
{
public:
	drink(const int idd, string  name, const int price ) : id(idd ), name(std::move(name )), price(price ) {}// constructor
	drink(const int idd, string  name, const double dPrice ) : id(idd ), name(std::move(name )), price(static_cast<int>( 100 * dPrice )) {}// same constructor but you can put price in double
	
private:
	const int id;
	const string name;
	const int price;
	friend class vending_machine;
};

#endif