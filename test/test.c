#include <stdio.h>
#include "main.h"

int main(void)
{
	int len, _len;

	len = printf("Simple test\n");
	_len = _printf("Simple test\n");
	printf("len: %d - _len = %d\n", len, _len);
	len = printf("print letter %c\n", 'c');
	_len = _printf("print letter %c\n", 'c');
	printf("len: %d - _len = %d\n", len, _len);
	len = printf("print str %s and letter %c, then str %s\n", "str1", 'c', "str2");
	_len = _printf("print str %s and letter %c, then str %s\n", "str1", 'c', "str2");
	printf("len: %d - _len = %d\n", len, _len);

	return (0);
}
