#include "ft_printf.h"

int ft_print_char (int c)
{
	int i;
	i = 0;
	i += write(1, &c, 1);
	return(i);
}
int ft_print_str (char *str)
{
	int i;
	i = 0;
	while(*str)
		i += ft_print_char((int)*str++);
	return (i);
}
int ft_print_digit(int n)
{
	int count;
	count = 0;
	if(n == 0)
		count += ft_print_char('0');
	else if(n < 0)
	{
		count += ft_print_char('-');
		if(n == -2147483648)
		{
			count += ft_print_char('2');
			n = 147483648;
		}
		else
			n = -n;
	}
	if(n > 0)
	{
		count += ft_print_unsigned((unsigned int)n);
}
	return (count);
}

int ft_print_unsigned(unsigned int n)
{
	int count;
	count = 0;
	if (n == 0)
		count += ft_print_char('0');
	else
	{
		if(n >= 10)
			count += ft_print_unsigned(n/10);
		count += ft_print_char(n % 10 + '0');
	}
	return (count);
}
