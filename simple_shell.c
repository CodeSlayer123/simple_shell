#include "shell.h"
/**
 * simple_shell - initializes the shell
 * Return: 0 on success
 */
int simple_shell(void)
{
	char *buffer;
	size_t bufsize = 200000;
	int length;
	char **argv;
	struct stat st;

	buffer = malloc(bufsize * sizeof(char));
	if (buffer == NULL)
	{
		return (-1);
	}
	do {
		printf("#cisnotfun$ ");
		length = getline(&buffer, &bufsize, stdin);

		if (length == EOF)
		{
			putchar('\n');
			free(buffer);
			exit(0);
		}

		if (strcmp(buffer, "exit\n") == 0)
		{
			free(buffer);
			exit(0);
		}
		buffer[strlen(buffer) - 1] = '\0';
		argv = splitter(buffer);

		if (stat(argv[0], &st) == 0)
		{
			execArgs(argv);
		}
		else
		{
		printf("%s: not found\n", argv[0]);
		}

	} while (length != -1);

	free(buffer);
	return (0);
}
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
int execArgs(char **argv)
{
	int status;
	pid_t pid;

	pid = fork();
	if (pid == -1)
	{
		perror("Error:");
		return (-1);
	}
	if (pid == 0)
	{
		execve(argv[0], argv, NULL);
	}
	else
	{
		wait(&status);
	}
	return (0);
}
