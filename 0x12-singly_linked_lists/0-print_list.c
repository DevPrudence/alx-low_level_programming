#include <stdio.h>
#include "lists.h"

/**
* print_list - prints all the elements of a list_t list
* @h: a linked list to print
* Return: the number of nodes (counter)
*/

/* Function to print list elements */
size_t print_list(const list_t *h)
{
	/* Initialize counter to track list elements */
	size_t counter = 0;

	/* Iterate through the list */
	while (h != NULL)
	{
		if (h->str == NULL)
			printf("[0] (nil)\n");
		else
			printf("[%u] %s\n", h->len, h->str);

		/* Increment counter */
		++counter;
		h = h->next;
	}

/* Return the number of elements in the list */
return (counter);
}

