#include "monty.h"

/**
* free_dlistint - frees doubly linked list
* @head: pointer to head of the list
*/
void free_dlistint(stack_t *head)
{
stack_t *current;
stack_t *next;

current = head;
while (current != NULL)
{
next = current->next;
free(current);
current = next;
}
}
