#include "ft_printf.h"

int check_format(char type, va_list ap)
{
	int count;
	count = 0;
	if(type == 'c')
		count = ft_print_char(va_arg(ap, int));
	else if(type == 's')
		count = ft_print_str(va_arg(ap, char*));
	else if(type == 'p')
		count = ft_print_pointer(va_arg(ap, unsigned long long), "0123456789abcdef", 1);
	else if(type == 'd' || type == 'i')
		count = ft_print_digit(va_arg(ap, int));
	else if(type == 'u')
		count = ft_print_unsigned(va_arg(ap, unsigned int));
	else if(type == 'x')
		count = ft_print_hex(va_arg(ap, unsigned int), "0123456789abcdef");
	else if(type == 'X')
		count = ft_print_hex(va_arg(ap, unsigned int), "0123456789ABCDEF");
	else if(type == '%')
		count = write(1, "%", 1);
	return(count);
}
int ft_printf (const char *string, ...)
{
	va_list ap; //arg pointer
	int i;
	int count;
	va_start(ap, string); //ahora señala a primer arg no str
	i = 0;
	count = 0;
	while(string[i])
	{	
		if(string[i] == '%')
		{
			i++;
			count += check_format(string[i], ap);
		}
		else
			count += write(1, &string[i], 1);
		i++;
	}
	va_end(ap);
	return(count);
}

int main()
{
	//int num_of_symb;
	ft_printf("My name is %s, and my age %d, in hexadecimal: %x, random character: %c", "Mia", 42, 42, 'c');
	return(0);
}
