#include "lists.h";

/**
* list_len - count the elements of a linked list.
* @h: a singly linked list
*
* Return: the number of nodes
*/

/* Function to calculate list length */
size_t list_len(const list_t *h)
{
	/* Initialize counter to 0 */
	size_t counter = 0;

	/* Iterate through the list */
	while (h != NULL)
	{
		/* Increment counter */
		++counter;
		/* Move to the next node */
		h = h->next;
	}

/* Return the calculated length */
return (counter);
}
