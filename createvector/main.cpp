#include <iostream>
#include <iterator>
#include <vector>
#include <fstream>
#include <istream>

using namespace std;
int main(int argc, char** argv) {
	string line;
	ifstream inputfile;
	ofstream outputfile;

	if (argc != 3) {
		cout << "Wrong number of arguments" << endl;
		return 1;
	}

  inputfile.open(argv[1]);
	if (!inputfile.is_open()) {
    cerr << "Failed to open input file." << endl;
    return 1;
  }

	outputfile.open(argv[2]);
	if (!outputfile.is_open()) {
		cerr << "Failed to open output file." << endl;
		return 1;
	}

	outputfile << "#include <vector>" << endl;
	outputfile << "#include <string>" << endl;
	outputfile << "std::vector<std::string> inputfile = {";
	while (std::getline(inputfile, line)) {
		outputfile << "\"" << line << "\",";
	}
	outputfile << "};\n" << endl;
}
