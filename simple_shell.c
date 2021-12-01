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
	char **argv;
	int length;
	struct stat st;
	char **path = _getPath();
	char *execPath = malloc(sizeof(char) * 1024);
	int i;
	char *cwd = getcwd(cwd, bufsize), *hd = getcwd(cwd, bufsize);
	int cd;

	if (buffer == NULL)
		return (-1);
	do {
		printf("#cisnotfun$ ");
		length = getline(&buffer, &bufsize, stdin);
		if (length == EOF)
		{
			putchar('\n');
			free(buffer);
			exit(-1);
		}
		if (buffer[strlen(buffer) - 1] == '\n')
			buffer[strlen(buffer) - 1] = '\0';
		argv = splitter(buffer);
		if (strcmp(argv[0], "exit") == 0)
		{
			printf("exit\n");
			if (!argv[1] || (argv[1][0] >= '0' && argv[1][0] <= '9'))
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
		if (strcmp(argv[0], "cd") == 0)
		{
			cwd = execCD(argv, cwd, hd);
			continue;
		}
		if (strchr(argv[0], '/'))
		{
			if (stat(argv[0], &st) == 0)
				executePath(argv[0], argv);
			else
				printf("%s: not found\n", argv[0]);
		}
		else
		{
			for (i = 0; path[i] != NULL; i++)
			{
				strcpy(execPath, path[i]);
				strcat(execPath, "/");
				strcat(execPath, argv[0]);
				if (stat(execPath, &st) == 0)
				{
					executePath(execPath, argv);
					break;
				}
			}
			if (path[i] == NULL)
				printf("%s: not found\n", argv[0]);
		}
	} while (length != -1);
	free(buffer);
return (0);
}

int executePath(char *execPath, char **argv)
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
		execve(execPath, argv, NULL);
	}
	else
	{
		wait(&status);
	}
	return (0);
}

char *execCD(char **argv, char *cwd, char *hd)
{
	int cd;
	
	cd = chdir(argv[1]);
	if (!argv[1])
		cd = chdir(hd);
	if (cd != 0)
		printf("./hsh: cd: %s: No such file or directory\n", argv[1]);
	cwd = getcwd(cwd, 1024);
	return (cwd);
}
