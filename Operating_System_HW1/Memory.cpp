#include <cstdlib>
#include <iostream>
#include <vector>
#include <stddef.h>
#include "Memory.h"
#include "Cell.h"

using namespace std;
// Global static pointer used to ensure a single instance of the class.
Memory * Memory::m_pInstance = 0;

Memory * Memory::getInstance()
{
	if (!m_pInstance)
	{	
		m_pInstance = new Memory();
		return m_pInstance;
	}
	return m_pInstance;
}

void Memory::addToMemory(const int adrs,const int value)
{
	//O adress daha once varsa bir daha ekleme yapma,bunu kontrol et!!!
	Cell tempCell(adrs,value);
	getMemory().push_back(tempCell);
}

void Memory::setValue(const int adrs, const int value)
{
	myMemory[adrs].setCellValue(value);
}

int Memory::getValue(int adrs)
{
	return myMemory[adrs].getCellValue();
}