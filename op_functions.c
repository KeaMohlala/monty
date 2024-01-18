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
