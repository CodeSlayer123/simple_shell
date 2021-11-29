#include "shell.h"

/**
 * _spec_u - prints unsigned int
 * @args: variadic uint to print from pr_uints
 * Return: returns length of str - 1
 */
int _spec_u(va_list *args) 
{
	unsigned int n = va_arg(*args, unsigned int);
	int i;
	char *str;
	char s[13];

	if (n / 10 != 0)
		pr_uints(n / 10);
	_putchar((n % 10) + '0');
	str = _itoa(n, s, 10);
	for (i = 0; str[i] != '\0'; i++)
		continue;
	return (i - 1);
}
/**
 * pr_uints - function to pass into pr_uint
 * @c: unsigned int to pass
 * 
 */
void pr_uints(unsigned int c)
{
	if (c / 10 != 0)
		pr_uints(c  / 10);
	_putchar((c % 10) + '0');
}
/**
 * _spec_di - prints an integer
 * @args: variadic int to print
 * Return: returns i
 */
int _spec_di(va_list *args) 
{
	int i;
	char s[13];
	char *a;
	int num = va_arg(*args, int);

	if (num == INT_MIN)
	{
		i = print_min();
		return (i);
	}

	a = _itoa(num, s, 10);
	for (i = 0; a[i] != '\0'; i++)
		_putchar(a[i]);
	return (i);
}

/**
 * print_min - prints the smallest integer possible and increments
 * Return: returns i
 *
 */
int print_min(void)
{
	int i = 0;
	char *int_min = "-2147483648";

	while (*int_min != '\0')
	{
		_putchar(*int_min);
		i++;
		int_min++;
	}
	return (i);
}
/**
 * print_max - prints the largest integer possible and decrements
 * Return: returns i
 *
 */
int print_max(void)
{
	int i = 0;
	char *int_max = "2147483648";

	while (*int_max != '\0')
	{
		_putchar(*int_max);
		i--;
		int_max--;
	}
	return (i);
}