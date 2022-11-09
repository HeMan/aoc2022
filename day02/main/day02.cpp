#include <iostream>
#include <thread>

using std::cout;
using std::endl;

extern "C" void app_main(void)
{
	while (true) {

		cout << "Hello world day02" << endl;
		std::this_thread::sleep_for(std::chrono::seconds(1));
	}
}
