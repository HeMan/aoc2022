#include <iostream>
#include <thread>
#include <set>

#include "getinput.h"

using namespace std;

#define SIZE 98

extern "C" void app_main(void)
{
	vector<string> inputlines;
	inputlines = getlines();
	set<pair<uint16_t, uint16_t>> found;
	uint16_t x, y;
	for (y = 0; y <= SIZE; y++) {
		char hl = inputlines[y][0];
		found.insert(make_pair(y,0));
		for (x=0; x <= SIZE; x++) {
			if (inputlines[y][x] > hl) {
				hl=inputlines[y][x];
				found.insert(make_pair(y,x));
			}
		}
	}
	for (y = 0; y <= SIZE; y++) {
		char hl = inputlines[y][SIZE];
		found.insert(make_pair(y,SIZE));
		for (x=SIZE+1; x-- > 0;) {
			if (inputlines[y][x] > hl) {
				hl=inputlines[y][x];
				found.insert(make_pair(y,x));
			}
		}
	}
	for (x = 0; x <= SIZE; x++) {
		char hl = inputlines[0][x];
		found.insert(make_pair(0,x));
		for (y=0; y <= SIZE; y++) {
			if (inputlines[y][x] > hl) {
				hl=inputlines[y][x];
				found.insert(make_pair(y,x));
			}
		}
	}
	for (x = 0; x <= SIZE; x++) {
		char hl = inputlines[SIZE][x];
		found.insert(make_pair(SIZE,x));
		for (y=SIZE+1; y-- > 0;) {
			if (inputlines[y][x] > hl) {
				hl=inputlines[y][x];
				found.insert(make_pair(y,x));
			}
		}
	}
	while (true) {

		cout << "Part 1: " << found.size() << endl;
		this_thread::sleep_for(chrono::seconds(1));
	}
}
