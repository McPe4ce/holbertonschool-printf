#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>

/**
 * struct type - Structure that has the map to specifiers with a function
 * @specifier: Specifier that can be triggered
 * @fn: function that points to other printable functions
 */
typedef struct type
{
	char specifier;
	int (*fn)(va_list *);
} typeuh;

int _printf(const char *format, ...);
int _putchar(char c);
int print_char(va_list *pargument);
int longueprint2string(va_list *pargument);
int print_pour2cent(va_list *pargument);
int print_decimal(va_list *pargument);
int handle_specifier(char specifier, typeuh *array, va_list *pargument);

#endif
