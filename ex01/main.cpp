#include <iostream>
#include <string>
#include "iter.hpp"

template <typename T>
void print(const T& x)
{
	std::cout << x << std::endl;
}


void increment(int& x)
{
	++x;
}

int main()
{
	// 1) Tableau d'int : print
	int numbers[] = {1, 2, 3, 4, 5};
	size_t n_len = sizeof(numbers) / sizeof(numbers[0]);

	std::cout << "Print int array:" << std::endl;
	iter(numbers, n_len, print<int>);

	// 2) Tableau d'int : modify
	std::cout << "\nIncrement int array:" << std::endl;
	iter(numbers, n_len, increment);

	std::cout << "After increment:" << std::endl;
	iter(numbers, n_len, print<int>);

	// 3) Tableau de string : print
	std::string words[] = {"chaine1", "chaine2", "chaine3"};
	size_t w_len = sizeof(words) / sizeof(words[0]);

	std::cout << "\nPrint string array:" << std::endl;
	iter(words, w_len, print<std::string>);

	// 4) Tableau const : print (doit appeler la surcharge const)
	const int const_numbers[] = {10, 20, 30};
	size_t c_len = sizeof(const_numbers) / sizeof(const_numbers[0]);

	std::cout << "\nPrint const int array:" << std::endl;
	iter(const_numbers, c_len, print<int>);

	return 0;
}
