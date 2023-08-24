#include "monty.h"

/**
 * executor - executes the opcode
 * @content: content of the line
 * @line_no: line number of bytecode
 * @stack: head stack of linked list
 * @file: pointer to a monty file
 *
 * Return: no return
 */

int executor(char *content, stack_t **stack, unsigned int line_no, FILE *file)
{
	instruction_t inst_op[] = {
		{"nop", my_nop},
		{"push", push_monty},
		{"pop", pop_monty},
		{"swap", swap_monty},
		{"pall", pall_monty},
		{"pint", pint_monty},
		{"add", add_monty},
		{"queue", queue_monty}
	}
	char op_code;
	unsigned int a = 0;

	op_code = strtok(content, "\n\t");
	if (op_code && op_code[0] == '#')
		return;
	bus.args = strtok(NULL, "\n\t");
	while (inst_op[a].opcode && op_code)
	{
		if (strcmp(op_code, inst_op[a].opcode) == 0)
		{
			inst_op[a].f(stack, line_no);
			return (0);
		}
		a++;
	}
	if (op_code && inst_op[a].opcode == NULL)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", line_no, op_code);
		fclose(file);
		free(content);

		stack_free(*stack);
		exit(EXIT_FAILURE);
	}
	return (1);
}
