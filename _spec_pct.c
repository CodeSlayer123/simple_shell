#include "shell.h"
#include <stdarg.h>

/**
 * _spec_pct - Prints a single percent sign.
 *
 * @args: The argument list passed from _printf.
 * Return: Always 1.
 */
int _spec_pct(va_list *args)
{
	(void)(args);

	_putchar('%');
	return (1);
}
