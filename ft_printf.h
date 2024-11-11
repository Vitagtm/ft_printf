#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

#ifndef FT_PRINTF_H
#define FT_PRINTF_H

int ft_print_char (int c);
int ft_print_str (char *str);
int ft_print_digit(int n);
int ft_print_unsigned(unsigned int n);
int ft_print_hex(unsigned int  num, char *base);
int check_format(char type, va_list ap);
int ft_printf (const char *string, ...);
int ft_print_pointer(unsigned long long ptr, char *base, int f);

#endif
