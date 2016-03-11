#include <iostream>
#include "Cell.h"
#include "Memory.h"
#include "Instructions.h"
#include "Factory.h"
#include "CPU.h"
#include <cstdlib>

using namespace std;

int main(int argc,char**argv) {
	
	GTU_C312 *gtu = new GTU_C312();
	
	gtu->readFile(argv[1]);
	
	if ((atoi(argv[3]) == 0))
	{
		while (!(gtu->isHalted()))
		{
			gtu->tick();
		}
		gtu->printMemory();
	}
	else if (atoi(argv[3]) == 1)
	{
		while (!(gtu->isHalted()))
		{
			gtu->tick();
			gtu->printMemory();
		}
	}
	else if(atoi(argv[3]) == 2)
	{
		while (!(gtu->isHalted()))
		{
			gtu->tick();
			gtu->printMemory();
			cout << "Press Enter to Continue";
			cin.ignore();
		}
	}
	cout << endl;
	cout << "End Of Program" << endl;
	cout << endl;
	cout << "Press Enter to Continue";
	cin.ignore();

	return 0;
}