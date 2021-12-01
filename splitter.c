#include "shell.h"

/**
 * splitter - splits the newline into separate arguments
 *
 * @fun: The newline entered by the user
 * Return: An array of character pointers, separated by a whitespace.
 */
char **splitter(char fun[])
{
	char **holder;
	char *tmp;
	long int length = strlen(fun);
	int i = 0;

	holder = malloc(sizeof(char) * (length * 2));

	tmp = strtok(fun, " ");
	holder[i] = tmp;
	while (tmp != NULL)
	{
		i++;
		tmp = strtok(NULL, " ");
		holder[i] = tmp;
	}
	return (holder);
}
