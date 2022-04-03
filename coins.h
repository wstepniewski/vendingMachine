#ifndef COINS_H
#define COINS_H
#include "payment.h"
#include "menu.h"

class coins : public payment
{
private:
	bool pay(int x ) final;
	string name() const final;
	static bool addCoin( int &atp );
	static bool isPaid( int atp );
	static void printNotification2();
};

#endif