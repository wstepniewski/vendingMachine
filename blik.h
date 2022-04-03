#ifndef BLIK_H
#define BLIK_H
#include "payment.h"

class blik : public payment
{
private:
	bool pay(int x ) final;
	string name() const final;
	const int PINlen = 6;
};

#endif
