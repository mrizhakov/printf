/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_hex.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrizakov <mrizakov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 19:25:34 by mrizakov          #+#    #+#             */
/*   Updated: 2023/01/21 21:21:21 by mrizakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<stdarg.h>
#include<limits.h>
#include"ft_printf.h"

int	ft_putchar_hex(char c, char low_uppercase)
{
	if (c <= 9)
	{
		c += 48;
		write(1, &c, 1);
	}
	if (c >= 10 && c <= 15)
	{
		if (low_uppercase == 'x')
			c += 87;
		if (low_uppercase == 'X')
			c += 55;
		write(1, &c, 1);
	}
	return (1);
}

int	ft_puthex(unsigned int n, char low_uppercase)
{
	int	i;

	i = 0;
	if (n >= 16)
	{
		i += ft_puthex(n / 16, low_uppercase);
		i += ft_putchar_hex(n % 16, low_uppercase);
	}
	if (n < 16)
		i += ft_putchar_hex(n, low_uppercase);
	return (i);
}

int	ft_puthex_ulonglong(unsigned long long n, char low_uppercase)
{
	int	i;

	i = 0;
	if (n >= 16)
	{
		i += ft_puthex_ulonglong(n / 16, low_uppercase);
		i += ft_putchar_hex(n % 16, low_uppercase);
	}
	if (n < 16)
		i += ft_putchar_hex(n, low_uppercase);
	return (i);
}

int	ft_putpointer(void *n)
{
	unsigned long long	i;

	i = 0;
	if (n == NULL || n == 0)
		i += ft_putstr("(nil)");
	if (n != NULL)
	{
		i += ft_putstr("0x");
		i += ft_puthex_ulonglong((unsigned long long)n, 'x');
	}
	return (i);
}
