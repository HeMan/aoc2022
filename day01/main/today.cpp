#include <iostream>
#include <thread>
#include <vector>
#include "getinput.h"

extern "C" void app_main(void)
{
	std::vector<std::string> inputlines;
	inputlines = getlines();
	while (true) {

		for (auto l: inputlines) {
			std::cout << l << std::endl;
		}
		std::cout << inputlines.size() << std::endl;

		std::cout << "Hello world day 01" << std::endl;
		std::this_thread::sleep_for(std::chrono::seconds(1));
	}
}
