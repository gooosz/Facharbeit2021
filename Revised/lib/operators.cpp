#include "BigInt.hpp"

const BigInt& BigInt::operator= (const BigInt& rhs)
{
	//sets this equal to rhs

	//Equalize the signs
	if (rhs.isNegative())
		this->negative = true;
	else
		this->negative = false;

	//Set the number of digits equal
	numDigits = rhs.getNumDigits();

	//Resize the vector to fit all elements of rhs
	number.resize(getNumDigits());

	for (int i=0; i<getNumDigits(); i++)
	{
		changeDigit(i, rhs.getDigit(i));
	}

	return *this;
}

const BigInt& BigInt::operator+= (const BigInt& rhs)
{
	//adds rhs to this

	return *this;
}

const BigInt& BigInt::operator-= (const BigInt& rhs)
{
	//subtracts rhs from this

	return *this;
}

const BigInt& BigInt::operator*= (const BigInt& rhs)
{
	//multiplies rhs to this

	return *this;
}

const BigInt& BigInt::operator%= (const BigInt& rhs)
{
	//sets this as the remainder of this and rhs

	return *this;
}
