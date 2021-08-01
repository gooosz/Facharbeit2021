#include "BigInt.hpp"

int BigInt::getSigDigit() const
{
	//returns the significant digit

	//significant digit is at position 0

	return getDigit(0);
}

bool BigInt::isNegative() const
{
	//returns true, if BigInt is negative
	return negative;
}

int BigInt::getNumDigits() const
{
	//returns the number of digits of BigInt
	return numDigits;
}

int BigInt::getDigit(int k) const
{
	//returns the k-th digit

	//Check if k is in bound of number
	if (0 <= k && k < getNumDigits())
		return number[k];

	//k not in bound
	throw std::out_of_range("Error: k not in bound!");
}

void BigInt::changeDigit(int k, int val)
{
	//changes the k-th digit to val

	//Check if k is in bound of number
	if (0 <= k && k < getNumDigits())
	{
		number[k] = val;
	}

	//k not in bound
	throw std::out_of_range("Error: k not in bound!");
}

void BigInt::addSigDigit(int val)
{
	//adds val as new significant digit

	//Allocate new storage
	//Push each value to 1 Pos next
	number.resize(getNumDigits() + 1);

	//Start at last digit and go through vector
	for (int i=number.size()-1; i > 0; i--)
	{
		changeDigit(i, i-1);
	}

	//Add the new significant digit
	changeDigit(0, val);

	//Number of digits has increased by 1
	numDigits++;
}

