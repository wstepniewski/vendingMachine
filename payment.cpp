#include "payment.h"
#include <iostream>
#include <string>
using namespace std;

string payment::readPIN(){
	string line;
	getline( cin, line );
	return line;
}

bool payment::isCorrectPIN(string PIN, int len ){
	int length = PIN.length();

	if(length != len ){
		return false;
	}
	for( int i = 0; i < len; i++ ){
		if( ( PIN[i] < '0' ) || ( PIN[i] > '9' ) ){
			return false;
		}
	}
	return true;
}