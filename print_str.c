#include "main.h"
/**
 * print_str - writes the string to standard output
 * @args: input string
 * @buf: buffer pointer
 * @ibuf: index for buffer pointer
 * Return: On success 1.
 */
int print_str(va_list args, char *buf, unsigned int ibuf)
{
	char *str;
	unsigned int a;
	char nill[] = "(null)";

	str = va_arg(args, char *);
	if (str == NULL)
	{
		for (a = 0; nill[a]; a++)
			ibuf = handle_buffer(buf, nill[a], ibuf);
		return (6);
	}
	for (a = 0; str[a]; a++)
		ibuf = handle_buffer(buf, str[a], ibuf);
	return (a);
}
