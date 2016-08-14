#ifndef MURLOC
#define MURLOC
#include <iostream>
#include <fstream>
#include <sstream>
#include <map>

class Murlocs {
	private:
		std::map<std::string, int> jobs;
	public:
		Murlocs();
		void increment_job(std::string job, int number);
};

int quick_murloc_calculation (int leaders, int chargers);
int quick_murloc_total (int leaders, int chargers);
void quick_murloc_damage ();

int wild_murloc_total ();
void wild_murloc_damage (Murlocs &murlocs);

void read_murloc_list (Murlocs &murlocs);
#endif