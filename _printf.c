#include "shell.h"

/**
 * _get_func - gets the function for a conversion specifier.
 *
 * @s: The conversion specifier
 * Return: The function matching the conversion specifier
 */
int (*_get_func(char s))(va_list * args)
{
	fun_t fun[] = {
		{"c", _spec_c},
		{"s", _spec_s},
		{"d", _spec_di},
		{"i", _spec_di},
		{"u", _spec_u},
		{"%", _spec_pct},
		{NULL, NULL}
	};
	int i = 0;

	if (!s)
	{
		exit(1);
	}
	while (fun[i].spec != NULL)
	{
		if (_strcmp2(s, fun[i].spec) == 0)
		{
			return (fun[i].funct);
		}
		i++;
	}

return (NULL);
}

/**
 * _printf - Printf equivalent
 *
 * @format: The first string, containing conversion statements
 * Return: returns length of the string
 */

int _printf(const char *format, ...)
{
	va_list args;
	int (*func)(va_list *); /* funct ptr to find funct for spec */
	int x = 0;  /* input incrementer variable */
	int tot = 0;  /* length of output string */

	va_start(args, format);
	if (!format)
	{
		return (-1);
	}
	while (format && format[x])
	{
		if (format[x] == '%')
		{
			x++;
			func = _get_func(format[x]);
			if (func != NULL)
			{
				tot += func(&args);
			}
			else
			{
				tot +=	_putchar('%');
				tot += _putchar(format[x]);
			}
			x++;
		}
		else
		{
			tot += _putchar(format[x]);
			x++;
		}
	}
	va_end(args);
	return (tot);
}
