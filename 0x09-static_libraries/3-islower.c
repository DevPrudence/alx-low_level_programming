#include"main.h"

/**
 * _islower - a function that checks for lowercase character.
 *
 * @c: the value to be checked
 *
 * Return: Returns 1 if c is lowercase returns 0 otherwise
*/

int _islower(int c)
{
	if (c >= 97 && c <= 122)
		return (1);
	return (0);
}
