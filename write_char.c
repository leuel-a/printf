#include <unistd.h>
#include "main.h"

/**
 * write_char - writes a character c to the stdout
 *
 * Return: On success 1.
 * On error, -1 is returned.
 */

int write_char(char c)
{
	return (write(1, &c, 1));
}
