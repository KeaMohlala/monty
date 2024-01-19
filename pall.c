#include "monty.h"

/**
*op_pall - prints all the values on the stack
*@stack: pointer to the head of the stack
*@line_number: file line number
**/

void op_pall(stack_t **stack, unsigned int line_number)
{
stack_t *ptr = *stack;
/*argument not used*/
(void)line_number;

if (ptr == NULL)
return;

while (ptr != NULL)
{
printf("%d\n", ptr->n);
ptr = ptr->next;
}
}
