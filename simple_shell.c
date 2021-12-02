#include "shell.h"
char *hd;
/**
 * simple_shell - initializes the shell
 * Return: 0 on success
 */
int simple_shell(void)
{
	size_t bufsize = 200000;
	char *buffer = malloc(bufsize * sizeof(char));
	char **argv;
	int length, exitStatus = 0;
	struct stat st;

	hd = getcwd(hd, 1024);
	if (buffer == NULL)
		return (0);
	do {
		if (isatty(STDIN_FILENO))
			_printf("$ ");
		length = getline(&buffer, &bufsize, stdin);
		if (length == EOF)
		{
			if (isatty(STDIN_FILENO))
				_printf("\n");
			if (argv != NULL)
				free(argv);
			free(buffer);
			exit(0);
		}
		if (buffer[_strlen(buffer) - 1] == '\n')
			buffer[_strlen(buffer) - 1] = '\0';
		argv = splitter(buffer);
		if (strcmp(argv[0], "exit") == 0)
		{
				free(buffer);
				free(argv);
				exit(exitStatus);
		}
		exitStatus = checkArgs(argv, st);
	} while (length != -1);
	free(buffer);
return (0);
}
/**
 * checkArgs - Checks for builtins and other commands in the PATH
 *
 * @argv: The array of arguments passed into shell
 * @st: The stat structure to use when checking for args
 * Return: 0 on success
 */
int checkArgs(char **argv, struct stat st)
{
	char **path = _getPath();
	char *execPath = malloc(sizeof(char) * 1024);
	char *cwd = malloc(sizeof(char));
	int i, exitStatus = 0;

	cwd = getcwd(cwd, 1024);

	if (strcmp(argv[0], "cd") == 0)
	{
		cwd = execCD(argv, cwd, hd);
	}
	else if (strcmp(argv[0], "env") == 0)
	{
		execEnv();
	}
	else if (strchr(argv[0], '/'))
	{
		if (stat(argv[0], &st) == 0)
			executePath(argv[0], argv);
		else
			_printf("%s: not found\n", argv[0]), exitStatus = 127;
	}
	else
	{
		for (i = 0; path[i] != NULL; i++)
		{
			_strcpy(execPath, path[i]);
			_strcat(execPath, "/");
			_strcat(execPath, argv[0]);
			if (stat(execPath, &st) == 0)
			{
				executePath(execPath, argv);
				break;
			}
		}
		if (path[i] == NULL)
			_printf("%s: not found\n", argv[0]), exitStatus = 127;
	}
return (exitStatus);
}
/**
 * executePath - executes a program found on the PATH.
 *
 * @execPath: The destination path of the program
 * @argv: The array of arguments passed into shell
 * Return: 0 on success
 */
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
/**
 * execCD - Changes the current working directory
 *
 * @argv: The array of arguments passed into the shell
 * @cwd: The current working directory
 * @hd: The home directory of the shell
 * Return: A pointer to the new current working directory.
 */
char *execCD(char **argv, char *cwd, char *hd)
{
	int cd;

	if (!argv[1])
		cd = chdir(hd);
	else
	{
		cd = chdir(argv[1]);
	}
	if (cd != 0)
		_printf("./hsh: cd: %s: No such file or directory\n", argv[1]);
	cwd = getcwd(cwd, 1024);
	return (cwd);
}
/**
 * execEnv - Displays the entire working environment variable.
 * Return: 0 on success
 */
int execEnv(void)
{
	int i;

	for (i = 0; environ[i] != NULL; i++)
		_printf("%s\n", environ[i]);

return (0);
}
