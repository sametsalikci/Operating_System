#pragma once
class Cell
{
public:
	Cell() { address = 0; value = 0; }
	Cell(const int & newAddress, const int & newValue) {
		address = newAddress;
		value = newValue;
	}
	int getCellValue()const { return value; }
	int getCellAddress() const { return address; }
	void setCellAddress(int newAdrs) { address = newAdrs; }
	void setCellValue(int newValue) { value = newValue; }
private:
	int value;
	int address;
};