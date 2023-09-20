#ifndef _MAIN_H_
#define _MAIN_H_

#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
int print_char(va_list types, char buffer[],

int flags, int width, int precision, int size);

int print_string(va_list types, char buffer[],

int flags, int width, int precision, int size);

int print_percent(va_list types, char buffer[],
		
int flags, int width, int precision, int size);

int _printf(const char *format, ...);
int get_flags(const char *format, int *i);

int get_width(const char *format, int *i, va_list list);

int get_precision(const char *format, int *i, va_list list);

int get_size(const char *format, int *i);
#endif
