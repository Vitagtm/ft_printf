#include "ft_printf.h"

int ft_print_pointer(unsigned long long ptr, char *base, int f)
{
    int i;
    i = 0;
    if(!ptr)
    {
        i += ft_print_str("(nil)");
        return (i);
    }
    if(f == 1)
    {
        i += write(1, "0x", 2);
        f = 0;
    }
    
    while(ptr >= 16)
        i += ft_print_pointer(ptr / 16, base, f);
    i += write(1, &base[ptr % 16], 1);
    return i;
}
