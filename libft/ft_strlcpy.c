/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnachit <mnachit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 11:46:39 by mnachit           #+#    #+#             */
/*   Updated: 2023/11/16 20:00:41 by mnachit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	length;
	size_t	i;

	length = 0;
	while (src[length])
		length++;
	i = 0;
	if (i < dstsize)
	{
		while (src[i] && i < dstsize - 1)
		{
			dst[i] = (char )src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (length);
}
