#include "monty.h"
/**
 * _add - adds top of stack and second top of stack
 *
 * @stack: pointer to linked list stack
 * @line_number: number of line opcode occurs on
 */
void _add(stack_t **stack, unsigned int line_number)
{
	stack_t *current = NULL;
	int sum = 0;

	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		cleanStack(stack);
		exit(EXIT_FAILURE);
	}
	current = *stack;
	sum = current->n + current->next->n;
	current->next->n = sum;
	_pop(stack, line_number);
}


/**
 * _sub - subtracts top of stack and second top of stack
 *
 * @stack: pointer to linked list stack
 * @line_number: number of line opcode occurs on
 */
void _sub(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;
	int sub = 0;

	if (!current || !current->next)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		cleanStack(stack);
		exit(EXIT_FAILURE);
	}
	sub = current->next->n - current->n;
	current->next->n = sub;
	_pop(stack, line_number);
}

/**
 * _mul - multiply top of stack and second top of stack
 * @stack: pointer to linked list stack
 * @line_number: number of line opcode occurs on
 *
 */
void _mul(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		printf("L%d: can't mul, stack too short\n", line_number);
		error_exit(stack);
	}
	(*stack)->next->n *= (*stack)->n;
	_pop(stack, line_number);
}

/**
 * _div - divide top of stack and second top of stack
 * @stack: pointer to linked list stack
 * @line_number: number of line opcode occurs on
 */
void _div(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		printf("L%d: can't div, stack too short\n", line_number);
		error_exit(stack);
	}
	if ((*stack)->n == 0)
	{
		printf("L%d: division by zero\n", line_number);
		error_exit(stack);
	}
	(*stack)->next->n /= (*stack)->n;
	_pop(stack, line_number);
}

/**
 * _mod - mod top of stack and second top of stack
 * * @stack: pointer to linked list stack
 * @line_number: number of line opcode occurs on
 *
 */
void _mod(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		printf("L%d: can't mod, stack too short\n", line_number);
		error_exit(stack);
	}
	if ((*stack)->n == 0)
	{
		printf("L%d: division by zero\n", line_number);
		error_exit(stack);
	}
	(*stack)->next->n %= (*stack)->n;
	_pop(stack, line_number);
}
