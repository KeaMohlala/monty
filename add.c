#include "monty.h"

/**
* op_add - adds top two elements of the stack
* @stack: pointer to head pointer of the stack
* @line_number: file line number
*/

void op_add(stack_t **stack, unsigned int line_number)
{
stack_t *top, *second_top;

if (*stack == NULL || (*stack)->next == NULL)
{
fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
return;
}

top = *stack;
second_top = top->next;

second_top->n += top->n;
if (top->prev != NULL)
{
top->prev->next = top->next;
}
if (top->next != NULL)
{
top->next->prev = top->prev;
}

free(top);
*stack = second_top;
}
