#include "shell.h"
/**
 * simple_shell - initializes the shell
 * Return: 0 on success
 */
int simple_shell(__attribute__((unused)) char **av)
{
	size_t bufsize = 2097152;
	char *buffer = malloc(bufsize * sizeof(char)), *tmp = buffer;
	char **argv;
	int length, exitStatus = 0, count = 0;

	if (buffer == NULL)
		return (-1);
	do {
		if (isatty(STDIN_FILENO))
			_printf("$ ");
		length = getline(&buffer, &bufsize, stdin);
		count++;
		if (length == EOF)
		{
			if (isatty(STDIN_FILENO))
				_printf("\n");
			free(tmp);
			exit(0);
		}

		if (_strcmp(buffer, "\n") == 0)
			continue;

		else
		{
			if (buffer[_strlen(buffer) - 1] == '\n')
				buffer[_strlen(buffer) - 1] = '\0';
			while (*buffer == ' ')
				buffer++;
			if (_strcmp(buffer, " ") == 0)
				continue;
			else
			{
				argv = splitter(buffer);
				if (_strcmp(argv[0], "exit") == 0)
				{
					free(tmp);
					free(argv);
					exit(exitStatus);
				}
				exitStatus = checkArgs(argv);
			}
		}
		free(argv);
	} while (length != -1);
	return (0);
}
/**
 * checkArgs - Checks for builtins and other commands in the PATH
 *
 * @argv: The array of arguments passed into shell
 * @st: The stat structure to use when checking for args
 * Return: 0 on success
 */
int checkArgs(char **argv)
{
	char **path = _getPath();
	char *execPath = malloc(sizeof(char) * 1024);
	int i = 0, exitStatus = 0;
	struct stat st;
/**
	cwd = getcwd(cwd, 1024);

	if (_strcmp(argv[0], "cd") == 0)
	{
		cwd = execCD(argv, cwd, hd);
	}
	*/
	if (_strcmp(argv[0], "env") == 0)
	{
		execEnv();
	}
	else if (_strchr(argv[0], '/'))
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
			_printf("%s", path[i]);
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
	free(path), free(execPath);
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
	int i;

	for (i = 0; argv[i] != NULL; i++)
	{
		if (argv[i + 1] == NULL)
			argv[i + 1] = '\0';
	}
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
/**
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
		printf("./hsh: cd: %s: No such file or directory\n", argv[1]);
	cwd = getcwd(cwd, 1024);
	return (cwd);
}
*/
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
