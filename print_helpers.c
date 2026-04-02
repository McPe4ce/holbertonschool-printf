#include "main.h"
#include <stdarg.h>
#include "stdlib.h"

/**
 * print_char - Function that prints a char
 * Return: 1 (Success)
 * @pargument: argument list
 */
int print_char(va_list *pargument)
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
int longueprint2string(va_list *pargument)
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
int print_pour2cent(va_list *pargument)
{
	(void)pargument;
	_putchar('%');
	return (1);
}

/**
 * print_decimal - Function that prints a decimal or integer
 * Return: number of characters printed
 * @pargument: argument list
 */
int print_decimal(va_list *pargument)
{
	int num = va_arg(*pargument, int);
	unsigned int n;
	char buffer[20];
	int i = 0;
	int count = 0;

	if (num < 0)
	{
		_putchar('-');
		count++;
		n = (unsigned int)(-num);
	}
	else
	{
		n = (unsigned int)num;
	}

	if (n == 0)
	{
		_putchar('0');
		return (count + 1);
	}

	while (n > 0)
	{
		buffer[i] = '0' + (n % 10);
		n /= 10;
		i++;
	}

	for (i--; i >= 0; i--)
	{
		_putchar(buffer[i]);
		count++;
	}

	return (count);
}

/**
 * handle_specifier - handles format specifiers after '%'
 * @specifier: The specifier after %
 * @array: Array that has the specifier
 * @pargument: argument list
 * Return: number of printed characters
 */
int handle_specifier(char specifier, typeuh *array, va_list *pargument)
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
