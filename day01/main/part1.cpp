#include <algorithm>
#include <numeric>
#include <ranges>

uint32_t part1(std::vector<std::string> lines)
{
	std::string delimiter {""};
	auto sumelf = [](auto v) {
		auto values = v | std::views::transform([](auto w) { return std::stoi(w); }) | std::views::common;
		return std::accumulate(values.begin(), values.end(), 0);
	};
	auto top = (lines | std::views::split(delimiter) | std::views::transform(sumelf) | std::views::common);
	return std::ranges::max(top);

}

