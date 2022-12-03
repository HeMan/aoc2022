#include <iostream>
#include <map>
#include <numeric>
#include <thread>

#include "getinput.h"

using std::cout;
using std::endl;

std::map<std::string, int> scoremap_part1{
	{"A X", 4}, {"A Y", 8}, {"A Z", 3},
	{"B X", 1}, {"B Y", 5}, {"B Z", 9},
	{"C X", 7}, {"C Y", 2}, {"C Z", 6},
};


std::map<std::string, int> scoremap_part2{
	{"A X", 3}, {"A Y", 4}, {"A Z", 8},
	{"B X", 1}, {"B Y", 5}, {"B Z", 9},
	{"C X", 2}, {"C Y", 6}, {"C Z", 7},
};

extern "C" void app_main(void) {
	std::vector<std::string> inputlines;
	uint32_t part1, part2 = 0;

	inputlines = getlines();
	while (true) {
		part1 = std::transform_reduce(inputlines.begin(), inputlines.end(), 0,
																	std::plus{}, [](auto v) { return scoremap_part1[v]; });

		part2 = std::transform_reduce(inputlines.begin(), inputlines.end(), 0,
																	std::plus{}, [](auto v) { return scoremap_part2[v]; });
		cout << "Score in part 1 " << part1 << endl;
		cout << "Score in part 2 " << part2 << endl;
		std::this_thread::sleep_for(std::chrono::seconds(1));
	}
}
