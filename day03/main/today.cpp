#include <iostream>
#include <iterator>
#include <numeric>
#include <ranges>
#include <set>
#include <thread>

#include "getinput.h"

auto icv = [](auto c) {
  if (isupper(c)) {
    return c - 38;
  } else {
    return c - 96;
  }
};

auto part1(auto input) {
  auto halfsetify = [](auto i, auto s) {
    auto subs = i.substr((s * i.size()) / 2, i.size() / (2 - s));
    return std::set<char>(subs.begin(), subs.end());
  };
  auto setit = [halfsetify](auto l) {
    auto first = halfsetify(l, 0);
    auto second = halfsetify(l, 1);
    char inter;
    std::set_intersection(first.begin(), first.end(), second.begin(),
                          second.end(), &inter);
    return inter;
  };
  auto rucksacks =
      input | std::views::transform(setit) | std::views::transform(icv);
  return std::accumulate(rucksacks.begin(), rucksacks.end(), 0);
}

auto part2(auto input) {
  std::vector<char> badges;
  for (uint16_t i = 0; i <= input.size() - 2; i += 3) {
    auto first = std::set<char>(input[i].begin(), input[i].end());
    auto second = std::set<char>(input[i + 1].begin(), input[i + 1].end());
    auto third = std::set<char>(input[i + 2].begin(), input[i + 2].end());
    std::set<char> inter_set;
    char inter;
    std::set_intersection(first.begin(), first.end(), second.begin(),
                          second.end(),
                          std::inserter(inter_set, inter_set.end()));
    std::set_intersection(third.begin(), third.end(), inter_set.begin(),
                          inter_set.end(), &inter);
    badges.push_back(inter);
  }
  auto prios = badges | std::views::transform(icv);
  return std::accumulate(prios.begin(), prios.end(), 0);
}

extern "C" void app_main(void) {
  std::vector<std::string> inputlines;
  inputlines = getlines();
  while (true) {
    std::cout << "Part 1 prio is " << part1(inputlines) << std::endl;
    std::cout << "Part 2 prio is " << part2(inputlines) << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(1));
  }
}
