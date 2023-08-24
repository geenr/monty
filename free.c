#include "monty.h"

/**
 * stack_free - frees a double linked list
 * @head: head stack of linked list
 */

void stack_free(stack_t *head)
{
	stack_t *tmp;
	tmp = head;

	while (head)
	{
		tmp = head->next;
		free(head);
		head = tmp;
	}
}
