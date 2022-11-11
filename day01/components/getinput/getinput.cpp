#include <iostream>
#include <vector>
#include <sstream>


std::vector<std::string> getlines(void) {
	extern const unsigned char input_start[] asm("_binary_input_txt_start");
	extern const unsigned char input_end[] asm("_binary_input_txt_end");
	std::stringstream st(std::string(input_start, input_end-1));

	std::vector<std::string> retval;
	std::string line;
	while (std::getline(st, line)) {
		retval.push_back(line);
	}

	return retval;
}

