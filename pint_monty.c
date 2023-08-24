#include "monty.h"
/**
 * pint_monty - prints the top
 * @head: stack head
 * @line_no: line_number
 * Return: no return
*/
void pint_monty(stack_t **head, unsigned int line_no)
{
	if (*head == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_no);
		fclose(bus.file);
		free(bus.content);
		stack_free(*head);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*head)->n);
}
