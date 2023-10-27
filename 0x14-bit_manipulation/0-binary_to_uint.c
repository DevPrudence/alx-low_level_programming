#include "main.h"

/**
 * binary_to_uint - Function to convert binary string to unsigned int
 * @b: pointer to a binary string
 *
 * Return: the converted unsigned integer, or 0 if there is one or more
 * chars in the string b that is not 0 or 1 or if b is NULL
 */
unsigned int binary_to_uint(const char *b)
{
	/* Declare an integer variable i */
	int index;
	/* Declare an unsigned integer variable decimal and initialize it to 0 */
	unsigned int decimalResult = 0;
	/* Check if the input string b is NULL */
	if (b == NULL)

	/* If b is NULL, return 0 */
	return (0);

	/* Iterate through the binary string */
	for (index = 0; b[index] != '\0'; ++index)
	{
		/**
		 * Check if the character at index i in the
		 * string b is not a valid binary digit
		 */
		if (b[index] != '0' && b[index] != '1')
		/**
		 * If the character at index i in the string b
		 * is not a valid binary digit, return 0
		 */
		return (0);
		/**
		 * Convert the binary digit at index i in the
		 * string b to decimal and update the result
		 */
		decimalResult = 2 * decimalResult + (b[index] - '0');
	}
	/* Return the converted unsigned integer */
	return (decimalResult);
}
