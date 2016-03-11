#pragma once
#include <iostream>
#include <string>

#include "Instructions.h"

using namespace std;

class Factory
{
public:
	static Instruction * createIntruction(int idx, string command, int B, int A);
	Factory();
	~Factory();

private:

};
