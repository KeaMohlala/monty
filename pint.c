#include "monty.h"

/**
*op_pint - prints the value at the top of the stack, followed by a new line.
*@stack: pointer to the head of the stack
*@line_number: file line number
**/

void op_pint(stack_t **stack, unsigned int line_number)
{
stack_t *ptr = *stack;
/*argument not used*/

if (ptr == NULL)
{
fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
return;
}
printf("%d\n", ptr->n);
}
