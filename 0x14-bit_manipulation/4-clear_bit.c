#include "main.h"

/**
 * clear_bit - Function to clear the value of a bit at a given index
 * @n: Pointer to the decimal number
 * @index: The index, starting from 0, of the bit you want to clear
 *
 * Return: 1 if it worked, or -1 if an error occurred
 */

int clear_bit(unsigned long int *n, unsigned int index)
{
	/**
	 * If the index is greater than 32 (because size
	 * of long int is 32 bits), return -1
	 */
	if (index > 32)
	return (-1);

	/**
	 * Shift left 1 by index bits, perform bitwise NOT, perform
	 * bitwise AND with the dereferenced n, and assign the result
	 * back to the dereferenced n
	 */
	*n = *n & (~(1 << index));
	/* Return 1 to indicate success */
	return (1);
}
