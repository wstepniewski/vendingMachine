#ifndef CONTAINER_H
#define CONTAINER_H
#include <iostream>
using namespace std;

template <typename T>
class container
{
public:
	void add( T item ){
		nSize++;
		T *newTab = new T[nSize];
		for( int i = 0; i < nSize - 1; i++ ){
			newTab[i] = tab[i];
		}
		delete[] tab;
		tab = newTab;
		tab[nSize - 1] = item;
	}

	T &operator[]( int index )const{
		if( index >= nSize || index < 0 ){
			cout << "Index out of range\n";
			exit( 0 );
		}
		return tab[index];
	}
	
private:
	int nSize = 0;
	T *tab = nullptr;
};

#endif