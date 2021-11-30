#include "shell.h"
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
	int i = 0;
	int j = 0;

	while (dest[i] != '\0')
	{
		i++;
	}
	while (src[j] != '\0')
	{
		dest[i] = src[j];
		i++;
		j++;

	}
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
	if (__environ[i])
		return (__environ[i] + l + 1);
	return (NULL);
}
