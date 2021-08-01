#include "BigInt.hpp"

ostream& operator<< (ostream& out, BigInt& big)
{
	//print big to out
	big.print(out);

	return out;
}

istream& operator>> (istream& in, BigInt& big)
{
	//Creates a temporary BigInt
	//and sets big equal to the temporary one
	string str;
	in >> str;
	BigInt* temp = new BigInt(str);

	big = *temp;

	delete temp;
	return in;
}
