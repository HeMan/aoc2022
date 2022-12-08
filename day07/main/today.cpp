#include <algorithm>
#include <concepts>
#include <fstream>
#include <iostream>
#include <iostream>
#include <numeric>
#include <ranges>
#include <stack>
#include <thread>
#include <vector>

#include "getinput.h"

// TODO: could be simplified

using namespace std;

struct Node {
    string name;
    Node() {};
    Node(string name) : name(name) {};
    virtual uint32_t get_size()=0;
    virtual void print()=0;
    virtual void get_directories()=0;
    virtual bool is_dir()=0;
};

struct Directory : Node {
    vector<Node *> nodes;
    inline static vector<Node *> directories;
    Directory() : Node("") {};
    Directory(string name) : Node(name) {};
    bool is_dir() { return true; };
    void add(Node *node) {
        this->nodes.push_back(node);
    };
    uint32_t get_size() {
        if (this->nodes.size() == 0)
            return 0;
        auto allsizes = nodes | views::transform([](auto n) { return n->get_size(); });
        return accumulate(allsizes.begin(), allsizes.end(), 0);
    }
    void get_directories() {
        for (auto n : nodes) {
            if (n->is_dir()) {
                directories.push_back(n);
            };
            n->get_directories();
        }
    }
    void print() {
        cout << name << " contains ";
        for (auto n : nodes)
            n->print();
        //cout << endl;
    }
};

struct File : Node {
    uint32_t sz;
    File(string name, uint32_t siz) : Node(name), sz(siz) {};
    bool is_dir() { return false; };
    uint32_t get_size() {
        return this->sz;
    };
    void get_directories() {};
    void print() {
        cout << " F:" << name << endl;
    };
};

extern "C" void app_main(void)
{
    std::vector<std::string> inputlines;
    inputlines = getlines();
    stack<Directory*> dirstack;
    Directory* cwd;
    cwd = new Directory(".");
    for (auto line : inputlines) {
        if (line.starts_with("$")) {
            if (line == "$ ls") {
                //ls (do nothing?)
            } else if (line == "$ cd ..") {
                auto tmp = cwd;
                cwd = dirstack.top();
                cwd->add(tmp);
                dirstack.pop();
            } else if (line.starts_with("$ cd ")) {
                auto dirname = line.substr(5);
                dirstack.push(cwd);
                cwd = new Directory(dirname);
            };
        } else if (line.starts_with("dir")) {
            // directory (do nothing?)
        } else {
            int size;
            char filename[255];
            sscanf(line.c_str(), "%d %s", &size, filename);
            cwd->add(new File(filename, size));
        };
    };
    while(!dirstack.empty()){
        auto tmp = cwd;
        cwd = dirstack.top();
        cwd->add(tmp);
        dirstack.pop();
    }
    auto storagesize = 70000000 - cwd->get_size();
    auto needed = 30000000 - storagesize;
    cwd->get_directories();
    auto sizes = cwd->directories | views::filter([](auto d){ if ((d->name == ".") or (d->name=="/")) { return false; } else { return d->get_size()<=100000; }; }) | views::transform([](auto d){ return d->get_size(); });
    auto p1 = accumulate(sizes.begin(), sizes.end(), 0);
    auto bestsize = cwd->directories | views::filter([needed](auto d){ if ((d->name == ".") or (d->name=="/")) { return false; } else { return d->get_size() >= needed; }}) | views::transform([](auto d){ return d->get_size(); }) | views::common;
    //int p2min = min_element(p2.begin(), p2.end());
    //cout << "Part 2: " << p2min << endl;
    auto p2 = ranges::min(bestsize);
    while (true) {

        cout << "Part 1: " << p1 << endl;
        cout << "Part 2: " << p2 << endl;
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
}
