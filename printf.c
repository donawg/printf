#include "main.h"

/**
 * specifier_handler - returns speciier struct
 * @s: string beginning with specifier's %
 *
 * Return: specier struct
 */
spec_t specifier_handler(const char *s)
{
	spec_t specifier;
	int i, precision;
	char next, type;

	i = 1;
	precision = -1;
	next = s[i];

	if (next == '.')
	{
		precision = 0;
		next = s[++i];
		while (next >= 48 && next < 58)
		{
			precision *= 10;
			precision += (next - 48);
			next = s[++i];
		}
	}
	type = next;
	specifier.type = type;
	specifier.precision = precision;
	specifier.jump = i;

	return (specifier);
}

/**
 * _printf - prints to the standard output
 * @format: format string composed of any number of directives
 *
 * Return: number of characters printed excluding the null byte
 */
int _printf(const char *format, ...)
{
	va_list ap;
	spec_t specifier;
	int i, count, spec_p, spec_j;
	char char_i, spec_t;

	va_start(ap, format);
	count = 0;

	for (i = 0; format[i] != '\0'; i++)
	{
		char_i = format[i];
		if (char_i == '%')
		{
			specifier = specifier_handler(format + i);
			spec_t = specifier.type;
			spec_p = specifier.precision;
			spec_j = specifier.jump;

			if (spec_t == 'c')
				count += _print_c(va_arg(ap, int));
			else if (spec_t == 's')
				count += _print_s(va_arg(ap, char *), spec_p);
			else if (spec_t == 'd' || spec_t == 'i')
				count += _print_d_i(va_arg(ap, int), spec_p);
			i += spec_j;
		}
		else
		{
			write(1, format + i, 1);
			count += 1;
		}
	}

	va_end(ap);
	return (count);
}

/**
 * _print_c - print a character
 * @c: char to print
 *
 * Return: 1 if printable character, else 0
 */
int _print_c(char c)
{
	int size;

	size = write(1, &c, 1);
	return (size);
}

/**
 * _print_s - prints a string
 * @s: string to print
 * @precision: if >=0, max chars to print
 *
 * Return: number of characters written
 */
int _print_s(char *s, int precision)
{
	int size;

	if (precision >= 0)
		for (size = 0; s[size] != '\0' && size < precision; size++)
			_print_c(s[size]);
	else
		for (size = 0; s[size] != '\0'; size++)
			_print_c(s[size]);

	return (size);
}

/**
 * _print_d_i - prints an int
 * @i: int to print
 * @precision:number of digits to print, or padding for extra
 *
 * Return: number of characters written
 */
int _print_d_i(int i, int precision)
{
	int size, max;

	max = precision;
	max = 1;
	size = 0;

	if (i < 0)
	{
		_print_c('-');
		i *= -1;
		size++;
	}

	while (i >= max)
		max *= 10;
	max /= 10;
	while (max)
	{
		_print_c(48 + (i / max));
		i %= max;
		max /= 10;
		size++;
	}

	return (size);
}
