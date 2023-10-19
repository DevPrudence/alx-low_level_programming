#include <string.h>
#include "lists.h"

/**
* add_node_end - adds a new node at the end of a singly linked list.
* @head: a linked list to print
* @str: needs to be duplicated.
*
* Return: the address of the new element, or NULL if it failed.
*/

list_t *add_node_end(list_t **head, const char *str)
{
	list_t *new_node, *tmp_node;
	unsigned int c = 0;

	/* Check if str is NULL */
	if (str == NULL)
		return (NULL);

	/* Calculate the length of str */
	while (str[c++])
		;
	/* Allocate memory for new_node */
	new_node = malloc(sizeof(list_t));
	if (new_node == NULL)
		return (NULL);
	/* Copy str to new_node */
	new_node->str = strdup(str);
	new_node->len = --c;
	new_node->next = NULL;

	/* If head is NULL, set new_node as head */
	if (*head == NULL)
	{
		(*head) = new_node;
		return (new_node);
	}

	/* Traverse the list to find the last node */
	tmp_node = *head;
	while (tmp_node->next)
		tmp_node = tmp_node->next;

	/* Add new_node to the end of the list */
	tmp_node->next = new_node;

	return (new_node);
}

