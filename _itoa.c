#include "shell.h"
#include <stdio.h>
/**
 * reverse - reverses a string
 * @str: string to reverse
 * @length: length of string
 */
void reverse(char str[], int length)
{
	int i;
	char *tmpPtrA, *tmpPtrB, tmpCh;

	tmpPtrA = str;
	tmpPtrB = str;

	tmpPtrB += length - 1;
	for (i = 0; i < length / 2; i++)
	{
		tmpCh = *tmpPtrB;
		*tmpPtrB = *tmpPtrA;
		*tmpPtrA = tmpCh;
		tmpPtrA++;
		tmpPtrB--;
	}
}

/**
 * _itoa - converts integer to char
 * @n: indexer
 * @str: string to convert
 * @base: base system of numbers
 * Return: returns string
 */
char *_itoa(int n, char *str, int base)
{
	int i;
	int isNeg;
	int remainder;

	isNeg = 0;
	i = 0;
	if (n == 0)
	{
		str[i] = '0';
		str[i + 1] = '\0';
		return (str);
	}
	if (n < 0 && base == 10)
	{
		isNeg = 1;
		n = -n;
	}
	while (n != 0)
	{
		remainder = n % base;
		if (remainder > 9)
		{
			str[i] = remainder - 10 + 'a';
		}
		else
		{
			str[i] = remainder + '0';
		}
		n = n / base;
		i++;
	}
	if (isNeg)
		str[i++] = '-';
	str[i] = '\0';
	reverse(str, i);

	return (str);
}
