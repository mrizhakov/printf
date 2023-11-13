/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrizakov <mrizakov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 19:25:34 by mrizakov          #+#    #+#             */
/*   Updated: 2023/01/21 21:28:49 by mrizakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<stdarg.h>
#include<limits.h>
#include"ft_printf.h"

int	ft_datatype_sel(va_list args, char data_type)
{
	int	i;

	i = 0;
	if (data_type == 'c')
		i += ft_putchar(va_arg(args, int));
	if (data_type == '%')
		i += ft_putchar('%');
	if (data_type == 's')
		i += ft_putstr(va_arg(args, char *));
	if (data_type == 'd' || data_type == 'i')
		i += ft_putnbr(va_arg(args, int));
	if (data_type == 'u')
		i += ft_putnbr_unsigned(va_arg(args, unsigned int));
	if (data_type == 'x' || data_type == 'X')
		i += ft_puthex(va_arg(args, unsigned int), data_type);
	if (data_type == 'p')
		i += ft_putpointer(va_arg(args, void *));
	return (i);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		j;
	va_list	args;

	i = 0;
	j = 0;
	if (!str)
		return (0);
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			j += ft_datatype_sel(args, str[i]);
		}
		else
			j += ft_putchar(str[i]);
		i++;
	}
	va_end(args);
	return (j);
}

/* int main(void)
{
	char c = 'X';
	char *str = "STRING";
	int number = 34567890;
	unsigned int u_number = 4294967295;
	
	int return_val;
	
	return_val = ft_printf("My char is : aaa%caa%s\n", c, str);
	printf("return values: %d\n", return_val);
	return_val = printf("My char is : aaa%caa%s\n", c, str);
	printf("return values: %d\n", return_val);
	
	return_val = ft_printf("My number is : aaa%dcaa or aaaa%i\n", number, number);
	printf("return values: %d\n", return_val);
	return_val = printf("My number is : aaa%dcaa or aaaa%i\n", number, number);
	printf("return values: %d\n", return_val);
	
	return_val = ft_printf("My %% is : aaa%%aa\n");
	printf("return values: %d\n", return_val);
	return_val = printf("My %% is : aaa%%aa\n");
	printf("return values: %d\n", return_val);

	return_val = ft_printf("My string is : aaa%saa\n", str);
	printf("return values: %d\n", return_val);
	return_val = printf("My string is : aaa%saa\n", str);
	printf("return values: %d\n", return_val);

	return_val = ft_printf("My unsigned int is : aaa%ucaa\n", u_number);
	printf("return values: %d\n", return_val);
	return_val = printf("My unsigned int is : aaa%ucaa\n", u_number);
	printf("return values: %d\n", return_val);


	return_val = ft_printf("My lowercase hex is : aaa%x - %x\n", number, number);
	printf("return values: %d\n", return_val);
	return_val = printf("My lowercase hex is : aaa%x - %x\n", number, number);
	printf("return values: %d\n", return_val);

	return_val = ft_printf("My uppercase hex is : aaa%X\n", number);
	printf("return values: %d\n", return_val);
	return_val = printf("My uppercase hex is : aaa%X\n", number);
	printf("return values: %d\n", return_val);

	return_val = ft_printf("My pointer is : |%p|aaa|%p|\n", 0, 0);
	printf("return values: %d\n", return_val);
	return_val = printf("My pointer is : |%p|aaa|%p|\n", 0, 0);
	printf("return values: %d\n", return_val);

	printf("Empty string will follow after this, my function: |");
	
	return_val = ft_printf("");
	printf("return values: %d\n", return_val);
	
	printf("Empty string will follow after this, official function: |");
	
	//return_val = printf("");
	printf("return values: %d\n", return_val);


	char *string = NULL;
	
	printf("The real printf returns: |\n");
	printf("return values: %s\n", string);
	ft_printf("the fake prints return values: %s\n", string);

	return (0);
} */