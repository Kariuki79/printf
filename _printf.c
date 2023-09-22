#include "main.h"

/**
 * _printf - Printf function to handle different arguments
 * @format: format
 * Return: Printed chars
 */
int _printf(const char *format, ...)
{
    if (format == NULL)
        return (-1);

    va_list args;
    int printed_chars = 0;

    va_start(args, format);
    printed_chars = parse_and_print(format, args);
    va_end(args);

    return (printed_chars);
}

int parse_and_print(const char *format, va_list args)
{
    int printed_chars = 0;
    int buff_ind = 0;
    char buffer[BUFF_SIZE];

    for (int i = 0; format[i] != '\0'; i++)
    {
        if (format[i] != '%')
        {
            buffer[buff_ind++] = format[i];
            if (buff_ind == BUFF_SIZE)
                printed_chars += print_buffer(buffer, &buff_ind);
        }
        else
        {
            i++;
            if (format[i] == '\0')
                return (-1);

            int flags = get_flags(format, &i);
            int width = get_width(format, &i, args);
            int precision = get_precision(format, &i, args);
            int size = get_size(format, &i);

            int printed = handle_print(format[i], args, buffer, flags, width, precision, size);
            if (printed == -1)
                return (-1);
            printed_chars += printed;
        }
    }

    printed_chars += print_buffer(buffer, &buff_ind);

    return printed_chars;
}

int print_buffer(char buffer[], int *buff_ind)
{
    if (*buff_ind > 0)
    {
        write(1, buffer, *buff_ind);
        *buff_ind = 0;
        return *buff_ind;
    }
    return 0;
}
