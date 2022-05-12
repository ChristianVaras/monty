#include "monty.h"

/**
 * _isdigit - Checks for a digit 0 through 9
 * @c: pointer to item
 * Return: 0 if is integer else 1
 */

int _isdigit(char *s)
{
	char *tmp = s;
	if (s == NULL)
		return (0);

	if (*tmp == '-')
		tmp++;

	while (*tmp != '\0')
	{
		if ((*tmp < '0' || *tmp > '9'))
			return (0);
	}
	return (1);
}

/**
 * free_dlistint - Free a list.
 * @stack: Head node.
 */
void free_dlistint(stack_t *stack)
{
	stack_t *current = NULL;

	current = stack;

	if (current != NULL)
	{
		free_dlistint(current->next);
		free(current);
	}
}


/**
 * new_node : added new_node
 * @n: The value in the node
 * Return: the adress of the new node
 */

stack_t *new_node(int n)
{
	stack_t *new = NULL;

	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		dprintf(STDERR_FILENO, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new->n = n;
	new->next = NULL;
	new->prev = NULL;

	return (new);
}
