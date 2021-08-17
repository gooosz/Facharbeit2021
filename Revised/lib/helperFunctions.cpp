#include "BigInt.hpp"

int BigInt::getSigDigit() const
{
	//returns the significant digit

	//significant digit is at position numDigits -1
	int sigPos = getNumDigits() -1;

	return getDigit(sigPos);
}


//public helper functions

//returns true, if BigInt is negative
inline bool BigInt::isNegative() const
{
	return negative;
}

//returns the number of digits of BigInt
inline int BigInt::getNumDigits() const
{
	return numDigits;
}
//end of public helper functions

//returns the k-th digit
inline int BigInt::getDigit(int k) const
{
	//Check if k is in bound of number
	if (0 <= k && k < this->getNumDigits())
		return number[k];

	//k not in bound
	throw std::out_of_range("Error: k not in bound!");
}

//changes the k-th digit to val
void BigInt::changeDigit(int k, int val)
{
	//Check if k is in bound of number
	if (0 <= k && k < this->getNumDigits())
	{
		number[k] = val;
		return;
	}

	//k not in bound
	throw std::out_of_range("Error: k not in bound!");
}

//adds val as new significant digit
void BigInt::addSigDigit(int val)
{
	//Allocate new storage
	number.resize(getNumDigits() + 1);

	//Number of digits has increased by 1
	numDigits++;

	int sigDigPos = getNumDigits()-1;

	//Add the new significant digit
	changeDigit(sigDigPos, val);
}

//returns abs value of this
const BigInt BigInt::abs() const
{
	BigInt big = *this;

	if (big.isNegative())
	{
		big.negative = true;
	}

	return big;
}



