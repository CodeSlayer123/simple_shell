#include "shell.h"
#include <stdio.h>

/**
 * _strcmp - returns the difference between two strings.
 *
 * @s1: The first string to compare
 * @s2: The second string to compare
 * Return: The difference between the two strings.
 */
int _strcmp(char *s1, char *s2)
{
	int i;

	for (i = 0; s1[i] != '\0'; i++)
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
	}
return (0);
}

/**
 * _strcmp2 - Returns the difference between two strings.
 *
 * @s1: The first string to compare
 * @s2: The second string to compare
 * Return: The difference
 */
int _strcmp2(char s1, char *s2)
{
	int diff = 1;

	while (*s2 != '\0')
	{
		if (s1 == *s2)
		{
			diff = 0;
		}
		s2++;
	}
	return (diff);
}

/**
 * _strdup - Copies a string to a new memory area
 *
 * @str: The string to be copies
 *
 * Return: A pointer to the copy of the string
 */
char *_strdup(char *str)
{
	char *s;
	int size = 0;
	int i;

	if (str == NULL)
	{
		return (NULL);
	}
	while (*str != '\0')
	{
		size++;
		str++;
	}
	str = str - size;
	s = malloc((size + 1) * sizeof(char));
	if (s == NULL)
	{
		free(s);
		return (NULL);
	}

	for (i = 0; i < size; i++)
	{
		s[i] = str[i];
	}
	s[i] = '\0';
	return (s);
}
