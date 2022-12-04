#include <algorithm>
#include <iostream>
#include <thread>
#include <ranges>
#include <set>
#include <sstream>
#include <utility>
//#include <vector>
#include "getinput.h"


using namespace std;

set<uint32_t> setit(string in){
    auto index = in.find("-");
    
    auto ra = views::iota(stoi(in.substr(0,index)), stoi(in.substr(index+1))+1);
    return set<uint32_t>(ra.begin(), ra.end());

}
bool fulloverlap(string line) { 
    pair<set<uint32_t>, set<uint32_t>> sset;
    set<uint32_t> ol; 
    auto index = line.find(",");
    sset = make_pair(setit(line.substr(0, index)), setit(line.substr(index+1)));
    set_intersection(sset.first.begin(), sset.first.end(), sset.second.begin(), sset.second.end(), inserter(ol, ol.end()));
    
    return min(sset.first.size(),sset.second.size()) == ol.size(); 
}

bool overlapsome(string line) { 
    pair<set<uint32_t>, set<uint32_t>> sset;
    set<uint32_t> ol; 
    auto index = line.find(",");
    sset = make_pair(setit(line.substr(0, index)), setit(line.substr(index+1)));
    set_intersection(sset.first.begin(), sset.first.end(), sset.second.begin(), sset.second.end(), inserter(ol, ol.end()));
    
    return ol.size() > 0; 
}

extern "C" void app_main(void)
{
	vector<string> inputlines;
	inputlines = getlines();

	while (true) {
    cout << "Result part 1: " << ranges::count_if(inputlines, fulloverlap) << endl;
    cout << "Result part 2: " << ranges::count_if(inputlines, overlapsome) << endl;

		this_thread::sleep_for(chrono::seconds(1));
	}
}
