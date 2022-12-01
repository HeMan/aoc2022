#include <algorithm>
#include <iostream>
#include <istream>
#include <numeric>
#include <ranges>
#include <thread>
#include <vector>
#include "esp_log.h"
#include "sdkconfig.h"

#include "getinput.h"


static const char* TAG = "AoC";

extern "C" void app_main(void)
{
	ESP_LOGI(TAG, "Day 01");
	auto sumelf = [](auto v) {
		auto values = v | std::views::transform([](auto w) { return std::stoi(w); }) | std::views::common;
		return std::accumulate(values.begin(), values.end(), 0);
	};

	auto lines = getlines();
	std::string delimiter {""};

	while (true) {
		auto kcals_view = lines | std::views::split(delimiter) | std::views::transform(sumelf) | std::views::common;
		auto kcals = std::vector<uint32_t>(kcals_view.begin(), kcals_view.end());
		std::ranges::sort(kcals, std::ranges::greater{});
		std::cout << "The elf with the most calories has " << kcals.front() << "\n";

		std::cout << "The three elves with the most calories has " << std::accumulate(kcals.begin(), kcals.begin()+3,0) << "\n";

		std::this_thread::sleep_for(std::chrono::seconds(1));
	}
}
