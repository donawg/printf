#ifndef PRINTF
#define PRINTF
#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>
/**
 * struct specifier - information on format specifiers
 * @type: type (eg. c, s, d)
 * @precision: if not specified, -1
 * @jump: number of chars used for specifier
 */
typedef struct specifier
{
	char type;
	int precision;
	int jump;
} spec_t;
int _printf(const char *format, ...);
spec_t specifier_handler(const char *s);
int _print_c(char c);
int _print_s(char *s, int precision);
#endif
