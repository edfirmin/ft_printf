/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edilson <edilson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 14:01:51 by edfirmin          #+#    #+#             */
/*   Updated: 2023/04/12 21:41:14 by edilson          ###   ########.fr       */
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
	if (c == 'p')
	{
		size += ft_putstr("0x");
		size += ft_printhexa_min(va_arg(args, int));
	}
	if (c == 'd')
		size += ft_printnbr(va_arg(args, int));
	if (c == 'i')
		size += ft_printnbr(va_arg(args, int));
	if (c == 'u')
		size += ft_printnbrus(va_arg(args, unsigned int));
	if (c == 'x')
		size += ft_printhexa_min(va_arg(args, int));
	if (c == 'X')
		size += ft_printhexa_maj(va_arg(args, int));
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
	int	i;
	int	s;

	i = 20155555;
	s = 667;
	printf("%%%");
}
