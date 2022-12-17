#include <iostream>
#include <iterator>
#include <thread>

#include <set>
#include "getinput.h"

using namespace std;

using Point = pair<int16_t, int16_t>;
struct Rope {
    Point head, tail;
    set<Point> tail_visited;

    Rope() { tail_visited.insert(make_pair(0,0)); };

    void move(string line) {
        int8_t updown=0, leftright=0;
        char direction=line[0];
        uint8_t distance=stoi(line.substr(2));

        if (direction == 'U')
            updown = 1;
        else if (direction == 'D')
            updown = -1;
        else if (direction == 'L')
            leftright = -1;
        else if (direction == 'R')
            leftright = 1;

        for (auto i=0; i<distance; i++) {
            auto prev = head;
            head.first += updown;
            head.second += leftright;
            if  (abs(head.first-tail.first)>1 or abs(head.second-tail.second)>1) {
                tail = prev;
                tail_visited.insert(tail);
            }
        }
    };

    uint32_t total_positions() {
        return tail_visited.size();
    }
};

extern "C" void app_main(void)
{
	Rope rope;
	string line;
	while (true) {
		while (std::getline(inputstream, line)) {
			rope.move(line);
		}
		cout << "Part 1: " << rope.total_positions() << endl;
		std::this_thread::sleep_for(std::chrono::seconds(1));
	}
}
