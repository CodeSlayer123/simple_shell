#include "shell.h"
/**
 * _getPath - gets path
 * Return: splitpath
 */
char **_getPath(void)
{
	char *pathtok;
	char *path;
	int i;
	char **splitpath;

	path = _getenv("PATH");
	splitpath = malloc(sizeof(char) * 1024);

	if (splitpath == NULL)
	{
		free(path);
		return (0);
	}
	pathtok = strtok(path, ":");

	for (i = 0; pathtok != NULL; i++)
	{
		splitpath[i] = pathtok;
		pathtok = strtok(NULL, ":");

	}
	free(path);
	return (splitpath);
}
/**
 * _strcpy - copies string
 * @dest: destination to be copied to
 * @src: source to be copied
 * Return: Always 0
 */
char *_strcpy(char *dest, char *src)
{

	int i;

	for (i = 0; src[i] != '\0'; i++)
	{
		dest[i] = src[i];
	}
	dest[i++] = '\0';
	return (dest);
}
/**
 * _strcat - concatenates two strings
 * @dest: first number
 * @src: second number
 * Return: Always 0
 */
char *_strcat(char *dest, char *src)
{
	int len = 0;
	int i = 0;

	while (*(dest + len) != '\0')
	{
		len++;
	}
	for (i = 0; *(src + i) != '\0'; i++)
	{
		*(dest + len) = *(src + i);
		len++;
	}

	*(dest + len) = *(src + i);
	return (dest);
}
/**
 * _getenv - gets environmental variables
 * @var: name
 * Return: path on success
 */
char *_getenv(char *var)
{
	char *envvar = malloc(sizeof(char) * 1024);
	char *envfinal = malloc(sizeof(char) * 1024);
	char *envtok;
	int x, len = _strlen(var);

	for (x = 0; environ[x] != NULL; x++)
	{
		if (strncmp(var, environ[x], len) == 0)
		{
			_strcpy(envvar, environ[x]);
			envtok = strtok(envvar, "=");
			envtok = strtok(NULL, "=");
			_strcpy(envfinal, envtok);
		}
	}
	free(envvar);
	return (envfinal);
}
