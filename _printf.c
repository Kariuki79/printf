#include "main.h"

/**
 * _printf - Printf function to handle different arguments
 * @format: format
 * Return: Printed chars
 */
void print_buffer(char buffer[], int *buff_ind);

int _printf(const char *format, ...)
{
    if (format == NULL)
        return (-1);

    va_list args;
    va_start(args, format);

    int printed_chars = 0;
    int buff_ind = 0;
    char buffer[BUFF_SIZE];

    for (int i = 0; format[i] != '\0'; i++)
    {
        if (format[i] != '%')
        {
            buffer[buff_ind++] = format[i];
            if (buff_ind == BUFF_SIZE || format[i + 1] == '\0')
            {
                write(1, buffer, buff_ind);
                printed_chars += buff_ind;
                buff_ind = 0;
            }
            else
            {
                printed_chars++;
            }
        }
        else
        {
            i++;
            if (format[i] == '\0')
            {
                va_end(args);
                return (-1);
            }

            int flags = get_flags(format, &i);
            int width = get_width(format, &i, args);
            int precision = get_precision(format, &i, args);
            int size = get_size(format, &i);
            int printed = handle_print(format[i], args, buffer, flags, width, precision, size);

            if (printed == -1)
            {
                va_end(args);
                return (-1);
            }

            printed_chars += printed;
        }
    }

    va_end(args);

    return (printed_chars);
}

void print_buffer(char buffer[], int *buff_ind)
{
    if (*buff_ind > 0)
    {
        write(1, buffer, *buff_ind);
        *buff_ind = 0;
    }
}
