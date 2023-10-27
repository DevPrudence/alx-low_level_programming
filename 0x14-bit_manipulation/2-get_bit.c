#include "main.h"

/**
 * get_bit - Function to find the value of a bit at a given index
 * @n: The decimal number
 * @index: The index, starting from 0, of the bit you want to get
 *
 * Return: The value of the bit at the given index, or -1 if an error occurred
 */

/* Define the function get_bit */
int get_bit(unsigned long int n, unsigned int index)
{
	/* If the index is greater than 32, return -1 */
	if (index > 32)
	return (-1);
	/**
	 * Right shift the bits of n by index places,
	 * perform bitwise AND with 1, and return the result
	 */
	return ((n >> index) & 1);
}
