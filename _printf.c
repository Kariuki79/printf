#include <stdarg.h>
#include <unistd.h>
#include "main.h"

/**
 * _printf - printf function
 * @format: format
 * Return: printed chars
 */
int_printf(const char *format,...)
{
	va_list args;
	va_start(args, format);
