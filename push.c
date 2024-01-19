#include "monty.h"

/**
*op_push - pushes an integer to the stack
*@stack: pointer to the head of the stack
*@line_number: file line number
**/

void op_push(stack_t **stack, unsigned int line_number)
{
stack_t *temp;
int data;

temp = malloc(sizeof(stack_t));
if (temp == NULL)
{
fprintf(stderr, "Error: malloc failed\n");
return;
}
data = atoi(op_tokens[1]);
if (data == 0 && op_tokens[1][0] != '0')
{
fprintf(stderr, "L%d: usage: push integer\n", line_number);
free(temp);
return;
}
temp->n = data;
temp->prev = NULL;
temp->next = *stack;
if (*stack != NULL)
(*stack)->prev = temp;
*stack = temp;
}
