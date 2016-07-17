#include "atoi.h"

int atoiClass::myAtoi(std::string number) {
	int result = 0;
	int sign = 1;
	int i = 0;
	if (number[i] == '-') {
		sign *= -1;
		i++;
	}
	for (; i < number.size(); i++) {
		int digit = number[i] - '0';
		result = result * 10 + digit;
	}
	return sign * result;
}

void atoiClass::runClass() {
	std::string escapeKey = "exit";
	std::string value;
	bool run = true;
	while(run) {
		std::cout << "type in a number or " << escapeKey << " to escape:" << std::endl;
		std::cin >> value;
		if (value == escapeKey) {
			run = false;
		} else {
			std::cout << myAtoi(value) << std::endl;
		}
	}
}