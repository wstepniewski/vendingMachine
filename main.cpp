#include <iostream>
#include <fstream>
#include "drink.h"
#include "vending_machine.h"
#include "blik.h"
#include "card.h"
#include "coins.h"
using namespace std;
#define AUTO1 // preprocessor const variable used to program auto execute

int main( int argc, char *argv[] )
{
#ifdef AUTO // if you defined   AUTO   program will execute automatically
	ifstream file;
	if( argc == 2 ){
		file.open( "stdin.txt" );
		cin.rdbuf( file.rdbuf() );
	}
#endif //AUTO

	drink dr0(0, "Coca Cola", 2.0 );
	drink dr1(1, "Pepsi", 3.7 );
	drink dr2(2, "Sprite", 610 );
	drink dr3(3, "Sparkling water", 1000 );
	drink *drinks[] = {&dr0, &dr1, &dr2, &dr3 };
	
	blik BLIK;
	card CARD;
	coins COINS;
	payment *payments[] = {&COINS, &BLIK, &CARD };

	const int nDrinks = *(&drinks + 1) - drinks;
	const int nPayments = *(&payments + 1) - payments;

	vending_machine vm(nDrinks, drinks, nPayments, payments );
	payment *payment;
	drink *drink;
	int choice;
	int secondChoice;
	
	do {
        vm.printDrinks();
		choice = readInt();
		drink = vm.chooseDrink(choice);
		if( !drink ) { continue; }

		do {
            vm.printPayments();
			secondChoice = readInt();

			try{
				payment = vm.choosePayment(secondChoice);
			}
			catch( ERROR_fatal_value ) { continue; }
			catch( ERROR_incorrect_value ){
				cout << "  Please, choose number in range 0-" << nPayments << endl;
				continue;
			}

			int atp = vending_machine::getPrice(drink ); // atp = amount to pay

			if( !payment->pay(atp) ){
				break;
			}

            vm.updateStock(drink);
			secondChoice = 0;
		} while( secondChoice != 0 );
		//system( "cls" );
	} while( choice != 0 );
	
	return 1;
}