#include "main.h"
#include <stdio.h>
/**
 * print_chr - writes the character c to standard output
 * @arguments: input character
 * @buf: buffer pointer
 * @ibuf: index for buffer pointer
 * Return: On success 1
 */
int print_chr(va_list args, char *buf, unsigned int ibuf)
{
	char c;

	c = va_arg(args, int);
	handle_buffer(buf, c, ibuf);
	return (1);
}
