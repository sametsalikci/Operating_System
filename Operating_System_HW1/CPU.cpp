#include <iostream>
#include <sstream>
#include <string>
#include <cstdlib>
#include <fstream>
#include <vector>
#include "CPU.h"
#include "Memory.h"
#include "Factory.h"
#include "Instructions.h"

using namespace std;

//Class GTU_C312 function implementations
void GTU_C312::readFile(const char* filename)
{
	ifstream inpFile;
	inpFile.open(filename);
	if (!inpFile.is_open())
	{
		cerr << "Cannot open input file!!\n" << endl;
		return ;
	}
	string strLine;
	
	while ((getline(inpFile,strLine)))
	{
		if(strLine == "Begin Data Section" )
		{ 
			while(getline(inpFile,strLine) && (strLine != "End Data Section"))
			{
				
				if (strLine[0] != '#') {
						
					string str1 = strLine.substr(0, strLine.find(" "));
					string str2 = strLine.substr(strLine.find(" ") + 1, strLine.find("\n"));
					string str3 = str2.substr(0, str2.find(" "));
					int num1 = atoi(str1.c_str());
					int num2 = atoi(str3.c_str());
					Memory::getInstance()->addToMemory(num1,num2);
				}
			}
			
		}
		else if (strLine == "Begin Instruction Section")
		{	
			while (getline(inpFile, strLine) && (strLine != "End Instruction Section"))
			{
				if (strLine[0] != '#') {
					string number1 = strLine.substr(0, strLine.find(" "));
					string temp = strLine.substr(strLine.find(" ") + 1, strLine.find("\n"));
					string ins = temp.substr(0, temp.find(" "));
					temp = temp.substr(temp.find(" ") + 1, temp.find("\n"));
					string B = temp.substr(0, temp.find(" "));
					temp = temp.substr(temp.find(" ") + 1,temp.find("\n"));
					string A = temp.substr(0, temp.find(" "));
					int num1 = atoi(number1.c_str());
					int num2 = atoi(B.c_str());
					int num3 = atoi(A.c_str());
					try {
						Instruction *tempInstruction = Factory::createIntruction(num1, ins, num2, num3);
						getInstructionSet().push_back(tempInstruction);
					}
					catch (const std::invalid_argument& e) {
						cout << e.what();
						cout << "Press Enter to Continue";
						cin.ignore();
						return;
					}	
				}
			}
		}
		
	}
	inpFile.close();
}

void GTU_C312::tick()
{
	int programCounter = Memory::getInstance()->getCell(0).getCellValue();
	instructionSet[programCounter]->intructionRun();
}

bool GTU_C312::isHalted()
{
	int programCounter = Memory::getInstance()->getCell(0).getCellValue();
	for (unsigned int i = 0; i < getInstructionSet().size(); i++)
	{
		if ((instructionSet[i]->getCommand()) == "HLT")
		{
			if ((instructionSet[i]->getIndex()) == programCounter)
			{
				return true;
			}
		}
	}
	return false;
}

void GTU_C312::printMemory()
{
	for (unsigned int i = 0; i < Memory::getInstance()->getMemory().size(); i++)
	{
		printf("Address: %d  Value: %d\n",
			Memory::getInstance()->getCell(i).getCellAddress(), Memory::getInstance()->getCell(i).getCellValue());
	}
}
