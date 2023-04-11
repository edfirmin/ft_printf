/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edfirmin <edfirmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 14:01:51 by edfirmin          #+#    #+#             */
/*   Updated: 2023/04/11 17:24:58 by edfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		ft_printchar(str[i]);
		i++;
	}
	return (i);
}

int	ft_type(va_list args, const char c)
{
	int	size;

	size = 0;
	if (c == 'c')
		size += ft_printchar(va_arg(args, int));
	if (c == 's')
		size += ft_putstr(va_arg(args, char *));
	if (c == 'd')
		size += ft_printnbr(va_arg(args, int));
	if (c == 'i')
		size += ft_printnbr(va_arg(args, int));
	if (c == 'u')
		size += ft_printnbrus(va_arg(args, unsigned int));
	if (c == 'x')
		size += ft_printhexa_min(va_arg(args, int));
	if (c == '%')
		size += ft_printchar('%');
	return (size);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		size;

	i = 0;
	size = 0;
	va_start(args, str);
	if (!str[i])
		return (size);
	while (str[i])
	{
		if (str[i] != '%')
			size += ft_printchar(str[i]);
		if (str[i] == '%')
		{
			size += ft_type(args, str[i + 1]);
			i++;
		}
		i++;
	}
	va_end(args);
	return (size);
}

int	main(void)
{
	unsigned int	i;

	i = 16;
	printf("\n%d\n",ft_printf("%x Edilson Firmino", i));
}
