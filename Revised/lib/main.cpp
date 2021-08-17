#include <iostream>
#include "BigInt.hpp"

using namespace std;

int main(int argc, char **argv)
{
	//-2147483648
	BigInt b1("10");

	BigInt b2(10);
	b1 += b2;

	b1.print(cout);



	/* -------JOURNAL-------
	 *
	 * Date: 27/07
	 * Time: 12:05 AM
	 *
	 * Not working by now:
	 *
	 * -edge cases, aka max and min Integer range7
	 * (-2147483648 and 2147483647)
	 * Check the edge Cases by:
	 * 1. Checking if -2147483648 works
	 * 2. Check if -2147483649 works
	 * 3. Check if 2147483647 works
	 * 4. Check if 2147483648
	 *
	 * Error's due to edge Cases:
	 * -detect the underflow error in toInt()
	 * -print() the BigInt
	 * -toInt()
	 *
	 * --------------------------------------------
	 *
	 * Date: 27/07
	 * Time: 12:26 AM
	 *
	 * Fixed the edge cases for string Constructor
	 *
	 * Still not working:
	 * -edge cases with int Constructor
	 *//* Obviously you idiot, it takes INT as input, how could int not underflow/overflow at
	 *    edge Cases (Comment from: 29/7, 12:31 AM)
	 *
	 * What to fix:
	 * -toInt method
	 *
	 * --------------------------------------------
	 *
	 * Date: 31/07
	 * Time: 12:21 AM
	 *
	 * Fixed all problems by fixing int Constructor
	 * (while taking in the numbers it didn't increase
	 * numDigits)
	 *
	 *
	 *
	 */

    return 0;
}
