#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>

int write_char(char c);
int _printf(const char *format, ...);
int print_chars(va_list);
int formatSpecifier(char next, va_list args);
int print_string(va_list args);

typedef struct formatSpecifierStruct {
	char *Identifier;
	int (*print)(va_list);
} formatSpecifierStruct;

#endif
