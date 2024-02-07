/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnachit <mnachit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 15:53:28 by mnachit           #+#    #+#             */
/*   Updated: 2024/02/07 16:23:43 by mnachit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static char	*ft_call_strjoin(char *s1, char *s2)
{
	char	*result;

	if (!s1)
		s1 = ft_strdup("");
	result = ft_strjoin(s1, s2);
	free(s1);
	return (result);
}

static void	ft_check_len(char *check_len_map)
{
	static int	len;

	if (len == 0)
		len = ft_strlen_pro(check_len_map, '\n');
	if (len != ft_strlen_pro(check_len_map, '\n'))
		ft_show_error("The map isn't in shape!");
}

char	**ft_read_map(char *nmap)
{
	char		**return_map;
	char		*jmap;
	char		*lmap;
	int			fd;

	fd = open(nmap, O_RDONLY);
	if (fd == -1)
		return (NULL);
	jmap = get_next_line(fd);
	lmap = NULL;
	while (jmap)
	{
		ft_check_len(jmap);
		lmap = ft_call_strjoin(lmap, jmap);
		free(jmap);
		jmap = get_next_line(fd);
	}
	return_map = ft_split(lmap, '\n');
	free(lmap);
	return (return_map);
}
