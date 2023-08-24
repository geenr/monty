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
		{"nop", my_nop}
	}
	char op_code;
	unsigned int a = 0;

	op_code = strtok(content, "\n\t");
