#include "monty.h"

/**
 * _stack - stack LIFO: stack
 * @stack: The head of the stack
 * @line_number: The line where the operator is
 *
 * Return: Nothing
 */
void _stack(stack_t **stack, unsigned int line_number)
{
	(void) stack;
	(void) line_number;

	sq_flag = 0;
}
/**
 * _queue - Pchange to fifo
 * @stack: The head of the stack
 * @line_number: current line
 *
 * Return: Nothing
 */
void _queue(stack_t **stack, unsigned int line_number)
{
	(void) stack;
	(void) line_number;

	sq_flag = 1;
}
