#include "BigInt.hpp"

//Set this equal to rhs
const BigInt& BigInt::operator= (const BigInt& rhs)
{
	number.clear();
	negative = false;
	numDigits = 0;

	for (int i=0; i < rhs.getNumDigits(); i++)
	{
		int newSig = rhs.getDigit(i);
		this->addSigDigit(newSig);
	}


	if (rhs.isNegative())
		negative = true;

	return *this;
}

//adds rhs to this
const BigInt& BigInt::operator+= (const BigInt& rhs)
{
	int carry = 0;

	if (this->isNegative() == rhs.isNegative() &&
		this->getNumDigits() > rhs.getNumDigits())
	{
		int i;
		for (i=0; i<rhs.getNumDigits(); i++)
		{
			int added = getDigit(i) + rhs.getDigit(i) + carry;
			changeDigit(i, added % 10);
			carry = added / 10;
		}

		while (carry > 0)
		{
			i++;
			int added = this->getDigit(i) + carry;
			changeDigit(i, added % 10);
			carry = added / 10;
		}
	}
	else if (this->isNegative() == rhs.isNegative())
	{
		//this->getNumDigits <= rhs.getNumDigits
		int i;
		for (i=0; i<this->getNumDigits(); i++)
		{
			int added = getDigit(i) + rhs.getDigit(i) + carry;
			changeDigit(i, added % 10);
			carry = added / 10;
		}

		while (carry > 0 || i < rhs.getNumDigits())
		{
			int added = rhs.getDigit(i) + carry;
			addSigDigit(added % 10);
			carry = added / 10;
			i++;
		}
	}
	else
	{
		//different signs
		if (!this->isNegative() && rhs.isNegative())
			*this -= rhs.abs();

		if (this->isNegative() && !rhs.isNegative())
		{
			BigInt temp = rhs;
			temp -= this->abs();
			*this = temp;
		}
	}

	return *this;
}

//subtracts rhs from this
const BigInt& BigInt::operator-= (const BigInt& rhs)
{
	int carry = 0;


	if (!this->isNegative() && !rhs.isNegative())
	{
		//Algo

		if (this->getNumDigits() > rhs.getNumDigits())
		{
			//loop thru smaller (rhs) one
			int i;
			for (i=0; i<rhs.getNumDigits(); i++)
			{
				int subtracted = getDigit(i) - (rhs.getDigit(i) + carry);
				changeDigit(i, ::abs(subtracted % 10));
				carry = ::abs(subtracted / 10);
			}

			while (carry > 0)
			{
				i++;
				int subtracted = this->getDigit(i) - carry;
				changeDigit(i, ::abs(subtracted % 10));
				carry = ::abs(subtracted / 10);
			}
		}
		else
		{
			//this->getNumDigits <= rhs.getNumDigits

		}

	}
	else if (this->isNegative() && !rhs.isNegative())
	{
		//Algo
		BigInt temp = this->abs();
		temp += rhs;
		temp.negative = true;
		*this = temp;
	}
	else if (this->isNegative() && rhs.isNegative())
	{
		BigInt tmp = rhs.abs();
		tmp -= this->abs();
		*this = tmp;
	}
	else if (!this->isNegative() && rhs.isNegative())
	{
		*this += rhs.abs();
	}

	return *this;
}

//multiplies rhs to this
const BigInt& BigInt::operator*= (const BigInt& rhs)
{
	return *this;
}

//sets this as the remainder of this and rhs
const BigInt& BigInt::operator%= (const BigInt& rhs)
{
	return *this;
}
