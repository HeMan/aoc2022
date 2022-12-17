#include <iostream>
#include <thread>
#include "getinput.h"


using namespace std;

struct Op {
	static int32_t value;
	static int32_t pc;
	static int32_t signal;
	virtual void execute(){
		Op::time();
	};
	void time() {
		if (((pc-20) % 40) == 0) {
			signal+=pc*value;
		};
		pc++;
	};
};

struct Noop : Op
{
};

struct Addx : Op
{
	string argument;
	uint32_t timestep {0};
	Addx();
	Addx(const string &argument) : argument {argument} {};
	void execute() override {
		Op::time();
		Op::time();
		this->value+=std::stoi(argument);
	}
};

int32_t Op::value {1};
int32_t Op::pc {1};
int32_t Op::signal {0};

vector<Op *> program;

extern "C" void app_main(void)
{
	string line;
	while (std::getline(inputstream, line)) {
		Op *operation;
		if (line.starts_with("noop"))
			operation = new Noop();
		else if (line.starts_with("addx")
			operation = new Addx(line.substr(5));
		program.push_back(operation);
	};
	for (auto i : program) {
		i->execute();
	};
	while (true) {
		cout << "Part 1: " << Op::signal << endl;

	std::this_thread::sleep_for(std::chrono::seconds(1));
	}
}
