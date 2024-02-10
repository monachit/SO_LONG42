/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnachit <mnachit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 12:01:21 by mnachit           #+#    #+#             */
/*   Updated: 2023/11/16 20:07:17 by mnachit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	l;
	size_t	p;

	p = ft_strlen(dst);
	l = ft_strlen(src);
	i = 0;
	if (dstsize <= p)
		return (dstsize + l);
	j = p;
	while (j < dstsize - 1 && src[i] != '\0')
	{
		dst[j] = (char )src[i];
		j++;
		i++;
	}
	dst[j] = '\0';
	return (l + p);
}
