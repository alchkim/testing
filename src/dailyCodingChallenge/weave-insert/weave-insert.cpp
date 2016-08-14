#include <iostream>
#include <fstream>
#include <string>
#include <regex>
#include <vector>

using namespace std;

vector<string> gen_arrays(ifstream &infile) {
	vector<string> array;
	string elem;
	cout << "HELLO" << endl;
	regex space("\\s+");
	while(infile >> elem) {
		cout << elem << endl;
		if (regex_match(elem, space)) {
			break;
		} else {
			array.push_back(elem);
		}
	}
	return array;
}

void weave(ifstream &infile) {
	vector<string> a = gen_arrays(infile);
};

void bracket(ifstream &infile) {
	
};

void weave_insert(string filename) {
	ifstream infile;
	infile.open(filename.c_str());
	string type;
	infile >> type;
	if (type == "Bracket") {
		bracket(infile);
	} else if (type == "Weave") {
		weave(infile);
	} else {
		cout << "Not a valid type" << endl;
	}
	infile.close();
};

int main(int argc, char* argv[]) {
	for (int i=1; i<argc; ++i) {
		weave_insert(argv[i]);
	}
	return 0;
}