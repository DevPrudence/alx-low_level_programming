#include "main.h"

/**
 * flip_bits - Function to find the number of bits you would need to flip
 *             to get from one number to another
 * @n: The first number
 * @m: The second number (destination)
 *
 * Return: The number of bits you would need to flip
 */

unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	/* Declare an integer variable flipCount and initialize it to 0 */
	int flipCount = 0;

	/* While loop that continues as long as n is not 0 */
	while (n)
	{
		/**
		 * If the least significant bit of n and m are
		 * not the same, increment num_flips by 1
		 */
		if ((n & 1) != (m & 1)) /* check if corresponding bits are not the same */
		flipCount++;

		/**
		 * Right shift the bits of n and m by 1 place and
		 * assign the results back to n and m respectively
		 */
		n = n >> 1;
		m = m >> 1;
	}

	/* Return the number of bits you would need to flip */
	return (flipCount);
}
