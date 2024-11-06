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
	int i;
	char num;
	i = 0;
	if(n < 0)
	{
		write(1, "-", 1);
		n = -n;
		i++;
	}
	else if(n <= 9)
	{
		i += print_char(n + '0');
}
	else
		return count + print_digit(n % 10);
}
int check_format(char type, va_list ap)
{
	int count;
	count = 0;
	if(type == 'c')
		count += print_char(va_arg(ap, int));
	if(type == 's')
		count += print_str(va_arg(ap, char*));
	if(type == 'd')
		count += print_digit(va_arg(ap, int));
	if(type == 'x')
		count += print_hex(va_arg(ap, unsigned int), "minus");
	if(type == 'X')
	{
		count += print_hex(va_arg(ap, unsigned int), "mayus")
	if(type == '%')
	{
		count += write(1, "%", 1);
		count++;
	}
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
