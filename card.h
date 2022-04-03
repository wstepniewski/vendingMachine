#ifndef CARD_H
#define CARD_H
#include "payment.h"

class card : public payment
{
private:
	bool pay(int x ) final;
	string name() const final;
	const int PINlen = 4;
};

#endif
