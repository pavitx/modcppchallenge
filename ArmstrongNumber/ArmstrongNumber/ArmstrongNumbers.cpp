// ArmstrongNumber.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <set>
#include <iostream>

using namespace std;

int main()
{
	set<int> armstrong;
	for ( int i = 0; i < 1000; i++ )
	{
		int current = i;
		int centenes = current / 100;
		current -= 100 * centenes;
		int desenes = current / 10;
		// aixo son les unitats
		current -= 10 * desenes;
		int cubed = centenes * centenes * centenes + desenes * desenes * desenes + current * current * current;
		if ( cubed == i )
		{
			armstrong.insert( i );
		}
	}
	int index = 0;
	for ( auto arm : armstrong )
	{
		cout << arm;
		index++;
		if ( index % 10 == 0 || index == armstrong.size() ) cout << endl;
		else cout << " ";
	}

	
    return 0;
}

