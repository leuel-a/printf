#include <stdarg.h>
#include "main.h"
#include <stddef.h>

/**
 * _printf - This function mimics the printf function
 * from the <stdio.h> library.
 *
 * @format: This is the string that is to be printed
 * to the stdout, and it might contain format specifiers
 * or not.
 *
 * Return: On succes, it returns the number of charcters
 * that is printed to the stdout
 * On error, -1 is returned.
 */

int _printf(const char *format, ...)
{
	unsigned int i;
	int charsPrinted, formatIdentifier;
	va_list args;

	va_start(args, format);
	if (format == NULL)
		return (-1);
	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			write_char(format[i]);
			charsPrinted++;
			continue;
		}
		if (format[i + 1] == '%')
		{
			write_char('%');
			charsPrinted++;
			i++;
			continue;
		}
		if (format[i + 1] == '\0')
			return (-1);
		formatIdentifier = formatSpecifier(format[i + 1], args);
		if (formatIdentifier == -1 || formatIdentifier != 0)
			i++;
		if (formatIdentifier > 0)
			charsPrinted += formatIdentifier;
		if (formatIdentifier == 0)
		{
			write_char('%');
			charsPrinted++;
		}
	}
	va_end(args);
	return (charsPrinted);
}

/**
 * formatSpecifier - prints special characters
 * @next: character after the %
 * @args: argument for the indentifier
 *
 * Return: the number of characters printed
 * (excluding the null byte used to end output to strings)
 */

int formatSpecifier(char next, va_list args)
{
	int i;

	formatSpecifierStruct formatFunction[] = {
		{"c", print_chars},
		{"s", print_string}

	};

	for (i = 0; formatFunction[i].Identifier != NULL; i++)
	{
		if (formatFunction[i].Identifier[0] == next)
			return (formatFunction[i].print(args));
	}
	return (0);
}
