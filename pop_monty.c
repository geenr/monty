#include "monty.h"
/**
 * pop_monty - prints the top
 * @head: stack head
 * @line_no: line_number
 * Return: no return
*/
void pop_monty(stack_t **head, unsigned int line_no)
{
	stack_t *h;

	if (*head == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_no);
		fclose(bus.file);
		free(bus.content);
		stack_free(*head);
		exit(EXIT_FAILURE);
	}
	h = *head;
	*head = h->next;
	free(h);
}
