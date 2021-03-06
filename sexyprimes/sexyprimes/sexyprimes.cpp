// sexyprimes.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <string>
#include <set>

bool is_prime(int n) {
	for (int i = 2; i < n; i++) {
		if (n % i == 0) return false;
	}
	return true;
}

int main(int argc, const char **argv)
{
	if (argc != 2) {
		std::cout << "Requires an integer argument" << std::endl;
		return(1);
	 }
	int a = std::stoi(argv[1]);
	std::set<int> primes;
	std::set<std::pair<int, int>> sexy_primes;
	for (int i = 2; i <= a; i++) {
		if (is_prime(i))
			primes.insert(i);
	}
	for (auto prime : primes) {
		if (primes.count(prime + 6))
			sexy_primes.insert(std::pair<int, int>(prime, prime + 6));
	}
	int counter = 0;
	for (auto sexy : sexy_primes) {
		counter++;
		std::cout << "(" << sexy.first << "," << sexy.second << ")";
		if (counter % 4 == 0)
			std::cout << std::endl;
		else if (counter != sexy_primes.size()) {
			std::cout << ", ";
		}
	}
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
