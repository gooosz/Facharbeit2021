#include "BigInt.hpp"

BigInt::BigInt()
	:number(1, 0), negative(false), numDigits(1)
{
	//Standard Constructor
	//Sets this equivalent to 0

}

BigInt::BigInt(int num)
	:negative(false), numDigits(0)
{
	//Constructs a BigInt, equivalent to num

	int eachDigit = num;

	if (num < 0)
	{
		negative = true;

		while (eachDigit < 0)
		{
			//take abs value, because negativity is given
			//by bool negative
			//turn those negatives into a pos value
			//with abs()
			number.push_back(abs(eachDigit % 10));
			numDigits++;

			eachDigit /= 10;
		}
	}
	else
	{
		//num is positive
		while (eachDigit > 0)
		{
			number.push_back(eachDigit % 10);
			numDigits++;

			eachDigit /= 10;
		}
	}

	//reverse the vector, so num is in correct order in number vector
	std::reverse(number.begin(), number.end());
}

BigInt::BigInt(const string& str)
	:negative(false), numDigits(0)
{
	//Constructs a BigInt, equivalent to str, str must contain only numerals!

	int start = 0;
	//Check if sign at beginning of str
	if (str[0] == '-')
	{
		negative = true;
		start = 1;
	}
	if (str[0] == '+')
	{
		start = 1;
	}

	//cut off leading zeroes, by increasing
	//the start counter until there is no zero anymore
	while (str[start] == '0')
	{
		start++;
	}
	//if start == str.size(), str consisted of only zeroes
	//set a new variable consisting of only 1 Zero
	string var = str;
	if ((size_t)((unsigned)start) == var.size())
	{
		var = "0";
		start = 0;
	}



	for (int i = start; ((size_t)(unsigned)i) < var.size(); i++)
	{
		//Check if str[1] is not a numeric value
		//by checking if in bound for Integer (ASCII-Values)
		//0x30 = '0' and 0x39 = '9', so if str[1] is not
		//in this range, str[1] is not numeric
		if (var[i] < 0x30 || var[i] > 0x39)
		{
			std::cout << "Error: Not numeric value at pos " << i << " in string " << var << "\n";
			return;
		}

		//append str[1] to number vector
		//var[i] is a char, so by doing
		//var[i] - '0' this means
		//(int)var[i] - (int)'0'
		//which is equivalent to var[i] but
		//as an Integer
		int numerical = var[i] - '0';

		number.push_back(numerical);
		numDigits++;
	}
}

BigInt::BigInt(const BigInt& big)
{
	//Copy Constructor


}

BigInt::~BigInt()
{
	//Destructor

	//free Storage etc.

	number.clear();
}
