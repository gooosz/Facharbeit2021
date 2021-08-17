/*
 *
 * AUTHOR: LEN-MARVIN ADLER
 * PUBLICATION DATE: -
 *
 *
 *
 *
 *
 * LICENSE AND STUFF
 *
 *
 *
 *
 * LICENSE:
 * GPL v3.0
 *
 *
 *
 *
 * This software is provided 'as-is', without any express or implied warranty.
 * In no event will the authors be held liable for any damages arising from the use of this software.
 *
*/



#ifndef BIGINT_H
#define BIGINT_H

#include <iostream>
#include <vector>
#include <string>
#include <limits>
#include <algorithm>
#include <math.h>

#define BASE 10

using namespace std;

class BigInt
{
private:
	vector<int> number;
	bool negative;
	int numDigits;

	//Helper functions
	int getDigit(int k) const;					//returns k-th digit, k must be in bound of length of number
	void changeDigit(int k, int val);				//Changes k-th digit to val
	int getSigDigit() const;					//returns the significant digit
	void addSigDigit(int val);					//adds val as new significant digit

public:
	BigInt();							//Standard Constructor
	BigInt(int num);						//Constructs BigInt equivalent to num
	BigInt(const string& str);					//Constructs BigInt equivalent to str, must contain only numerals
	BigInt(const BigInt& big);					//Copy Constructor

	~BigInt();							//Destructor, handles freeing Storage

	bool isNegative() const;					//returns negative
	int getNumDigits() const;					//returns numDigits

	const BigInt& operator+=(const BigInt& rhs);			//adds rhs to this
	const BigInt& operator-= (const BigInt& rhs);			//subtracts rhs from this
	const BigInt& operator*= (const BigInt& rhs);			//multiplies rhs to this
	const BigInt& operator%=(const BigInt& rhs);			//sets this as the remainder of this and rhs

	const BigInt& operator= (const BigInt& rhs);			//sets this equal to rhs

	const BigInt& gcd(const BigInt& rhs);				//returns the greatest common divisor (gcd) of this and rhs
	const BigInt abs() const;					//returns an absolute value of this

	bool isEqual(const BigInt& rhs);				//returns true, if this == rhs
	bool isLessThan(const BigInt& rhs);				//returns true, if this < rhs
	bool isGreaterThan(const BigInt& rhs);				//returns true, if this > rhs

	ostream& print(ostream& out);					//prints BigInt to stream out

	string toString();						//returns a string, equivalent to this
	int toInt();							/* returns an int, equivalent to this, this must be in Integer Bound
									 * may throw exception std::underflow_error / std::overflow_error
									 */
};

//------Operator overloading------

//printing
extern ostream& operator<< (ostream& out, BigInt& big);
extern istream& operator>> (istream& in, BigInt& big);

//Operations
extern const BigInt& operator+ (const BigInt& lhs, const BigInt& rhs);
extern const BigInt& operator- (const BigInt& lhs, const BigInt& rhs);
extern const BigInt& operator* (const BigInt& lhs, const BigInt& rhs);
extern const BigInt& operator* (const BigInt& lhs, int num);
extern const BigInt& operator* (int num, const BigInt& rhs);
extern const BigInt& operator% (const BigInt& lhs, const BigInt& rhs);
extern const BigInt& operator% (const BigInt& lhs, int num);
extern const BigInt& operator% (int num, const BigInt& rhs);

//boolean operators
extern bool operator== (const BigInt& lhs, const BigInt& rhs);
extern bool operator!= (const BigInt& lhs, const BigInt& rhs);
extern bool operator> (const BigInt& lhs, const BigInt& rhs);
extern bool operator< (const BigInt& lhs, const BigInt& rhs);
extern bool operator>= (const BigInt& lhs, const BigInt& rhs);
extern bool operator<= (const BigInt& lhs, const BigInt& rhs);


#endif // BIGINT_H




