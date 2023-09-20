#include "main.h"
/**
 * _printf - checks for characters in format
 * @format: holds the characters to be printed
 * Return: print characters
 */

void print_buffer(char buffer[], int *buf_index);
int _printf(const char *format, ...)
{
	int a;
	int printed = 0;
	int chars_printed = 0;
	int flags;
	int width;
	int precision;
	int size;
	int buffer_i = 0;
	va_list args;
	char buffer[BUFF_SIZE];

	if (format == NULL)
		return (-1);
