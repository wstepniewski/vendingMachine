#include "card.h"

bool card::pay(int x){
	string kod;
	int y;
	do {
		cout << "  Approach the card to the reader:" << endl
			<< "  1: **Approach.**" << endl
			<< "  0: Abort." << endl;

		y = readInt();
		if( !y ) { continue; }

		cout << "  Please confirm transaction with four-digit PIN number." << endl;
		kod = readPIN();
		if( !isCorrectPIN( kod, PINlen ) ){
			cout << "  Incorrect PIN code. Please try again." << endl;
			continue; 
		}
		cout << "  Transaction accepted." << endl << endl;
		return true;
	
	} while( y != 0 );
	return false;
}

string card::name() const{
	return "Payment card";
}