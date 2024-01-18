#include "monty.h"
char **op_tokens = NULL;

/**
*main- entry point
*@argc: number of arguments
*@argv: array of arguments
*Return: 0 on success
*/

int main(int argc, char *argv[])
{
FILE *fp;
char *line = NULL;
size_t size = 0;
unsigned int counter = 0;
ssize_t read = 1;
stack_t *head = NULL;

if (argc != 2)
{
fprintf(stderr, "USAGE: monty file\n");
return (EXIT_FAILURE);
}
if (access(argv[1], R_OK) == -1)
{
fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
return (EXIT_FAILURE);
}
/*open file*/
fp = fopen(argv[1], "r");
if (fp == NULL)
exit(EXIT_FAILURE);
while (read > 0)
{
read = getline(&line, &size, fp);
if (read == -1)
{
free(line);
line = NULL;
}
else if (read > 0)
{
counter++;
process_opcode(line, counter, &head, fp);
}
free(line);
line = NULL;
}
free_dlistint(head);
fclose(fp);
return (0);
}
