#include <stdio.h>
#include <iostream>
#include <random>
#include "TestCase.h"
using namespace std;


int main(void)
{
	srand(time_t(NULL));
	char c;
	std::cout << "Do you want to generate data Randomly?(y/n/d)" << std::endl;
	std::cout << "d: For default Test case as provided in question." << std::endl;
	std::cout << "Note: Else you will have to enter each data N times manually." << std::endl;
	std::cin >> c;

	switch (c)
	{
	case 'd':
	case 'D': DefaultTestCase(); break;
	case 'y':
	case 'Y': TestCaseRandom(); break;
	case 'n':
	case 'N': TestCaseUserDefined(); break;
	default: std::cout << "Enter y/n only.";
		break;
	}
}