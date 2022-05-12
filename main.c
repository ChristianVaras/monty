#include "monty.h"

glob_t global = {NULL, NULL};

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		dprintf(STDERR_FILENO, "USAGE: monty file\n");
                exit(EXIT_FAILURE);
	}

	handler(argv[1]);
	return 0;
}
