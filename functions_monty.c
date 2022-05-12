#include "monty.h"

int data_item;

/**
 * _push - pushes an element to the stack
 * @stack: HEAD of stack
 * @line_number: number of line
 */

void _push(stack_t **stack, unsigned int line_number)
{
	stack_t *new = NULL;
	(void)line_number;

	new = new_Node(data_item);

	new->next = *stack;
	if (*stack != NULL)
		(*stack)->prev = new;
	*stack = new;
}

/**
 * _pall - prints all the values on thestack starting from the top
 * @stack: HEAD of stack
 * @line_number: number of line
 */

void _pall(stack_t **stack, unsigned int line_number)
{
	stack_t *current = NULL;
	(void)line_number;

	current = *stack;

	while (current != NULL)
	{
		dprintf(STDOUT_FILENO, "%d\n", current->n);
		current = current->next;
	}
}
