#ifndef MACHINE_H
#define MACHINE_H
#include "drink.h"
#include "payment.h"
#include "menu.h"
#include "container.h"
#include <vector> 

struct ERROR_incorrect_value {};
struct ERROR_fatal_value {};

class vending_machine
{
public:
	vending_machine(int nDrinks, drink *pDrinks[], int nPayments, payment *pPayments[] ); // constructor
	void printDrinks() const; // prints available drinks, its prices and names
	drink *chooseDrink(int choice );
	static int getPrice(drink *dr ) { return dr->price; }; // returns price of specific drink
	void printPayments() const; // prints available payment methods
	payment* choosePayment(int choice ); // choose payment method
	void updateStock(drink* dr); // updates stock of drinks in vending machine

private:
	int n; // number of available drinks
	int m; // number of available payment methods
	vector <int> quantity; // vector containing quantity of ech drink in vending machines
	container <drink *> drinks; // custom container containing every drink
	container <payment *> payments; // custom container containing every available payment method
	void printDrink(drink *x ) const; // prints individual drink
	static void printNotification1(drink *x ); // notification about selected drink
	friend class payment;
};


#endif