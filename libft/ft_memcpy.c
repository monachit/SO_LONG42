/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnachit <mnachit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 18:34:25 by mnachit           #+#    #+#             */
/*   Updated: 2023/11/19 17:55:37 by mnachit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*adst;
	unsigned char	*asrc;
	size_t			i;

	i = 0;
	adst = (unsigned char *)dst;
	asrc = (unsigned char *)src;
	if (dst == src)
		return (dst);
	while (n > i)
	{
		adst[i] = asrc[i];
		i++;
	}
	return (dst);
}
