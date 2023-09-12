#include"main.h"

/**
 *  print_alphabet_x10 - a function that prints 10 times the alphabet
 *
 *  Description: Uses void print_alphabet_x10(void);
 */

void print_alphabet_x10(void)
{
	int line, i;

	for (line = 0; line <= 9; ++line)
	{
		for (i = 'a'; i <= 'z'; ++i)
			_putchar(i);
		_putchar('\n');
	}
}
