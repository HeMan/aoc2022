#include <iostream>
#include <thread>
#include "getinput.h"


using std::cout;
using std::endl;

extern "C" void app_main(void)
{
	std::vector<std::string> inputlines;
	inputlines = getlines();
	while (true) {

		std::cout << inputlines.size() << std::endl;
		cout << "Hello world day02" << endl;
		std::this_thread::sleep_for(std::chrono::seconds(1));
	}
}
