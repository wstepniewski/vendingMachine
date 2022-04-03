#include "coins.h"
#include <iostream>
using namespace std;

bool coins::pay(int x ){
    printNotification2();
	do {
		if( !addCoin( x ) ){
			cout << "  Please choose another coin, lesser than amount to pay." << endl;
		}
	} while( !isPaid( x ) );
	return true;
}

bool coins::addCoin(int &atp ){
	int x;
	int coin = readInt();

	switch( coin ){
	case 1:
		x = 100;
		break;
	case 2:
		x = 200;
		break;
	case 5:
		x = 500;
		break;
	case 10:
		x = 10;
		break;
	case 20:
		x = 20;
		break;
	case 50:
		x = 50;
		break;
	default:
		cout << "  Please choose correct coin." << endl;
		printNotification2();
		return false;
	}
	if(x <= atp ){
        atp -= x;
		if(atp > 0 ){
			printf("  You've just put: %2.2f zl.\n", priceToFloat(x));
			printf("  To be paid remains: %2.2f zl.\n", priceToFloat(atp));
		}
		return true;
	}
	return false;
}

bool coins::isPaid(int atp){
	if(atp == 0 ){
		cout << "  Product purchased." << endl;
		return true;
	}
	return false;
}

void coins::printNotification2(){
	cout << "  Acceptable coins: 10gr, 20gr, 50gr, 1zl, 2zl, 5zl. Enter how much you are tossing." << endl;
	cout << "  Type amount without unit, eg 20=20gr, 2=2zl, etc..." << endl;
}

string coins::name() const{
	return "Cash (coins)";
}