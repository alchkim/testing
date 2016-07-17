#include "mainfunc.h"

int hanoiClass::myHanoi (int levels) {
	return 1;
};

void hanoiClass::runClass () {
	int levels;
	std::cout << "Find out how many steps it takes to move the tower of Hanoi! Type in the number of levels: " << std::endl;
	std::cin >> levels;
	std::cout << levels;
};