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

/**
*op_nod - doesn't do anything
*@stack: pointer to the head of the stack
*@line_number: file line number
**/
void op_nod(stack_t **stack, unsigned int line_number)
{
/*argument not used*/
(void)line_number;
(void)stack;
}
