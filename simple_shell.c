#include "shell.h"
/**
 * simple_shell - initializes the shell
 * Return: 0 on success
 */
int simple_shell(void)
{
	char *buffer;
	size_t bufsize;
	ssize_t length;

	buffer = malloc(bufsize * sizeof(char));

	do {
		printf("#cisnotfun$ ");
		length = getline(&buffer, &bufsize, stdin);

		if (length == EOF)
		{
			putchar('\n');
			break;
		}

		if (strcmp(buffer, "exit\n") == 0)
		{
			break;
		}

		printf("./shell: No such file or directory\n");

	} while (length != -1);

	free(buffer);
	return (0);
}
