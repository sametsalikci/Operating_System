#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Instructions.h"

using namespace std;

class GTU_C312
{
public:
	GTU_C312() {};
	~GTU_C312();
	void readFile( const char* filename);
	void tick();
	bool isHalted();
	void printMemory();
	vector<Instruction*> & getInstructionSet() {return instructionSet; }
private:
	vector<Instruction*> instructionSet;
};

