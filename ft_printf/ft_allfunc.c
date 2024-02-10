/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_allfunc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnachit <mnachit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 05:51:35 by mnachit           #+#    #+#             */
/*   Updated: 2023/12/01 22:11:21 by mnachit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char s)
{
	write(1, &s, 1);
	return (1);
}

int	ft_putstr(char *s)
{
	int	i;

	i = 0;
	if (!s)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
	return (i);
}

int	ft_hex(unsigned long d)
{
	int		i;
	char	*hex;

	i = 0;
	hex = "0123456789abcdef";
	if (d < 16)
		i += write(1, hex + d, 1);
	else if (d >= 16)
	{
		i += ft_hex(d / 16);
		i += ft_hex(d % 16);
	}
	return (i);
}

int	ft_lhex(unsigned int d)
{
	int		i;
	char	*hex;

	i = 0;
	hex = "0123456789ABCDEF";
	if (d < 16)
		i += write(1, hex + d, 1);
	else if (d >= 16)
	{
		i += ft_lhex(d / 16);
		i += ft_lhex(d % 16);
	}
	return (i);
}

int	ft_unsigned_nbr(size_t n)
{
	int	len;

	len = 0;
	if (n >= 10)
	{
		len += ft_putnbr(n / 10);
		len += ft_putnbr(n % 10);
	}
	else
		len += ft_putchar(n + '0');
	return (len);
}
