#pragma once
#include <string>
#include <stdexcept> 

using namespace std;

class Instruction
{
public:
	Instruction(int i, string com, int B, int A) {
		index = i;
		command = com;
		opA = A;
		opB = B;
	}
	virtual int getOpA()const;
	virtual int getOpB()const;
	virtual string getCommand()const;
	virtual int getIndex()const;
	virtual void intructionRun() = 0;
private:
	int index;
	string command;
	int opA;
	int opB;
};
//SET INSTRUCTION
class SET : public Instruction
{
public:
	SET(int i, string com, int B, int A)
		:Instruction(i,com,B,A) {
		
		if (A < 0) {
			throw std::invalid_argument("SET Instruction address value negative!!\n");
		}
	}
	SET():Instruction(0,"No command",0,0){}
	~SET() {}
	void intructionRun();
	void set(int address, int value);
private:
};

//CPY INSTRUCTION
class CPY : public Instruction
{
public:
	CPY(int i, string com, int B, int A)
		:Instruction(i, com, B, A) {
		if (B < 0 || A < 0)
		{
			throw std::invalid_argument("CPY Instruction addresses values negative!!\n");
		}
	}
	~CPY();
	void intructionRun();
	void cpy(int address, int value);
private:

};
//CPYI INSTRUCTION
class CPYI : public Instruction
{
public:
	CPYI(int i, string com, int B, int A)
		:Instruction(i, com, B, A) {
		if (B < 0 || A < 0)
		{
			throw std::invalid_argument("CPYI Instruction addresses values negative!!\n");
		}
	}
	void intructionRun();
	void cpyi(int address, int value);
	~CPYI();
private:

};
//JPYI2
class CPYI2 : public Instruction
{
public:
	CPYI2(int i, string com, int B, int A)
		:Instruction(i, com, B, A) {
		if (B < 0 || A < 0)
		{
			throw std::invalid_argument("CPYI2 Instruction addresses values negative!!\n");
		}
	}
	void intructionRun();
	void cpyi2(int address, int value);
	~CPYI2();

private:

};

//ADD INSTRUCTION
class ADD : public Instruction
{
public:
	ADD(int i, string com,int B,int A)
		:Instruction(i, com, B, A) {
		if (A < 0)
		{
			throw std::invalid_argument("ADD Instruction address value negative!!\n");
		}
	}
	void intructionRun();
	void add(int address, int value);
	~ADD();
private:

};

//ADDI INSTRUCTION
class ADDI : public Instruction
{
public:
	ADDI(int i, string com, int B, int A)
		:Instruction(i, com, B, A) {
		if (A < 0 || B < 0)
		{
			throw std::invalid_argument("ADDI Instruction address value negative!!\n");
		}
	}
	~ADDI();
	void intructionRun();
	void addi(int address, int value);
private:

};

//SUBI INSTRUCTION
class SUBI : public Instruction
{
public:
	SUBI(int i, string com, int B, int A)
		:Instruction(i, com, B, A) {
		if (A < 0 || B < 0)
		{
			throw std::invalid_argument("SUBI Instruction address value negative!!\n");
		}
	}
	~SUBI();
	void intructionRun();
	void subi(int address, int value);
private:
};

//JIF INSTRUCTION
class JIF : public Instruction
{
public:
	JIF(int i, string com, int B, int A)
		:Instruction(i, com, B, A) {
		if (B < 0 || A < 0 )
		{
			throw std::invalid_argument("JIF Instruction address value negative!!\n");
		}
	}
	~JIF();
	void intructionRun();
	void jif(int address, int value);
private:

};
//HLT INSTRUCTION
class HLT : public Instruction
{
public:
	HLT(int i, string com)
		:Instruction(i, com,0,0) {}
	~HLT();
	void intructionRun();
	void hlt(int i,string com);
private:

};
