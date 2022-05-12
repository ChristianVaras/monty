#include "monty.h"

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		dprintf(STDERR_FILENO, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	handler(argv[1]);
	return (0);
}

void handler(char *filename)
{
	char *buffer = NULL;
	char *line;
	int line_count = 0, match = 0;
	size_t buffsize = 0;
	char *op_code = NULL, *argument = NULL;
	stack_t *stack = NULL;
	FILE *file = fopen(filename, "r");

	if (file == NULL)
	{
		dprintf(STDERR_FILENO, "Error: Can't open file %s\n", filename);
		exit(EXIT_FAILURE);
	}
	while (getline(&buffer, &buffsize, file) != -1)
	{
		line_count++;
		op_code = strtok(line, " \n\t\r");
		if (op_code == NULL)
		{
			free(op_code);
			continue;
		}
		else if (*op_code == '#')
			continue;
		argument = strtok(NULL, " \n\t\r");
		match = get_opc(&stack, op_code, argument, line_count);
		if (match == 1)
			push_error(file, line, stack, line_count);
		else if (match == 2)
			inst_error(file, line, stack, op_code, line_count);
	}
	free(buffer);
	free_dlistint(stack);
	fclose(file);
}

/**
 * get_opc - function to handle the opcode
 * @stack: is a stack or queue
 * @arg: is a parameter
 * @item: is a parameter
 * @count: is a line command
 * Return: 0 if
 */
int get_opc(stack_t **stack, char *oprt, char *item, int count)
{
	int i = 0;

	instruction_t op[] = {
		{"push", _push},
		{"pall", _pall},
		{NULL, NULL}
	};

	while (op[i].opcode)
	{
		if (!strcmp(oprt, op[i].opcode))
		{
			if (!strcmp(oprt, "push"))
			{
				if (_isdigit(item) == 1)
					data_item = atoi(item);
				else
					return (1);
			}
			op[i].f(stack, (unsigned int)count);
			break;
		}
		i++;
	}
	if (!op[i].opcode)
		return (2);

	return (0);
}
