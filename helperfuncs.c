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

	path = _getenv("PATH");
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
char *_getenv(char *env)
{
	int content, line;
	char *name = NULL;
	/* iterate each line in the environment */
	for (line = 0; environ[line] != NULL; line++)
	{ /* iterate each letter until we see a = */
		for (content = 0; environ[line][content] != '='; content++)
		{
			if (environ[line][content] != env[content])
			{
				break;
			} /* check that this env var name is what we're looking for */
			if (environ[line][content] == env[content])
			{ /* we've hit the end of our search string */
				if (env[content + 1] == '\0' &&
					environ[line][content + 1] == '=')
				{ /* duplicate everything past the equals */
					name = _strdup(
						&(environ[line][content + 2]));
					return (name);
				}
			}
		}
	}
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
