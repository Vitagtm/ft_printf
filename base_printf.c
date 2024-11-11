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
		n = -n;
	}
	else if(n > 0)
	{
		count += ft_print_unsigned(n);
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
		if(n/10 != 0)
			ft_print_unsigned(n);
		ft_print_char(n % 10 + '0');
		while(n > 0)
		{
			n /= 10;
			count++;
		}
	}
	return (count);
}
