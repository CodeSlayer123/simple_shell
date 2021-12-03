#include "shell.h"

/**
 * main - Initiates the shell.
 * Return: 0 on success
 */
int main(int ac, char **av)
{
    if (ac > 1)
    {
        _printf("%s: 0: Can't open %s\n", av[0], av[1]);
        return (127);
    }
	simple_shell(av);
	return (0);
}