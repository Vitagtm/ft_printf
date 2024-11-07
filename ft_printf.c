#include <stdarg.h>
#include <stdio.h>
int print_char (int c)
{
	int i;
	i = 0;
	i += write(1, &c, 1);
	return(i)
}
int print_str (char * str)
{
	int i;
	i = 0;
	while(*str)
	{
		print_char((int)*str);
		*str++;
		i++;
}
	return(i);
}
int print_digit(int n)
{
	int count;
	count = 0;
	if(n == 0)
		count += print_char('0');
	else if(n < 0)
	{
		count += print_char('-');
		n = -n;
	}
	else if(n > 0)
	{
		i += print_unsigned(n);
}
	else
		return count;
}
int print_unsigned(unsigned int n)
{
	int count;
	count = 0;
	if (n == 0)
		count += print_char('0');
	else
	{
		if(n/10 != 0)
			print_unsigned(n);
		print_char((n % 0) + '0');
		while(n > 0)
		{
			n /= 10;
			count++;
		}
	}
	return (count);
}
int check_format(char type, va_list ap)
{
	int count;
	count = 0;
	if(type == 'c')
		count += print_char(va_arg(ap, int));
	else if(type == 's')
		count += print_str(va_arg(ap, char*));
	else if(type == 'p')
		count +) print_pointer(va_arg(ap, unsigned long long));
	else if(type == 'd' || type == 'i')
		count += print_digit(va_arg(ap, int));
	else if(type == 'u')
		count += print_unsigned(va_arg(ap, unsigned int));
	else if(type == 'x' || type == 'X')
		count += print_hex(va_arg(ap, unsigned int), letter);
	else if(type == '%')
		count += write(1, "%", 1);
	return(count);
}
}
int ft_printf (const char *string, ...)
{
	va_list ap; //arg pointer
	int i;
	va_start(ap, string); //ahora señala a primer arg no str
	i = 0;
	while(*string)
	{	
		if(*string == "%")
			i += check_format(*++string, ap);
		else
			write(1, string, 1);
		*string++;
	}
	va_end(ap);
	return(i);
}
int main()
{
	int num_of_symb;
	ft_printf("My name is %s, and my age %d, in hexadecimal: %x, random character: %c", "Mia", 42, 42, "c");
}
