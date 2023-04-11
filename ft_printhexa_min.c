/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhexa_min.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edfirmin <edfirmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 17:14:00 by edfirmin          #+#    #+#             */
/*   Updated: 2023/04/11 17:24:49 by edfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_printhexa_min(int n)
{
	int		i;
	char	*base;

	i = 0;
	base = "0123456789abcdef";
	if (n > 16)
		ft_printhexa_min(n / 16);
	write(1, &base[(n % 16)], 1);
	return (i + 1);
}