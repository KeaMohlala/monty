#include "monty.h"

/**
*op_swap - swaps the top two elements of the stack.
*@stack: pointer to the head of the stack
*@line_number: file line number
**/
void op_swap(stack_t **stack, unsigned int line_number)
{
stack_t *ptr;
int temp, i = 0;

ptr = *stack;
while (ptr != NULL)
{
ptr = ptr->next;
i++;
}

if (i < 2)
{
fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
return;
}
else
{
ptr = *stack;
temp = (*stack)->n;
(*stack)->n = (*stack)->next->n;
(*stack)->next->n = temp;
}
}
