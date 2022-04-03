#include "blik.h"

bool blik::pay(int x ){
	string pin;
	int y = 1; 
	do {
		cout << "  Please enter six-digit Blik code:" << endl;
        pin = readPIN();
		if( !isCorrectPIN(pin, PINlen ) ){
			cout << "  Incorrect Blik code. Please try again." << endl;
			continue;
		}
		cout << "  Confirm transaction in yours bank mobile app." << endl
			<< "  1: **Confirm.**" << endl
			<< "  0: Abort." << endl;

		y = readInt();
		if( !y ) { continue; }
		
		cout << "  Transaction confirmed." << endl << endl;
		return true;

	} while( y != 0 );
	return false;
}

string blik::name() const{
	return "Blik";
}