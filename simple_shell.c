#include "shell.h"
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
/**
 * simple_shell - initializes the shell
 * Return: 0 on success
 */
int simple_shell(void)
{
	size_t bufsize = 200000;
	char *buffer = malloc(bufsize * sizeof(char));
	int length;
	char **argv;
	struct stat st;
	char *pwd = getcwd(pwd, bufsize);
	int cd;

	if (buffer == NULL)
		return (-1);
	do {
		printf("#%s cisfun$ ", pwd);
		length = getline(&buffer, &bufsize, stdin);
		if (length == EOF)
		{
			putchar('\n');
			free(buffer);
			exit(0);
		}

		buffer[strlen(buffer) - 1] = '\0';
		argv = splitter(buffer);

		if (strcmp(argv[0], "exit") == 0)
		{
			printf("exit\n");
			if (!argv[1])
			{
				free(buffer);
				exit(0);
			}
			else
			{
				if (argv[1][0] >= '0' && argv[1][0] <= '9')
				{
					free(buffer);
					exit(0);
				}
				else
				{
					printf("./hsh: exit: ");
					printf("%s: numeric argument required\n", argv[1]);
					free(buffer);
					exit(0);
				}
			}

		}

		if (_strcmp(argv[0], "cd") == 0)
		{
			cd = chdir(argv[1]);
			if (cd != 0)
			{
				printf("./hsh: cd: %s: No such file or directory\n", argv[1]);
			}
			pwd = getcwd(pwd, bufsize);
			continue;
		}
		if (_strcmp(argv[0], "pwd") == 0)
		{
			_printf("%s\n", pwd);
			continue;
		}

		if (stat(argv[0], &st) == 0)
		{
			execArgs(argv);
		}
		else
		{
			printf("%s: 1: %s: not found\n", "./hsh", argv[0]);
		}

	} while (length != -1);

	free(buffer);
	return (0);
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
	if (pid != 0)
	{
		wait(&status);
	}
	if (pid == 0)
	{
		execve(argv[0], argv, NULL);
	}

return (0);
}
