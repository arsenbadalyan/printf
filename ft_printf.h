/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsbadal <arsbadal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 13:02:29 by arsbadal          #+#    #+#             */
/*   Updated: 2023/01/24 19:18:01 by arsbadal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

// Main Functions
int	ft_printf(const char *str, ...);
int	ft_putnbr(long long n);
int	convert_hexadecimal(unsigned long long n, char x);
int	printf_address(unsigned long long addr);
int	check_sym(va_list arg, char sym);

// Helper Functions
int	ft_putchar(int c);
int	ft_putstr(char *str);
int	get_num_length(unsigned long long num);
int	printf_reverse(char *str, int length);
#endif