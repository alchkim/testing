#include "murloc.h"
#define CHARGE 2
#define LEADER 3
#define BUFF 2

//If job is present in jobs, increments value by number, otherwise, adds job to jobs
void Murlocs::increment_job (std::string job, int number) {
	if (jobs.find(job) != jobs.end()) {
		jobs[job] += number;
	} else {
		jobs[job] = 1;
	}
};

//Calculates the immediate damage available based on # of leaders and # of chargers
int quick_murloc_calculation (int leaders, int chargers) {
	return chargers*(CHARGE+(BUFF*leaders));
};

//Prints out the attack and health of each leader and charger. Then prints out total
//attack on board.
int quick_murloc_total (int leaders, int chargers) {
	for (int i=0; i<leaders+chargers; ++i) {

	}
	return chargers*(CHARGE+(CHARGE*leaders)+leaders*(LEADER+(leaders-1));
};

//Asks user how many leaders and chargers do they have and prints out the immediate damage
//they can do.
void quick_murloc_damage () {
	std::cout << "How many leaders: \n";
	int leaders;
	std::cin >> leaders;
	std::cout << "How many chargers: \n";
	int chargers;
	std::cin >> chargers;
	std::cout << "You have " << quick_murloc_calculation(leaders, chargers) << " charge damage.\n";
};

//
int wild_murloc_total () {
	return 1;
};

void wild_murloc_damage (Murlocs &murlocs) {

};

void read_murloc_list (Murlocs &murlocs) {
	std::cout << "Type in the text file's name: \n";
	std::string filename;
	std::cin >> filename;
	filename.append(".txt");
	std::ifstream textfile (filename.c_str());
	
	if (textfile.is_open()) {
		std::string line;
		while (std::getline(textfile, line)) {
			std::string job;
			int number;
			std::istringstream iss(line);
			iss >> job >> number;
			murlocs.increment_job(job, number);
		}
	} else {
		std::cout << filename+" was unable to be opened.\n";
	}
}