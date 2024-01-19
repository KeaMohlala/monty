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

/**
* op_sub - subtracts top element from second top element of the stack
* @stack: pointer to head pointer of the stack
* @line_number: file line number
*/

void op_sub(stack_t **stack, unsigned int line_number)
{
stack_t *top, *second_top;

if (*stack == NULL || (*stack)->next == NULL)
{
fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
return;
}

top = *stack;
second_top = top->next;

second_top->n -= top->n;
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
