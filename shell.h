#ifndef SHELL_H
#define SHELL_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdarg.h>
#include <stddef.h>
#include <limits.h>

/**
 * struct function - a function struct for _printf
 * @spec: The conversion specifier
 * @funct: A function pointer to the corresponding conversion spec
 * Description: A structure to connect a
 * conversion specifier with the corresponding
 * function when using _printf.
 */
typedef struct function
{
	char *spec;
	int (*funct)(va_list *);
} fun_t;

extern char **environ;

int simple_shell(char **av);
char **splitter(char fun[]);
char *execCD(char **argv, char *cwd, char *hd);
int execEnv(void);
int execArgs(char **argv);
int executePath(char *execPath, char **argv);
int checkArgs(char **argv);
int _strcmp(char *s1, char *s2);
int _strcmp2(char s1, char *s2);
int _strlen(char *s);
int (*_get_func(char s))(va_list *args);
int _printf(const char *format, ...);
int _putchar(char c);
int _spec_c(va_list *args);
int _spec_u(va_list *args);
int _spec_s(va_list *args);
int _spec_di(va_list *args);
int _spec_pct(va_list *args);
void pr_uints(unsigned int c);
char *_itoa(int n, char *str, int base);
void reverse(char str[], int length);
int print_min(void);
int _isdigit(int c);
char *_strcpy(char *dest, char *src);
char *_strcat(char *dest, char *src);
char *_strchr(char *s, char c);
char *_strdup(char *str);
char *_getenv(char *var);
char **_getPath(void);

#endif
