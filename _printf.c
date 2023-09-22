#include "main.h"
void print_buffer(char buffer[], int *buff_ind);
/**
 * _printf - Printf function todifferent arguments
 * @format: format
 * Return: Printed chars
 */

int _printf(const char *format, ...)
{
    if (format == NULL)
        return (-1);

    va_list list;
    va_start(list, format);

    int printed_chars = 0;
    int buff_ind = 0;
    char buffer[BUFF_SIZE];
	int i;

    for (int i = 0; format[i] != '\0'; i++)
    {
        if (format[i] != '%')
        {
            buffer[buff_ind++] = format[i];
            if (buff_ind == BUFF_SIZE || format[i + 1] == '\0')
            {
                printed_chars += write(1, buffer, buff_ind);
                buff_ind = 0;
            }
            else
            {
                printed_chars++;
            }
        }
        else
        {
            print_buffer(buffer, &buff_ind);
            i++;
            if (format[i] == '\0')
            {
                va_end(list);
                return (-1);
            }

            if (format[i] == '%') // Handle '%%' as a literal '%'
            {
                buffer[buff_ind++] = '%';
                if (buff_ind == BUFF_SIZE || format[i + 1] == '\0')
                {
                    printed_chars += write(1, buffer, buff_ind);
                    buff_ind = 0;
                }
                else
                {
                    printed_chars++;
                }
            }
            else
            {
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
    }

    va_end(list);
    return (printed_chars);
}
/**
 * print_buffer - Prints the contents of the buffer if it exist
 * @buffer: Array of chars
 * @buff_ind: Index at which to add next char, represents the length.
 */
void print_buffer(char buffer[], int *buff_ind)
{
	if (*buff_ind > 0)
		write(1, &buffer[0], *buff_ind);

	*buff_ind = 0;
}
