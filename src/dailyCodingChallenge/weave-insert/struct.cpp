#include <iostream>

using namespace std;

struct test {
	void demo() {
		std::cout << "this is a demo function" << std::endl;
	}
};

int main() {
	test a;
	a.demo();
	return 0;
}