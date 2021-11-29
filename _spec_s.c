#include "shell.h"

/**
 * _spec_s - Prints a string.
 *
 * @args: The list of args passed from _printf.
 * Return: The length of the string.
 */
int _spec_s(va_list *args)
{
	int i;
	char *str = va_arg(*args, char *);

	for (i = 0; str[i] != '\0'; i++)
	{
		_putchar(str[i]);
	}

	return (i - 1);
}