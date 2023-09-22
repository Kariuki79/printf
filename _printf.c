#include "main.h"
void print_buffer(char buffer[], int *buff_ind);
/**
 * _printf - Printf function todifferent arguments
 * @format: format
 * Return: Printed chars
 */

int _printf(const char *format, ...)
{
    va_list list;
    va_start(list, format);

    int printed_chars = 0;
    int i;
    char buffer[BUFF_SIZE];
    int buff_ind = 0;
    
    if (format == NULL)
        return (-1);

    for (i = 0; format[i]; i++)
    {
        if (format[i] != '%')
        {
            buffer[buff_ind++] = format[i];
            if (buff_ind == BUFF_SIZE || !format[i + 1])
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
            if (format[i + 1] == '\0')
            {
                va_end(list);
                return (-1);
            }

            int specifier_length = handle_print(format[i + 1], list, buffer, &buff_ind);
            if (specifier_length == -1)
            {
                va_end(list);
                return (-1);
            }

            i++; // Skip the format specifier
            printed_chars += specifier_length;
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
