#include "main.h"
/**
 * _printf - checks for characters in format
 * @format: holds the characters to be printed
 * Return: print characters
 */

void print_buffer(char buffer[], int *buf_index);
int _printf(const char *format, ...)
{
	int a;
	int printed = 0;
	int chars_printed = 0;
	int flags;
	int width;
	int precision;
	int size;
	int buffer_i = 0;
	va_list args;
	char buffer[BUFF_SIZE];

	if (format == NULL)
		return (-1);
	va_start(args, format);
	for (a = 0; format && format[a] != '\0'; i++)
	{
		if (format[a] != '%')
		{
			buffer[buffer_i++] = format[a];
			if (buffer_i == BUFF_SIZE)
				print_buffer(buffer, &buffer_i);
			chars_printed++;
		}
		else
		{
			printf_buffer(buffer, &buffer_i);
			flags = get_flags(format, &i);
			width = get_width(format, &i, args);
			precision = get_precision(format, &i, args);
			size = get_size(format, &i);
			++i;
			printed = handle_print(format, &i, args, buffer, flags, width, precision, size);
			if (printed == -1)
				return (-1);
			chars_printed = chars_printed + printed;
		}
	}
	print_buffer(buffer, &buffer_i);
	va_end(args);
	return (chars_printed);
}
/**
 * print_buffer - receives characters in a buffer and prints the contents
 * @buffer: contains array of characters
 * @buffer_i: lenght of characters in the array
*/
