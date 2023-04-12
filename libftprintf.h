/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edilson <edilson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 14:02:23 by edfirmin          #+#    #+#             */
/*   Updated: 2023/04/12 21:24:20 by edilson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>

int	ft_printf(const char *str, ...);
int	ft_printnbr(int nbr);
int	ft_printchar(const char c);
int	ft_printnbrus(unsigned int nbr);
int	ft_printhexa_min(int n);
int	ft_printhexa_maj(int n);

#endif
