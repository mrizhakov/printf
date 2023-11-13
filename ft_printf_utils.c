/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrizakov <mrizakov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 19:25:34 by mrizakov          #+#    #+#             */
/*   Updated: 2023/01/21 21:21:42 by mrizakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<stdarg.h>
#include<limits.h>
#include"ft_printf.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *s)
{
	int	i;

	i = 0;
	if (!s)
		s = "(null)";
	while (*s)
	{
		ft_putchar(*s);
		i++;
		s++;
	}
	return (i);
}

int	ft_putnbr(int n)
{
	int	i;

	i = 0;
	if (n == INT_MIN)
	{
		ft_putstr("-2147483648");
		return (11);
	}	
	if (n < 0)
	{
		i += ft_putchar('-');
		n = -n;
	}
	if (n >= 10)
	{
		i += ft_putnbr(n / 10);
		i += ft_putchar(n % 10 + '0');
	}
	if (n < 10)
		i += ft_putchar(n + '0');
	return (i);
}

int	ft_putnbr_unsigned(unsigned int n)
{
	int	i;

	i = 0;
	if (n >= 10)
	{
		i += ft_putnbr_unsigned(n / 10);
		i += ft_putchar(n % 10 + '0');
	}
	if (n < 10)
		i += ft_putchar(n + '0');
	return (i);
}
