#include <iostream>
#include <string>
#include "Array.hpp"

int main()
{
	// 1) Default constructor
	Array<int> empty;
	std::cout << "empty.size() = " << empty.size() << std::endl;

	// 2) Sized constructor (default/value initialization)
	Array<int> a(5);
	std::cout << "a.size() = " << a.size() << std::endl;
	std::cout << "a initial values:" << std::endl;
	for (unsigned int i = 0; i < a.size(); ++i)
		std::cout << "a[" << i << "] = " << a[i] << std::endl;

	// Modify values
	for (unsigned int i = 0; i < a.size(); ++i)
		a[i] = static_cast<int>(i) * 10;

	std::cout << "\na after modifications:" << std::endl;
	for (unsigned int i = 0; i < a.size(); ++i)
		std::cout << "a[" << i << "] = " << a[i] << std::endl;

	// 3) Copy constructor (deep copy)
	Array<int> b(a);
	b[0] = 999;
	std::cout << "\nAfter copying to b and changing b[0]:" << std::endl;
	std::cout << "a[0] = " << a[0] << " (should NOT be 999)" << std::endl;
	std::cout << "b[0] = " << b[0] << std::endl;

	// 4) Assignment operator (deep copy)
	Array<std::string> s1(3);
	s1[0] = "hello";
	s1[1] = "cpp";
	s1[2] = "42";

	Array<std::string> s2;
	s2 = s1;
	s2[1] = "module07";

	std::cout << "\nAssignment deep copy test:" << std::endl;
	std::cout << "s1[1] = " << s1[1] << " (should be cpp)" << std::endl;
	std::cout << "s2[1] = " << s2[1] << " (should be module07)" << std::endl;

	// 5) Const access
	const Array<int> ca(a);
	std::cout << "\nconst access ca[2] = " << ca[2] << std::endl;

	// 6) Out of bounds
	std::cout << "\nOut of bounds test:" << std::endl;
	try
	{
		std::cout << a[42] << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << "Caught exception: " << e.what() << std::endl;
	}

	return 0;
}
