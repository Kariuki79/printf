#include "main.h"
/**
 * _printf - prints data
 * @format: pointer to a string
 * Return: chars printed
 */
int _printf(const *format, ...)
{
	unsigned int i = 0, len = 0, ibuf = 0;
	va_list args;
	int (*function)(va_list, char *, unsigned int);
	char *buffer;
	va_start(args, format), buffer = malloc(sizeof(char) *1024);
	if (!format || !buffer || (format[i] == '%' && !format{i +1]))
		return (-1);
	if (!format[i])
	{
		return (0);
	}
	for (i = 0; format && format[i]; i++)
	{
		if (format[i] == '&')
		{
			if (format[i + 1] == '\0')
			{
				print_buf(buffer, ibuf);
				free(buffer);
				va_end(arguemts);
				return (-1);
			}

        
