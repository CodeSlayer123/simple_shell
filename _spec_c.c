#include "shell.h"

/**
 * _spec_c - Prints a char.
 *
 * @args: The list of arguments passed from printf.
 * Return: Always 1
 */
int _spec_c(va_list *args)
{
	_putchar(va_arg(*args, int));
	return (1);
}