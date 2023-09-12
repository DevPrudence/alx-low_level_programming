#include"main.h"

/**
 * print_alphabet - This is a function that prints the alphabet
 *
 * Description: Prints in lowercase, followed by a new line
 *
 */

void print_alphabet(void)
{
	int i;

	for (i = 'a'; i <= 'z'; ++i)
		_putchar(i);
	_putchar('\n');
}
