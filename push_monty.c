#include "monty.h"
/**
 * push_monty - add node to the stack
 * @head: stack head
 * @line_no: line_number
 * Return: no return
*/
void push_monty(stack_t **head, unsigned int line_no)
{
	int n, a = 0, f = 0;

	if (bus.arg)
	{
		if (bus.arg[0] == '-')
			a++;
		for (; bus.arg[a] != '\0'; a++)
		{
			if (bus.arg[a] > 57 || bus.arg[a] < 48)
				f = 1; }
		if (f == 1)
		{ fprintf(stderr, "L%d: usage: push integer\n", line_no);
			fclose(bus.file);
			free(bus.content);
			stack_free(*head);
			exit(EXIT_FAILURE); }}
	else
	{ fprintf(stderr, "L%d: usage: push integer\n", line_no);
		fclose(bus.file);
		free(bus.content);
		stack_free(*head);
		exit(EXIT_FAILURE); }
	n = atoi(bus.arg);
	if (bus.lifi == 0)
		addnode(head, n);
	else
		addqueue(head, n);
}
