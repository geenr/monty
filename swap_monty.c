#include "monty.h"
/**
 * swap_monty - adds the top two elements of the stack.
 * @head: stack head
 * @line_no: line_number
 * Return: no return
*/
void swap_monty(stack_t **head, unsigned int line_no)
{
	stack_t *h;
	int len = 0, tmp;

	h = *head;
	while (h)
	{
		h = h->next;
		len++;
	}
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_no);
		fclose(bus.file);
		free(bus.content);
		stack_free(*head);
		exit(EXIT_FAILURE);
	}
	h = *head;
	tmp = h->n;
	h->n = h->next->n;
	h->next->n = aux;
}
