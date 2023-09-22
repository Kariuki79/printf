#include "main.h"
/**
 * get_width - calculates the width for printing
 * @format: formatted string
 * @i: list of arguments to display
 * @list: list of arguments
 * Return: (width)
 */
int get_width(const char *format, int *i, va_list list)
{
	int ci;
	int w = 0;

	for (ci = *i + 1; format[ci] != '\0'; ci++)
	{
		if (is_digit(format[ci]))
		{
			w *= 10;
			w += format[ci] - '0';
		}
		else if (format[ci] == '*')
		{
			ci++;
			w = va_arg(list, int);
			break;
		}
		else
			break;
	}

	*i = ci - 1;

	return (w);
}
