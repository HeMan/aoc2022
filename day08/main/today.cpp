#include <algorithm>
#include <iostream>
#include <map>
#include <ranges>
#include <set>
#include <thread>

#include "getinput.h"

using namespace std;
#define datasize uint8_t
using Point = pair<datasize, datasize>;

#define SIZE 99

extern const unsigned char input_start[] asm("_binary_input_txt_start");
extern const unsigned char input_end[] asm("_binary_input_txt_end");

int part1(){
    istringstream inputstream(string(input_start, input_end-1));
	  string line;

    set<Point> found;
    datasize x, y;
    y=0;
	  while (std::getline(inputstream, line)) {
        char hl = line[0];
        found.insert(make_pair(y,0));
        for (x=0; x < SIZE; x++) {
            if (line[x] > hl) {
                hl=line[x];
                found.insert(make_pair(y,x));
            }
        }
        y++;
    }

    y=0;
    inputstream.clear();
    inputstream.seekg(0, ios::beg);
	  while (std::getline(inputstream, line)) {
        char hl = line[SIZE-1];
        found.insert(make_pair(y,SIZE-1));
        for (x=SIZE; x-- > 0;) {
            if (line[x] > hl) {
                hl=line[x];
                found.insert(make_pair(y,x));
            }
        }
        y++;
    }
    
    string column;
    for (x = 0; x < SIZE; x++) {
        inputstream.clear();
        inputstream.seekg(0, ios::beg);
        column="";
	      while (std::getline(inputstream, line)) {
            column += line[x];
        }
        char hl = column[0];
        found.insert(make_pair(0,x));
        for (y=0; y < SIZE; y++) {
            if (column[y] > hl) {
                hl=column[y];
                found.insert(make_pair(y,x));
            }
        }
    }

    for (x = 0; x < SIZE; x++) {
        inputstream.clear();
        inputstream.seekg(0, ios::beg);
        column="";
	      while (std::getline(inputstream, line)) {
            column += line[x];
        }
        char hl = column[SIZE-1];
        found.insert(make_pair(SIZE-1,x));
        for (y=SIZE; y-- > 0;) {
            if (column[y] > hl) {
                hl=column[y];
                found.insert(make_pair(y,x));
            }
        }
    }
    return found.size();
};

int visibletrees(string &in, datasize pos){
    datasize visible=0;
    char hl=in[pos];
    if (pos == 0)
        return 0;
    for (datasize j=pos; j-- >0;) {
            if (in[j]>=hl) 
            {
                visible++;
                break;
            }
            if (in[j]<hl) {
                visible++;
            }
    }
    return visible;
};

int part2() {
    datasize x, y;
    map<Point, uint32_t> scores;
    istringstream inputstream(string(input_start, input_end-1));

	  string line;

    y=0;
	  while (std::getline(inputstream, line)) {
        for (x=0; x < SIZE; x++) {
            auto vt = visibletrees(line,x);
            if (vt > 0)
                scores[make_pair(y,x)] = vt; 

        }
        y++;
	  }
    y=0;
    inputstream.clear();
    inputstream.seekg(0, ios::beg);
	  while (std::getline(inputstream, line)) {
        string rev = string(line.rbegin(), line.rend());
        for (x=0; x < SIZE; x++) {
            auto vt = visibletrees(rev,x);
            auto p = make_pair(y,SIZE-x-1);
            if (vt > 0) 
                scores[p] *= vt;
            else
                scores.erase(p); 
        }
        y++;
    }
    // Looking up
    string column;
    for (x = 0; x < SIZE; x++) {
        column = "";
        inputstream.clear();
        inputstream.seekg(0, ios::beg);
	      while (std::getline(inputstream, line)) {
            column += line[x];
        }
        for (y=0; y < SIZE; y++) {
            auto vt = visibletrees(column,y);
            auto p = make_pair(y,x);
            if (vt > 0) 
                scores[p] *= visibletrees(column,y);
            else
                scores.erase(p); 
        }
    }
    // Looking down 
    for (x = 0; x < SIZE; x++) {
        column = "";
        inputstream.clear();
        inputstream.seekg(0, ios::beg);
	      while (std::getline(inputstream, line)) {
            column += line[x];
        }
        string rev = string(column.rbegin(), column.rend());
        for (y=0; y < SIZE; y++) {
            auto vt = visibletrees(rev,y);
            auto p = make_pair(SIZE-y-1,x);
            if (vt > 0) 
                scores[p] *= visibletrees(rev,y);
            else
                scores.erase(p); 
        }
    } 
    return ranges::max(scores | views::values);
}

extern "C" void app_main(void)
{
	while (true) {
		cout << "Part 1: " << part1() << endl;
		cout << "Part 2: " << part2() << endl;
		this_thread::sleep_for(chrono::seconds(1));
	}
}
