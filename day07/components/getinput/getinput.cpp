#include <iostream>
#include <vector>
#include <sstream>


extern const unsigned char input_start[] asm("_binary_input_txt_start");
extern const unsigned char input_end[] asm("_binary_input_txt_end");
std::istringstream inputstream(std::string(input_start, input_end-1));

std::vector<std::string> getlines(void) {
	std::vector<std::string> retval;
	std::string line;

	while (std::getline(inputstream, line)) {
		retval.push_back(line);
	}

	return retval;
}

