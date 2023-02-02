#include <string>
#include <vector>
#include <iostream>
#include <sstream>

#include "ulliststr.h"

//Use this file to test your ulliststr implementation before running the test suite

int main(int argc, char* argv[])
{
	ULListStr dat;
	dat.push_back("7");
	dat.push_front("8");
	dat.push_back("9");
	dat.push_back("9");
	dat.push_back("9");
	dat.push_back("9");
	dat.push_back("9");
	dat.push_back("9");
	dat.push_back("9");
	dat.push_back("9");
	dat.push_back("9");
	dat.push_back("1");
	std::cout << dat.get(0) << " " << dat.get(1) << " " << dat.get(2) << " " <<
	dat.get(3) << " " << dat.get(4) << " " << dat.get(5) << " " <<
	dat.get(6) << " " << dat.get(7) << " " << dat.get(8) <<  " " <<
	dat.get(9) << " " << dat.get(10) << " " << dat.get(10) << std::endl;
	// prints: 8 7 9
	std::cout << dat.size() << std::endl;  // prints 3 since there are 3 strings stored
}
