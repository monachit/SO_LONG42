/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnachit <mnachit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 10:55:45 by mnachit           #+#    #+#             */
/*   Updated: 2023/11/30 18:45:44 by mnachit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stddef.h>

int	ft_lhex(unsigned int d);
int	ft_printf(const char *s, ...);
int	ft_putnbr(int nb);
int	ft_putchar(char c);
int	ft_putstr(char *s);
int	ft_unsigned_nbr(size_t n);
int	ft_hex(unsigned long nb);
int	ft_adr(void *d);

#endif
