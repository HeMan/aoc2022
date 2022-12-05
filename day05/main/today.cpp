#include <algorithm>
#include <deque>
#include <iostream>
#include <ranges>
#include <thread>
#include <vector>
#include <regex>

#include "getinput.h"

using namespace std;

regex reg("move (\\d*) from (\\d*) to (\\d*)");

struct Crates {
  array<deque<char>, 9> stacks;

  void push(char crate, uint8_t stck) { this->stacks[stck].push_back(crate); }


  void move(uint8_t amount, uint8_t from, uint8_t to) {
    for (int a = 0; a < amount; a++) {
      if (!this->stacks[from-1].empty()) {
        auto f = this->stacks[from-1].front();
        this->stacks[to-1].push_front(f);
        this->stacks[from-1].pop_front();
      }
    }
  }

  void move2(uint8_t amount, uint8_t from, uint8_t to) {
    deque<char> tempstack;
    for (int a = 0; a < amount; a++) {
      if (!this->stacks[from-1].empty()) {
        auto f = this->stacks[from-1].front();
        tempstack.push_front(f);
        this->stacks[from-1].pop_front();
      }
    }
    for (int a = 0; a < amount; a++) {
      auto f = tempstack.front();
      this->stacks[to-1].push_front(f);
      tempstack.pop_front();
    }
  }

  void parseline(auto line, auto part) {
    if ((line[1] == '1') or (line == "")) return;
    if (line.starts_with("move")) {
      smatch matches;
      if (regex_match(line, matches, reg)) {
        if (part == 1) {
          this->move(stoi(matches[1]), stoi(matches[2]), stoi(matches[3]));
        } else {
          this->move2(stoi(matches[1]), stoi(matches[2]), stoi(matches[3]));
        }
      }
    } else {
      for (uint16_t i = 0; i < (line.size() + 1) / 4; i++) {
        if (line[(i * 4) + 1] != ' ') {
          this->push(line[(i * 4) + 1], i);
        }
      }
    }
  }
};

extern "C" void app_main(void) {
  const auto inputlines = getlines();
  const string delimiter{""};
  Crates crates,crates2;
  for (auto l : inputlines) {
    crates.parseline(l,1);
    crates2.parseline(l,2);
  }
  while (true) {
    cout << "Part 1: ";
    for (auto s : crates.stacks)
      cout << s.front();
    cout << endl;
    cout << "Part 2: ";
    for (auto s : crates2.stacks)
      cout << s.front();
    cout << endl;
    this_thread::sleep_for(chrono::seconds(1));
  }
}
