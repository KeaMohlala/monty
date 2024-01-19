#include "monty.h"

/**
*op_pop - removes the top element of the stack.
*@stack: pointer to the head of the stack
*@line_number: file line number
**/

void op_pop(stack_t **stack, unsigned int line_number)
{
stack_t *temp;

if (*stack == NULL)
{
fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
return;
}
temp = *stack;
*stack = (*stack)->next;
if (*stack != NULL)
(*stack)->prev = NULL;
free(temp);
temp = NULL;
}
