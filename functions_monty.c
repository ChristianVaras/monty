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

/**
 * _pint - print int a top of stack
 * @stack: pointer to linked list stack
 * @line_number: number of line opcode occurs on
 *
 */
void _pint(stack_t **stack, unsigned int line_number)
{
	if (!*stack || !stack)
	{
		printf("L%d: can't pint, stack empty\n", line_number);
		cleanStack(stack);
		exit(EXIT_FAILURE);
	}
	dprintf(STDOUT_FILENO, "%d\n", (*stack)->n);
}

/**
 * _pop - removes the top element of the stack.
 * @stack: Stack list
 * @line_number: Number of the line
 */
void _pop(stack_t **stack, unsigned int line_number)
{
	stack_t *current = NULL;

	if (*stack == NULL || stack == NULL)
	{
		dprintf(STDERR_FILENO, "L%d: can't pop an empty stack\n", line_number);
		cleanStack(stack);
		exit(EXIT_FAILURE);
	}

	current = *stack;

	*stack = current->next;
	if (current->next != NULL)
		current->next->prev = current->prev;
	free(current);
}

/**
 * _nop - function void
 * @stack: Stack list
 * @line_number: Number of the line
 */
void _nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}
