/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhexa_maj.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edilson <edilson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 21:23:39 by edilson           #+#    #+#             */
/*   Updated: 2023/04/12 21:26:13 by edilson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_printhexa_maj(int n)
{
	int		i;
	char	*base;

	i = 0;
	base = "0123456789ABCDEF";
	if (n >= 16)
	{
		i = ft_printhexa_maj(n / 16);
		ft_printchar(base[n % 16]);
	}
	else
		ft_printchar(base[(n % 16)]);
	return (i + 1);
}