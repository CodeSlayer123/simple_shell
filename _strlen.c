#include "shell.h"
#include <stdio.h>

/**
 * _strlen - returns the length of a string.
 *
 * @s: The string to be measured
 * Return: the length
 */
int _strlen(char *s)
{
	int i = 0;

	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}
