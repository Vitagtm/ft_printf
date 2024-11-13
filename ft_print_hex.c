#include <stdarg.h>
#include <stdio.h>
#include "ft_printf.h"

int ft_print_hex(unsigned int  num, char *base)
{
    int i;
    i = 0;
    if(num >= 16)
        i += ft_print_hex(num/16, base);
    i += write(1, &base[num % 16], 1);
    return (i);
}
