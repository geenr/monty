#include "monty.h"
bus_t bus = {NULL, NULL, NULL, 0};
/**
* main - entry point to monty code interpreter
* @argc: number of arguments
* @argv: monty file location
* Return: 0 on success
*/
int main(int argc, char *argv[])
{
	FILE *file;
	char *content;
	size_t s = 0;
	ssize_t lineRead = 1;
	stack_t *stack = NULL;
	unsigned int line_no = 0;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");
	bus.file = file;
	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (lineRead > 0)
	{
		content = NULL;
		lineRead = getline(&content, &s, file);
		bus.content = content;
		line_no++;
		if (read_line > 0)
		{
			execute(content, &stack, line_no, file);
		}
		free(content);
	}
	stack_free(stack);
	fclose(file);
return (0);
}
