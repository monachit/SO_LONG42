/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnachit <mnachit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 11:29:57 by mnachit           #+#    #+#             */
/*   Updated: 2023/11/19 18:13:03 by mnachit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	ft_nachit(char c, char const *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	int		start;
	int		finish;
	int		i;

	i = 0;
	start = 0;
	finish = ft_strlen(s1);
	if (!s1)
		return (0);
	if (!set)
		return (ft_strdup(s1));
	while (s1[start] && ft_nachit(s1[start], set))
		start++;
	while (start < finish && ft_nachit(s1[finish - 1], set))
		finish--;
	str = malloc(finish - start + 1);
	if (!str)
		return (NULL);
	while (start < finish)
		str[i++] = s1[start++];
	str[i] = '\0';
	return (str);
}
