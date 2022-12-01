#include <iostream>
#include <thread>
#include <vector>
#include <istream>
#include "part1.h"
#include "esp_log.h"
#include "sdkconfig.h"

#include "getinput.h"


static const char* TAG = "AoC";

extern "C" void app_main(void)
{
	ESP_LOGI(TAG, "Day 01");

	while (true) {
		auto lines = getlines();
		std::cout << "The elf with the most calories has " << part1(lines) << "\n";

		std::this_thread::sleep_for(std::chrono::seconds(1));
	}
}
