/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_helpers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsbadal <arsbadal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 13:00:30 by arsbadal          #+#    #+#             */
/*   Updated: 2023/01/24 18:57:44 by arsbadal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(int c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *str)
{
	int	index;

	index = 0;
	if (!str)
	{
		return (ft_putstr("(null)"));
	}
	while (*(str + index))
	{
		ft_putchar(*(str + index));
		index++;
	}
	return (index);
}

int	get_num_length(unsigned long long num)
{
	int	length;

	length = 0;
	if (num == 0)
		return (1);
	while (num > 0)
	{
		num /= 10;
		length++;
	}
	return (length);
}

int	printf_reverse(char *str, int length)
{
	int	new_length;

	new_length = 0;
	length--;
	while (length >= 0)
	{
		new_length += ft_putchar(str[length]);
		length--;
	}
	return (new_length);
}
