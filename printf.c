#include "main.h"

/**
 * _printf - prints to the standard output
 * @format: format string composed of any number of directives
 *
 * Return: number of characters printed excluding the null byte
 */
int _printf(const char *format, ...)
{
	va_list ap;
	int i, count;
	char char_i, char_n;

	va_start(ap, format);

	for (i = 0; format[i] != '\0'; i++)
	{
		char_i = format[i];
		if (char_i == '%')
		{
			char_n = format[i + 1];
			if (char_n == 'c')
				count += _print_c(va_arg(ap, int));
			if (char_n == 's')
				count += _print_s(va_arg(ap, char *));
			i++;
		}
		else
		{
			write(1, format + i, 1);
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
 *
 * Return: number of characters written
 */
int _print_s(char *s)
{
	int size;

	size = (int) sizeof(s) - 1;
	write(1, s, size);

	return (size);
}
