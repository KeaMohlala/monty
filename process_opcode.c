#include "monty.h"
#include <string.h>

/**
* get_op_func - gets the function associated with the opcode
* @s: operator passed as argument to the program
* Return: pointer to function that corresponds to the operator argument
*/

void (*get_op_func(char *s))(stack_t **, unsigned int)
{
instruction_t ops[] = {
{"push", op_push},
{"pall", op_pall},
{"pint", op_pint},
{"add", op_add},
{"swap", op_swap},
{"pop", op_pop},
{"nop", op_nod},
{"sub", op_sub},
{"div", op_div},
{"mul", op_mul},
{"mod", op_mod},
{NULL, NULL}
};
int i = 0;

while (ops[i].opcode != NULL)
{
if (strcmp(ops[i].opcode, s) == 0)
return (ops[i].f);
i++;
}
return (NULL);
}

/**
* deallocate_tokens - frees memory allocated for tokens
* @tokens: pointer to the tokenized input
*/

void deallocate_tokens(char **tokens)
{
int i;

for (i = 0; tokens[i] != NULL; i++)
{
/*free each token*/
free(tokens[i]);
tokens[i] = NULL;
}
/*free the array of tokens*/
free(tokens);
}

/**
*parse_opcode - parses the opcode
*@line: pointer to the file line
*@d: delimeter to create the tokens
*Return: pointer to the tokens array
*/

char **parse_opcode(char *line, const char *d)
{
char **tokens;
char *token;
int token_count = 0;

if (line == NULL || *line == '\0')
return (NULL);

tokens = malloc(1024 * sizeof(char *));
if (tokens == NULL)
{
perror("malloc");
exit(EXIT_FAILURE);
}

token = strtok(line, d);
while (token != NULL)
{
/*save a copy of the token*/
tokens[token_count] = strdup(token);

if (tokens[token_count] == NULL)
{
perror("strdup");
exit(EXIT_FAILURE);
}

token_count++;
token = strtok(NULL, d);
}
tokens[token_count] = NULL;

return (tokens);
}

/**
*process_opcode - processes the opcode
*@line: pointer to the file line
*@counter: line number
*@stack: pointer to the head of the stack
*Return: if error occurs, returns error flag to main function
*/

int  process_opcode(char *line, unsigned int counter,
stack_t **stack)
{
void (*op_func)(stack_t **, unsigned int);
int error_flag = 0;

op_tokens = parse_opcode(line, " \t\n");
if (*line == '\0' || op_tokens == NULL || *op_tokens == NULL)
{
/*Handle empty line or parsing failure*/
free(line);
if (op_tokens != NULL)
deallocate_tokens(op_tokens);
return (1);
}
/*Get the function associated with the opcode*/
op_func = get_op_func(op_tokens[0]);
if (op_func == NULL)
{
/*Handle unknown opcode*/
fprintf(stderr, "L%u: unknown instruction %s\n", counter, op_tokens[0]);
error_flag = 1;
}
else
{
/*Call the function associated with the opcode*/
op_func(stack, counter);
}

deallocate_tokens(op_tokens);
return (error_flag);
}
