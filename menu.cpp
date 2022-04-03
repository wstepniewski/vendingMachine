#include "menu.h"
#include <iostream>
using namespace std;

float priceToFloat(int x ){
	float f = static_cast< float >( x ) / 100;
	return f;
}

int readInt(){
	string line;
	getline( cin, line );
	return atoi( line.c_str() );
}