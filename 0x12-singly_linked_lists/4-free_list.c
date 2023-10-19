#include <string.h>
#include "lists.h"

/**
* free_list - frees a singly linked list.
* @head: a linked list to print
*
* Return: void.
*/

void free_list(list_t *head)
{
	list_t *tmp_node;

	while (head)
	{
		tmp_node = head; /* Store current node */
		head = head->next; /*  Move to next node */
		free(tmp_node->str); /* Free string memory */
		free(tmp_node); /* Free node memory */
	}
}

