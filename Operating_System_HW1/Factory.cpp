#include "Factory.h"

Instruction * Factory::createIntruction(int idx, string command, int B, int A)
{
		if (command == "SET")
		{
			return  (new SET(idx, command, B, A));
		}
		else if (command == "CPY")
		{
			return  (new CPY(idx, command, B, A));
		}
		else if (command == "CPYI" )
		{
			return  (new CPYI(idx, command, B, A));
		}
		else if (command == "ADD")
		{
			return  (new ADD(idx, command, B, A));
		}
		else if (command == "ADDI")
		{
			return  (new ADDI(idx, command, B, A));
		}
		else if (command == "SUBI")
		{
			return  (new SUBI(idx, command, B, A));
		}
		else if (command == "JIF")
		{
			return  (new JIF(idx, command, B, A));
		}
		else if (command == "HLT")
		{
			return  (new HLT(idx, command));
		}
		else if (command == "CPYI2")
		{
			return (new CPYI2(idx, command, B, A));
		}
	return NULL;
}