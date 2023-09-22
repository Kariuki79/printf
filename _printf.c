#include "main.h"
void print_buffer(char buffer[], int *buffer_index);
/**
 * _printf - Printf function todifferent arguments
 * @format: format
 * Return: Printed chars
 */
int _printf(const char *format, ...)
{
    int printed_chars = 0;
    int buffer_index = 0, int i;
    va_list list;
    char buffer[BUFF_SIZE];

    if (format == NULL)
        return (-1);

    va_start(list, format);

    for (i = 0; format[i] != '\0'; i++)
    {
        if (format[i] != '%')
        {
            buffer[buffer_index++] = format[i];
            if (buffer_index == BUFF_SIZE || format[i + 1] == '\0')
            {
                printed_chars += print_buffer(buffer, &buffer_index);
            }
            else
            {
                printed_chars++;
            }
        }
        else
        {
            print_buffer(buffer, &buffer_index);
            i++;
            if (format[i] == '\0')
                return (-1);

            int flags = get_flags(format, &i);
            int width = get_width(format, &i, list);
            int precision = get_precision(format, &i, list);
            int size = get_size(format, &i);

            int printed = handle_print(format[i], list, buffer, flags, width, precision, size);
            if (printed == -1)
            {
                va_end(list);
                return (-1);
            }

            printed_chars += printed;
        }
    }

    va_end(list);

    return printed_chars;
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
