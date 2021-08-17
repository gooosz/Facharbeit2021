#include "BigInt.hpp"

ostream& BigInt::print(ostream& out)
{
	//print this to out
	out << toString() << '\n';

	return out;
}

//returns a string equivalent to this
string BigInt::toString()
{
	std::string str = "";

	if (isNegative())
	{
		str = "-";
	}

	//append each int in vector<int> number to the string
	for (int i = getNumDigits()-1; i >= 0; i--)
	{
		str += to_string(getDigit(i));
	}

	return str;
}

/*
 * returns an int, equivalent to this
 * this must be in bound for Integer
 * convert vector<int> number to int
 * so that e.g. {1, 2, 3} becomes 123
 */
int BigInt::toInt() /* may throw exception */
{
	int integer = 0;

	for (int i = getNumDigits()-1; i >= 0; i--)
	{
		/*
		 * If BigInt is negative
		 * the integer has to go into negative
		 * otherwise underflow/overflow can't
		 * handle correctly, because
		 * the max int is 2147483647
		 * but min int is -2147483648
		 */
		if (isNegative())
			integer = integer * 10 - getDigit(i);
		else
			integer = integer * 10 + getDigit(i);
	}

	/*
	 * check if overflow/underflow
	 * by checking last digit of both
	 * BigInt and integer
	 * check the signs of both
	 * if the signs are different
	 * e.g. integer is positive
	 * and BigInt negative,
	 * underflow/overflow has happened
	 * throw a std::underflow_error / std::overflow_error exception
	 */

	if ((integer > 0) && (this->isNegative()))
		throw std::underflow_error("Cannot type convert BigInt to int, BigInt out of range!");
	if ((integer < 0) && (!this->isNegative()))
		throw std::overflow_error("Cannot type convert BigInt to int, BigInt out of range!");

	return integer;
}
