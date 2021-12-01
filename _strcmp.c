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
