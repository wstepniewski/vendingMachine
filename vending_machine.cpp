#include "vending_machine.h"

vending_machine::vending_machine(int nDrinks, drink *pDrinks[], int nPayments, payment* pPayments[] ){
	n = nDrinks;
	for( int i = 0; i < n; i++ ){
		drinks.add(pDrinks[i] );
		quantity.push_back( 3 );
	}
	m = nPayments;
	for( int i = 0; i < m; i++ ){
		payments.add(pPayments[i] );
	}
}

void vending_machine::printDrinks() const{
	cout << "######################################################" << endl;
	cout << "  Please choose your drink:" << endl;
	for( int i = 0; i < n; i++ ){
        printDrink(drinks[i]);
	}
	cout << "  If you want to move back press 0 or any other key." << endl;
	cout << "######################################################" << endl;
}

drink *vending_machine::chooseDrink(int choice ){
	if( choice == 0 ){
		cout << "  Thank you and see you again!" << endl;
		return nullptr;
	}
	if( choice < 0 || choice > n ){
	    cout << "  Please, choose number in range 0-" << n << endl;
		return nullptr;
	}
	if( quantity[choice - 1] <= 0 ){
		cout << "  Product unavailable, please choose another." << endl;
		return nullptr;
	}
    printNotification1(drinks[choice - 1]);
	return drinks[choice - 1];
}

void vending_machine::printDrink(drink *x ) const {
	printf("  %d:  %2.2f\t%-20s qty: %d", x->id+1, priceToFloat(x->price), x->name.c_str(), quantity[x->id]);
	if( quantity[x->id] == 0 ){
		printf(", product unavailable");
	}
	printf("\n");
}

void vending_machine::printNotification1(drink *x ){
    printf("  You've choose drink no: %d, %s, please pay: %2.2f zl.\n\n", x->id + 1, x->name.c_str(), priceToFloat(x->price));
}

payment* vending_machine::choosePayment(int choice ){
	if( choice == 0 ) {
		ERROR_fatal_value exit;
		throw exit;
	}
	
	if( choice < 0 || choice > m ){
		ERROR_incorrect_value repeat;
		throw repeat;
	}
	return payments[choice - 1];
}

void vending_machine::printPayments() const{
	cout << "  Choose your payment method:" << endl;
	for( int i = 0; i < m; i++ ){
		cout << "  " << i + 1 << ": " << payments[i]->name() << endl;
	}
	cout << "  If you want to move back press 0 or any other key." << endl;
}

void vending_machine::updateStock(drink* dr){
	quantity[dr->id]--;
}