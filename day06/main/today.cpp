#include <iostream>
#include <thread>
#include <set>
#include "getinput.h"

using namespace std;

uint16_t nwaycompare(string in, uint16_t s)
{
    uint16_t i;
    for (i=s; i<in.size(); i++) {
        const string sub = in.substr(i-s,s);
        const set<char> chs (sub.begin(), sub.end());
        if (chs.size() == s)
            break;
    }
    return i;
}


extern "C" void app_main(void)
{
    const vector<string> inputlines = getlines();
    const string firstline = inputlines.front();
    while (true) {
        cout << "Part 1: " << nwaycompare(firstline, 4) << endl;
        cout << "Part 2: " << nwaycompare(firstline, 14) << endl;
        this_thread::sleep_for(chrono::seconds(1));
    }
}
