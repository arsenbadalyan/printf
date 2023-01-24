/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsbadal <arsbadal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 12:39:33 by arsbadal          #+#    #+#             */
/*   Updated: 2023/01/24 21:58:09 by arsbadal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(long long n)
{
	int	i;

	i = 1;
	if (n == 0)
	{
		ft_putchar('0');
		return (1);
	}
	if (n < 0)
	{
		n *= -1;
		i += ft_putchar('-');
	}
	if (n >= 10)
		i += ft_putnbr(n / 10);
	ft_putchar((n % 10) + '0');
	return (i);
}

int	convert_hexadecimal(unsigned long long n, char x)
{
	char	*hexadecimal_alp;
	char	*result;
	int		length;

	if (x == 'X')
		hexadecimal_alp = "0123456789ABCDEF";
	else
		hexadecimal_alp = "0123456789abcdef";
	length = get_num_length((unsigned long long)n);
	result = (char *)malloc(sizeof(char) * (length + 1));
	length = 0;
	if (!result)
		return (0);
	while (n > 0 || (length == 0 && n == 0))
	{
		result[length] = hexadecimal_alp[n % 16];
		n /= 16;
		length++;
	}
	result[length] = '\0';
	length = printf_reverse(result, length);
	free(result);
	return (length);
}

int	printf_address(unsigned long long addr)
{
	int	length;

	length = 2;
	ft_putstr("0x");
	length += convert_hexadecimal(addr, 'x');
	return (length);
}

int	check_sym(va_list arg, char sym)
{
	if (sym == 's')
		return (ft_putstr(va_arg(arg, char *)));
	else if (sym == 'c')
		return (ft_putchar(va_arg(arg, int)));
	else if (sym == 'i' || sym == 'd')
		return (ft_putnbr(va_arg(arg, int)));
	else if (sym == 'u')
		return (ft_putnbr(va_arg(arg, unsigned int)));
	else if (sym == 'x' || sym == 'X')
		return (convert_hexadecimal((unsigned long long)
				va_arg(arg, unsigned int), sym));
	else if (sym == 'p')
		return (printf_address((unsigned long long)
				va_arg(arg, unsigned long long)));
	else if (sym == '%')
		return (ft_putchar('%'));
	return (0);
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
		if (str[i] == '%')
		{
			length += check_sym(args, *(str + ++i));
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
