#include "monty.h"

/**
 * _isdigit - Checks for a digit 0 through 9
 * @s: pointer to item
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
	tmp++;
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
 * add_dnodeint - add node to the beginning of list
 * @head: pointer to first node
 * @n: data inside node
 * Return: pointer to first node
 */
stack_t *add_dnodeint(stack_t **head, const int n)
{
	stack_t *new;

	new = malloc(sizeof(stack_t));
	if (new == NULL)
		return (NULL);

	if (*head == NULL)
	{
		new->n = n;
		new->next = NULL;
		new->prev = NULL;
		*head = new;
		return (*head);
	}

	(*head)->prev = new;
	new->n = n;
	new->next = *head;
	new->prev = NULL;
	*head = new;
	return (*head);
}
/**
 * add_dnodeint_end - add node to end of list
 * @head: pointer to first node
 * @n: data inside node
 * Return: pointer to first node
 */
stack_t *add_dnodeint_end(stack_t **head, const int n)
{
	stack_t *tmp = *head;
	stack_t *new_node;

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
		return (NULL);

	new_node->n = n;

	if (*head == NULL)
	{
		new_node->next = NULL;
		new_node->prev = NULL;
		*head = new_node;
		return (new_node);
	}

	while (tmp->next != NULL)
	{
		tmp = tmp->next;
	}

	tmp->next = new_node;
	new_node->prev = tmp;
	new_node->next = NULL;
	return (new_node);
}

/**
 * cleanStack - Frees mallocs and close de files
 * @stack: Stack
 */
void cleanStack(stack_t **stack)
{
	stack_t *current = *stack;

	for (; current; current = *stack)
	{
		*stack = (*stack)->next;
		free(current);
	}
}
