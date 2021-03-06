// validisbn.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>


using namespace std;

int main()
{
	string isbn;
	while ( true ) {
		cout << "Enter ISBN-10, quit to quit:";
		cin >> isbn;
		if ( isbn == "quit" )
			break;
		if ( isbn.size() != 10 ) {
			cerr << "Must be of length 10" << endl;
			continue;
		}
		int s = 0;
		try {
			for ( int i = 0; i < isbn.size(); i++ ) {
				int val;
				if ( isbn[i] == 'X' ) val = 10;
				else val = stoi( isbn.substr( i, 1 ) );
				s += (10 - i) * val;
			}
			if ( s % 11 != 0 ) {
				cerr << "Incorrect ISBN!" << endl;
			}
			else {
				cout << "Correct ISBN!" << endl;
			}
		}
		catch ( ... )
		{
			cerr << "Invalid character in string, please fix and try again, only digits allowed in the first nine positions and digit or X at position 10" << endl;
			continue;
		}
	}
	
    return 0;
}

