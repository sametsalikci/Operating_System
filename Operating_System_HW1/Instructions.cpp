#include "Instructions.h"
#include "Memory.h"

//Instruction abstract class
int Instruction::getOpA() const
{
	return opA;
}

int Instruction::getOpB() const
{
	return opB;
}

string Instruction::getCommand() const
{
	return command;
}

int Instruction::getIndex() const
{	
	return index;
}

//Set Instruction functions

void SET::intructionRun()
{
	set(getOpB(), getOpA());
}

//A is a address,B is a value
void SET::set(int B,int A)
{
	//istenen adresin olup olmadýðýný kontrol et
	Memory::getInstance()->setValue(A,B);
	if (A != 0)
	{
		int pc = Memory::getInstance()->getCell(0).getCellValue();
		pc += 1;
		Memory::getInstance()->getCell(0).setCellValue(pc);
	}
}

//CPY Instructions functions
void CPY::intructionRun()
{	
	cpy(getOpB(),getOpA());
	int pc = Memory::getInstance()->getCell(0).getCellValue();
	pc += 1;
	Memory::getInstance()->getCell(0).setCellValue(pc);
}
//Copy the content of memory location A1 to memory A2.
void CPY::cpy(int address, int value)
{	
	int tempValue = Memory::getInstance()->getCell(address).getCellValue();
	Memory::getInstance()->getCell(value).setCellValue(tempValue);
}


//CPYI INSTRUCTION
void CPYI::intructionRun()
{
	cpyi(getOpB(), getOpA());
	int pc = Memory::getInstance()->getCell(0).getCellValue();
	pc += 1;
	Memory::getInstance()->getCell(0).setCellValue(pc);
}
void CPYI::cpyi(int address, int value)
{
	int tempInderectAdrs1 = Memory::getInstance()->getCell(address).getCellValue();
	int tempValue = Memory::getInstance()->getCell(tempInderectAdrs1).getCellValue();
	Memory::getInstance()->getCell(value).setCellValue(tempValue);
}

//ADD INSTRUCTION
void ADD::intructionRun()
{
	add(getOpB(), getOpA());
	int pc = Memory::getInstance()->getCell(0).getCellValue();
	pc += 1;
	Memory::getInstance()->getCell(0).setCellValue(pc);
}

void ADD::add(int address, int value)
{
	int val = Memory::getInstance()->getCell(value).getCellValue();
	val = val + address;
	Memory::getInstance()->getCell(value).setCellValue(val);
}

//ADDI INSTRUCTION
void ADDI::intructionRun()
{
	addi(getOpB(), getOpA());
	int pc = Memory::getInstance()->getCell(0).getCellValue();
	pc += 1;
	Memory::getInstance()->getCell(0).setCellValue(pc);
}

void ADDI::addi(int address, int value)
{
	int temp1 = Memory::getInstance()->getCell(address).getCellValue();
	int temp2 = Memory::getInstance()->getCell(value).getCellValue();
	int temp3 = temp1 + temp2;
	Memory::getInstance()->getCell(value).setCellValue(temp3);
}

//SUBI INSTRUCTION
void SUBI::intructionRun()
{
	subi(getOpB(), getOpA());
	int pc = Memory::getInstance()->getCell(0).getCellValue();
	pc += 1;
	Memory::getInstance()->getCell(0).setCellValue(pc);
}

void SUBI::subi(int address, int value)
{
	int tempValue = Memory::getInstance()->getCell(address).getCellValue();
	tempValue -= Memory::getInstance()->getCell(value).getCellValue();
	Memory::getInstance()->getCell(value).setCellValue(tempValue);
}

//JIF INSTRUCTION
void JIF::intructionRun()
{
	jif(getOpB(), getOpA());
}

void JIF::jif(int address, int value)
{	
	int tempVal = Memory::getInstance()->getCell(address).getCellValue();
	if (tempVal <= 0)
	{
		Memory::getInstance()->getCell(0).setCellValue(value);
		
	}
	else
	{
		int pc = Memory::getInstance()->getCell(0).getCellValue();
		pc += 1;
		Memory::getInstance()->getCell(0).setCellValue(pc);
	}
}
//HLT INSTRUCTION
void HLT::intructionRun()
{
}
void HLT::hlt(int i, string com)
{
}

//CPYI2
void CPYI2::intructionRun()
{
	cpyi2(getOpB(), getOpA());
	int pc = Memory::getInstance()->getCell(0).getCellValue();
	pc += 1;
	Memory::getInstance()->getCell(0).setCellValue(pc);
}

void CPYI2::cpyi2(int address, int value)
{
	int val = Memory::getInstance()->getCell(address).getCellValue();
	int adrs = Memory::getInstance()->getCell(value).getCellValue();
	Memory::getInstance()->getCell(adrs).setCellValue(val);
}
