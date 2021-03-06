// primefactors.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>

using namespace std;

int main()
{
	vector<int> primes;
	vector<int> prime_factors;
	int previous_upper_limit = -1;
	int n;
	while ( true ) {
		cout << "Enter number, -1 to exit:";
		cin >> n;
		if ( n == -1 )
			break;
		
		// find the prime numbers till n
		int lower_limit;
		if ( primes.empty() )
			lower_limit = 2;
		else if (previous_upper_limit != -1) {
			lower_limit = previous_upper_limit;
		}
		if ( lower_limit < n )
			cout << "Obtenint els nombres primers des de " << lower_limit << " fins a " << n << endl;
		for ( int i = lower_limit; i <= n; i++ ) {
			bool is_prime = true;
			if ( primes.empty() ) {
				for ( int j = 2; j < i; j++ )
					if ( i % j == 0 ) {
						is_prime = false;
						break;
					}
			}
			else {
				for ( auto prime : primes ) {
					if ( i % prime == 0 ) {
						is_prime = false;
						break;
					}
						
					
				}
			}
			if ( is_prime )
				primes.emplace_back( i );
		}
		int current = n;
		for ( auto prime : primes ) {
			while ( current % prime == 0 ) {
				prime_factors.emplace_back( prime );
				current /= prime;
			}

				
		}
		cout << n << " = ";
		for ( unsigned int i = 0; i < prime_factors.size(); i++ ) {
			cout << prime_factors[i];
			if ( i != prime_factors.size() - 1 )
				cout << ".";
			else cout << endl;
		}
		prime_factors.clear();
		if (n > previous_upper_limit) previous_upper_limit = n;
	}
    return 0;
}

