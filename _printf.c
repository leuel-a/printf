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
	int charsPrinted;
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
	}
	return (charsPrinted);
}
