#include <stdio.h>
#include "main.h"

int main(void)
{
	int len, _len;

	len = printf("Simple test\n");
	_len = _printf("Simple test\n");
	printf("len: %d - _len = %d\n", len, _len);

	len = printf("print letter %c and then %c\n", 'c', 'C');
	_len = _printf("print letter %c and then %c\n", 'c', 'C');
	printf("len: %d - _len = %d\n", len, _len);

	len = printf("print string %.1s and letter %c\n", "str", 'c');
	_len = _printf("print string %.1s and letter %c\n", "str", 'c');
	printf("len: %d - _len = %d\n", len, _len);

	len = printf("num: %d, neg num: %d\n", 10, -123);
	_len = _printf("num: %d, neg num: %d\n", 10, -123);
	printf("len: %d - _len = %d\n", len, _len);

	return (0);
}
