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

    int printed_chars = 0, i;
    char buffer[BUFF_SIZE];
    int buff_ind = 0;

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
                return (-1);

            buff_ind += handle_print(format[i + 1], list, buffer + buff_ind);
            if (buff_ind == -1)
            {
                va_end(list);
                return (-1);
            }

            i++; // Skip the format specifier
            printed_chars += buff_ind;
            buff_ind = 0;
        }
    }

    va_end(list);
    return printed_chars;
}
