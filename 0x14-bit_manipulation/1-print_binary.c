#include "main.h"

/**
 * print_binary - Function to print the binary representation of a number
 * @n: The number to be converted to binary
 */

void print_binary(unsigned long int n)
{
	int bitCount = 0;
	unsigned long int CurrentNumber = n;

	/* While loop that continues as long as current is not 0 */
	while (CurrentNumber)
	{
		/**
		 * Right shift the bits of current by 1 place and
		 * assign the result back to current
		 */
		CurrentNumber = CurrentNumber >> 1;
		/* Increment count by 1 */
		bitCount++;
	}

	/* If count is 0, print '0' */
	if (!bitCount)
		putchar('0');

	/* While loop that continues as long as count is not 0 */
	while (bitCount)
	{
		/**
		 * Right shift the bits of n by (count - 1) places and
		 * assign the result to current
		 */
		CurrentNumber = n >> --bitCount;

		/* If the least significant bit of current is 1, print '1' */
		if (CurrentNumber & 1)
			putchar('1');
		/* Else, print '0' */
		else
		putchar('0');
	}
}
