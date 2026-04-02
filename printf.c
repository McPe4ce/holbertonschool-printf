#include "main.h"
#include <stdlib.h>
#include <stdarg.h>

/**
 * _printf - Function that replicates printf, a bit simplier
 * @format: Contains the string that will be passed
 * Return: length (Length of the string)
 */
int _printf(const char *format, ...)
{
	va_list pargument;
	int buffon = 0;
	int length = 0;

	typeuh array[] = {
		{'c', print_char},
		{'s', longueprint2string},
		{'%', print_pour2cent},
		{'d', print_decimal},
		{'i', print_decimal},
		{'\0', NULL},
	};

	if (format == NULL)
	{
		return (-1);
	}

	va_start(pargument, format);
	while (format[buffon] != '\0')
	{
		if (format[buffon] != '%')
		{
			_putchar(format[buffon]);
			length++;
		}
		else
		{
			buffon++;
			if (format[buffon] == '\0')
			{
				va_end(pargument);
				return (-1);
			}
			length += handle_specifier(format[buffon], array, &pargument);
		}
		buffon++;
	}
	va_end(pargument);
	return (length);
}
