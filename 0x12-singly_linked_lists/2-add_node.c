#include <string.h>
#include "lists.h"

/**
* add_node - adds a new node at the beginning of a singly linked list.
* @head: a linked list to print
* @str: needs to be duplicated.
*
* Return: the address of the new element, or NULL if it failed.
*/

/* Add node to list */
list_t *add_node(list_t **head, const char *str)
{
	/* Create new node */
	list_t *new_node;
	unsigned int c = 0;

	/* Calculate string length */
	while (str[c++])
		;

	/* Allocate memory for new node */
	new_node = malloc(sizeof(list_t));
	if (new_node == NULL)
		return (NULL);

	/* Copy string to new node */
	new_node->str = strdup(str);
	new_node->len = --c;
	
	/* Insert new node at beginning of list */
	new_node->next = (*head);
	(*head) = new_node;

	return (*head);
}

