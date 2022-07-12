#include "main.h"
#include <stdarg.h>

/**
 * print_chars - This function prints characters
 *
 * @args: Arguments to be printed
 * Return: On success, it returns 0
 */

int print_chars(va_list args)
{
	return (write_char(va_arg(args, int)));
}
