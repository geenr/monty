#include "monty.h"
/**
 * pall_monty - prints the stack
 * @head: stack head
 * @line_no: line number used
 * Return: no return
*/
void pall_monty(stack_t **head, unsigned int line_no)
{
	stack_t *h;
	(void)line_no;

	h = *head;
	if (h == NULL)
		return;
	while (h)
	{
		printf("%d\n", h->n);
		h = h->next;
	}
}
