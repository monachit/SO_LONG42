/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnachit <mnachit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 10:40:53 by mnachit           #+#    #+#             */
/*   Updated: 2023/12/01 22:13:53 by mnachit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_params(char c, va_list list)
{
	int	i;

	i = 0;
	if (c == 'd' || c == 'i')
		i += ft_putnbr(va_arg(list, int));
	else if (c == 'c')
		i += ft_putchar(va_arg(list, int));
	else if (c == 's')
		i += ft_putstr(va_arg(list, char *));
	else if (c == 'u')
		i += ft_unsigned_nbr(va_arg(list, unsigned int));
	else if (c == 'x')
		i += ft_hex(va_arg(list, unsigned int));
	else if (c == 'X')
		i += ft_lhex(va_arg(list, unsigned int));
	else if (c == 'p')
		i += ft_adr(va_arg(list, void *));
	else if (c == '%')
		i += ft_putchar(c);
	return (i);
}

int	ft_printf(const char *s, ...)
{
	va_list	list;
	int		i;
	int		j;

	if (s == NULL)
		return (-1);
	va_start(list, s);
	j = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] == '%')
		{
			i++;
			if (s[i] == '\0')
				break ;
			j += ft_params(s[i], list);
		}
		else
			j += ft_putchar(s[i]);
		i++;
	}
	va_end(list);
	return (j);
}
