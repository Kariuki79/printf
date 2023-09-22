#include "main.h"
/**
 * handle_print - Prints an argument based on its type
 * @formatted: string in which to print the arguments
 * @list: list of arguments to be printed
 * @index: index
 * @buffer: Buffer array to handle print.
 * @flags: Calculates active flags
 * @width: width
 * @precision: Precision
 * @size: Size specifier
 * Return: (1) or (2)
 */
int handle_print(const char *formatted, int *index, va_list list, char buffer[],
	int flags, int width, int precision, int size)
{
	int i, len = 0, chars_printed = -1;
	formatted_t formatted_types[] = {
		{'c', print_char}, {'s', print_string}, {'%', print_percent},
		{'i', print_int}, {'d', print_int}, {'b', print_binary},
		{'u', print_unsigned}, {'o', print_octal}, {'x', print_hexadecimal},
		{'X', print_hexa_upper}, {'p', print_pointer}, {'S', print_non_printable},
		{'r', print_reverse}, {'R', print_rot13string}, {'\0', NULL}
	};
	for (i = 0; formatted_types[i].formatted != '\0'; i++)
		if (formatted[*index] == formatted_types[i].formatted)
			return (formatted_types[i].fn(list, buffer, flags, width, precision, size));

	if (formatted_types[i].formatted == '\0')
	{
		if (formatted[*index] == '\0')
			return (-1);
		len += write(1, "%%", 1);
		if (formatted[*index - 1] == ' ')
			len += write(1, " ", 1);
		else if (width)
		{
			--(*index);
			while (formatted[*index] != ' ' && formatted[*index] != '%')
				--(*index);
			if (formatted[*index] == ' ')
				--(*index);
			return (1);
		}
		len += write(1, &formatted[*index], 1);
		return (len);
	}
	return (chars_printed);
}
