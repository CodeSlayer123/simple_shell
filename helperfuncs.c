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
	char **splitpath = malloc(sizeof(char *) * 1024);

	for (i = 0; i < 1024; i++)
	{
		splitpath[i] = NULL;
	}
	path = _getenv("PATH");
	if (splitpath == NULL)
	{
		free(path), free(splitpath);
		return (0);
	}
	pathtok = strtok(path, ":");

	for (i = 0; pathtok != NULL; i++)
	{
		splitpath[i] = pathtok;
		pathtok = strtok(NULL, ":");

	}
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
	dest[i] = '\0';
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
 * @name: name
 * Return: path on success
 */
char *_getenv(const char *name)
{
	int i;
	size_t l = strlen(name);

	if (!__environ || !*name || strchr(name, '='))
	return (NULL);

	for (i = 0; __environ[i] && (strncmp(name, __environ[i], l)
		|| __environ[i][l] != '='); i++)
		;

	if (__environ[i])
	return (__environ[i] + l + 1);

	return (NULL);
}

/**
 * _strchr - Locates a character in a string.
 *
 * @s: the string to be searched
 * @c: The character to find
 *
 * Return: The pointer to the first occurence of c, or NULL if not found.
 */
char *_strchr(char *s, char c)
{
	unsigned int i;
	char *p = s;

	for (i = 0; s[i] != '\0'; i++)
	{
		if (s[i] == c)
		{
			return (p);
		}
		p = p + 1;
	}
return (NULL);
}
