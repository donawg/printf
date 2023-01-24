#ifndef PRINTF
#define PRINTF
#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>
int _printf(const char *format, ...);
int _print_c(char c);
int _print_s(char *s);
#endif
