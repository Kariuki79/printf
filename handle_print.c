#include "main.h"
/**
 * handle_print - Prints an argument based on its type
 * @str_format: string in which to print the arguments
 * @list: list of arguments to be printed
 * @index: index
 * @buffer: Buffer array to handle print.
 * @flags: Calculates active flags
 * @width: width
 * @precision: Precision
 * @size: Size specifier
 * Return: (1) or (2)
 */
int handle_print(const char *str_format, int *index, va_list list, char buffer[],
	int flags, int width, int precision, int size)
{
	int i, len = 0, chars_printed = -1;
	str_format_t str_format_types[] = {
		{'c', print_char}, {'s', print_string}, {'%', print_percent},
		{'i', print_int}, {'d', print_int}, {'b', print_binary},
		{'u', print_unsigned}, {'o', print_octal}, {'x', print_hexadecimal},
		{'X', print_hexa_upper}, {'p', print_pointer}, {'S', print_non_printable},
		{'r', print_reverse}, {'R', print_rot13string}, {'\0', NULL}
	};
	for (i = 0; str_format_types[i].str_format != '\0'; i++)
		if (str_format[*index] == str_format_types[i].str_format)
			return (str_format_types[i].fn(list, buffer, flags, width, precision, size));

	if (str_format_types[i].str_format == '\0')
	{
		if (str_format[*index] == '\0')
			return (-1);
		len += write(1, "%%", 1);
		if (str_format[*index - 1] == ' ')
			len += write(1, " ", 1);
		else if (width)
		{
			--(*index);
			while (str_format[*index] != ' ' && str_format[*index] != '%')
				--(*index);
			if (str_format[*index] == ' ')
				--(*index);
			return (1);
		}
		len += write(1, &str_format[*index], 1);
		return (len);
	}
	return (chars_printed);
}
