#include "main.h"
#include <stdarg.h>
#include <stddef.h>

/**
 * print_string - This function prints a string
 *
 * @args: The argument
 *
 * Return: The number of characters printed
 */

int print_string(va_list args)
{
	int i;
	char *str = va_arg(args, char*);

	if (str == NULL)
		str = "(null)";
	else if (*str == '\0')
		return (-1);

	for (i = 0; str[i]; i++)
		write_char(str[i]);

	return (i);
}
