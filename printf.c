#include "main.h"
#include <stdlib.h>
#include <stdarg.h>

/**
 * print_char - Function that prints a char
 * Return: 1 (Success)
 * @pargument: argument list
 */
static int print_char(va_list *pargument)
{
	_putchar((char)va_arg(*pargument, int));
	return (1);
}

/**
 * longueprint2string - Function that prints the length of the string
 * and the string
 * Return: longueru (The length of the string)
 * @pargument: argument list
 */
static int longueprint2string(va_list *pargument)
{
	char *string = va_arg(*pargument, char *);
	int longueru = 0;

	if (string == NULL)
	{
		string = "(null)";
	}

	while (*string)
	{
		_putchar(*string);
		string++;
		longueru++;
	}

	return (longueru);
}

/**
 * print_pour2cent - Function that prints the %
 * Return: 1 (Success)
 * @pargument: argument list
 */
static int print_pour2cent(va_list *pargument)
{
	(void)pargument;
	_putchar('%');
	return (1);
}

/**
 * handle_specifier - handles format specifiers after '%'
 * @specifier: The specifier after %
 * @array: Array that has the specifier
 * @pargument: argument list
 * Return: number of printed characters
 */
static int handle_specifier(char specifier, typeuh *array, va_list *pargument)
{
	int spaghetti = 0;

	while (array[spaghetti].specifier != '\0')
	{
		if (array[spaghetti].specifier == specifier)
			return (array[spaghetti].fn(pargument));
		spaghetti++;
	}
	_putchar('%');
	_putchar(specifier);
	return (2);
}

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
