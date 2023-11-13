/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrizakov <mrizakov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 21:14:30 by mrizakov          #+#    #+#             */
/*   Updated: 2023/01/21 21:14:34 by mrizakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include<fcntl.h>
# include<stdio.h>
# include<stdlib.h>
# include<unistd.h>

int	ft_putchar(char c);
int	ft_putstr(char *s);
int	ft_putnbr(int n);
int	ft_putnbr_unsigned(unsigned int n);
int	ft_puthex(unsigned int n, char low_uppercase);
int	ft_putchar_hex(char c, char low_uppercase);
int	ft_putpointer(void *n);
int	ft_printf(const char *str, ...);
int	ft_puthex_ulonglong(unsigned long long n, char low_uppercase);

#endif