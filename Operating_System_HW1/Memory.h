
#include <iostream>
#include <vector>
#include "Cell.h"
using namespace std;

class Memory
{
public:
	
	static Memory * getInstance();
	void addToMemory(const int adrs,const int value);//New memory block created and initialized with value
	void setValue(const int adrs,const int value);
	int getValue(int adrs);
	vector<Cell>& getMemory() { return myMemory; }
	Cell & getCell(int index) {return myMemory[index]; }

private:

	Memory() {};  // Private so that it can  not be called
	Memory(const Memory&);             // copy constructor is private
	Memory & operator=(const Memory&);  // assignment operator is private
	static Memory * m_pInstance;
	vector<Cell> myMemory;
};
