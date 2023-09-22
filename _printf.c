#include "main.h"
void print_buffer(char buffer[], int *buffer_index);
/**
 * _printf - Printf function todifferent arguments
 * @format: format
 * Return: Print chars
 */
int _printf(const char *format, ...)
{
	int a, print = 0, chars_printed = 0;
	int flags, width, precision, size, buffer_index = 0;
	va_list list;
	char buffer[BUFF_SIZE];

	if (format == NULL)
		return (-1);

	va_start(list, format);

	for (a = 0; format && format[a] != '\0'; a++)
	{
		if (format[a] != '%')
		{
			buffer[buffer_index++] = format[a];
			if (buffer_index == BUFF_SIZE)
				print_buffer(buffer, &buffer_index);
			chars_printed++;
		}
		else
		{
			print_buffer(buffer, &buffer_index);
			flags = get_flags(format, &a);
			width = get_width(format, &a, list);
			precision = get_precision(format, &a, list);
			size = get_size(format, &a);
			++a;
			print = handle_print(format, &a, list, buffer,
				flags, width, precision, size);
			if (print == -1)
				return (-1);
			chars_printed += print;
		}
	}

	print_buffer(buffer, &buffer_index);

	va_end(list);

	return (chars_printed);
}

/**
 * print_buffer - Prints the contents of the buffer if it exist
 * @buffer: Array of chars
 * @buffer_index: Index at which to add next char, represents the length.
 */
void print_buffer(char buffer[], int *buffer_index)
{
	if (*buffer_index > 0)
		write(1, &buffer[0], *buffer_index);

	*buffer_index = 0;
}
