#include "main.h"

/**
 * get_endianness - Function to check the endianness
 *
 * Return: 0 if big endian, 1 if little endian
 *
 * Description: In big endian format, the most significant byte
 *              is stored first, thus gets stored at the smallest
 *              address byte. While in little endian format,
 *              the least significant byte is stored first.
 */

int get_endianness(void)
{
	/* Declare an unsigned integer variable i and initialize it to 1 */
	unsigned int num = 1;

	/**
	 * Declare a character pointer ptr and
	 * initialize it to point to the address of num
	 */
	char *ptr = (char *) &num;

	/* Return the value pointed to by ptr */
	return (*ptr);
}
