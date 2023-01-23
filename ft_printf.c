#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#define UINT_MAX 4294967295

void	ft_putchar(int c)
{
	unsigned char	ch;

	ch = (unsigned char)c;
	write(1, &ch, 1);
}

int	ft_putstr(char *str)
{
	int	index;

	index = 0;
	while (*(str + index))
	{
		ft_putchar(*(str + index));
		index++;
	}
	return (index);
}

int	get_num_length(long long num)
{
	int	length;

	length = 0;
	if (num == 0)
		return (1);
	if (num < 0)
	{
		length++;
		num *= -1;
	}
	while (num > 0)
	{
		num /= 10;
		length++;
	}
	return (length);
}

void	ft_putnbr(long long n)
{
	if (n == 0)
	{
		ft_putchar('0');
		return ;
	}
	if (n < 0)
	{
		n *= -1;
		ft_putchar('-');
	}
	if (n >= 10)
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
	else
		ft_putchar(n + '0');
}

void	printf_reverse(char *str, int length)
{
	while (length >= 0)
	{
		ft_putchar(str[length--]);
	}
}

int	convert_hexadecimal(unsigned long int n, char x)
{
	char	*hexadecimal_alp;
	char	*result;
	int		length;

	if (x == 'X')
		hexadecimal_alp = "0123456789ABCDEF";
	else
		hexadecimal_alp = "0123456789abcdef";
	length = get_num_length((long long)n);
	result = (char *)malloc(sizeof(char) * (length + 1));
	length = 0;
	if (!result)
		return (0);
	while (n > 0)
	{
		result[length] = hexadecimal_alp[n % 16];
		n /= 16;
		length++;
	}
	result[length] = '\0';
	printf_reverse(result, length);
	free(result);
	return (length);
}

int	printf_address(unsigned long int addr)
{
	int	length;

	length = 2;
	ft_putstr("0x");
	length += convert_hexadecimal(addr, 'x');
	return (length);
}

int	check_sym(va_list arg, char sym)
{
	int				i_num;
	long long		num;
	unsigned int	u_num;

	if (sym == 's')
		return (ft_putstr(va_arg(arg, char *)));
	else if (sym == 'c')
	{
		ft_putchar(va_arg(arg, int));
		return (1);
	}
	else if (sym == 'i' || sym == 'd')
	{
		num = va_arg(arg, int);
		ft_putnbr(num);
		return (get_num_length(num));
	}
	else if (sym == 'u')
	{
		u_num = va_arg(arg, unsigned int);
		ft_putnbr(u_num);
		return (get_num_length(u_num));
	}
	else if (sym == 'x' || sym == 'X')
	{
		i_num = va_arg(arg, int);
		if (i_num == -2147483648)
			return (-1);
		return (convert_hexadecimal((unsigned long int)i_num, sym));
	}
	else if (sym == 'p')
	{
		return (printf_address(va_arg(arg, long long)));
	}
	return (-1);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		length;
	size_t	i;

	if (!str)
		return (0);
	va_start(args, str);
	i = 0;
	length = 0;
	while (str[i])
	{
		if (str[i] == '%' && (str[++i] == 'c' || str[i] == 's' || str[i] == 'p'
			|| str[i] == 'd' || str[i] == 'i' || str[i] == 'x' || str[i] == 'X' 
			|| str[i] == 'u'))
		{
			length += check_sym(args, *(str + i));
			va_arg(args, void *);
		}
		else
		{
			ft_putchar(str[i]);
			length++;
		}
		i++;
	}
	va_end(args);
	return (length);
}

// int main()
// {
// 	// int x = 5;
// 	// printf("\n|%d|\n", ft_printf("Hello result of -12345 is: %p\n", &x));
// 	// // printf("%x\n", -77);
// 	// printf("%p\n", &x);
// 	// // printf("%i\n", get_num_length(-0));
// 	// ft_printf("The first letter of the alphabet is %c\n", 'A');
// 	// ft_printf("The last letter of the alphabet is %c\n", 'Z'); 

// 	// int a = ft_printf("The answer is %d. The answer in octal is %p, and in hex %X\n", 42, &x, 42);
// 	// int b = printf("The answer is %d. The answer in octal is %p, and in hex %X\n", 42, &x, 42);                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                              
// 	// printf("%d - %d\n", a, b);
// 	// %c tests
// 	ft_printf("%c\n", '0');
// 	printf("%c\n", '0');
// 	ft_printf(" %c \n", '0');
// 	printf(" %c \n", '0');
// 	ft_printf(" %c\n", '0' - 256);
// 	printf(" %c\n", '0' - 256);
// 	ft_printf("%c \n", '0' + 256);
// 	printf("%c \n", '0' + 256);
// 	ft_printf(" %c %c %c \n", '0', 0, '1');
// 	printf(" %c %c %c \n", '0', 0, '1');
// 	ft_printf(" %c %c %c \n", ' ', ' ', ' ');
// 	printf(" %c %c %c \n", ' ', ' ', ' ');
// 	ft_printf(" %c %c %c \n", '1', '2', '3');
// 	printf(" %c %c %c \n", '1', '2', '3');
// 	ft_printf(" %c %c %c \n", '2', '1', 0);
// 	printf(" %c %c %c \n", '2', '1', 0);
// 	ft_printf(" %c %c %c \n", 0, '1', '2');
// 	printf(" %c %c %c \n", 0, '1', '2');
// 	return (0);
// }