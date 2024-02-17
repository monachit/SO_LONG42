/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnachit <mnachit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 15:53:28 by mnachit           #+#    #+#             */
/*   Updated: 2024/02/17 10:49:34 by mnachit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static char	*ft_call_strjoin(char *s1, char *s2)
{
	char	*result;

	result = ft_strjoin(s1, s2);
	free(s1);
	free(s2);
	return (result);
}

static int	ft_check_len(char *check_len_map)
{
	static int	len;

	if (len == 0)
		len = ft_strlen_pro(check_len_map, '\n');
	if (len != ft_strlen_pro(check_len_map, '\n'))
		return (1);
	return (0);
}

static char	*ft_get(int fd)
{
	char	*map;

	map = get_next_line(fd);
	if (map == NULL)
		ft_show_error("get_next_line error");
	return (map);
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
	jmap = ft_get(fd);
	lmap = ft_strdup("");
	while (jmap)
	{
		if (ft_check_len(jmap))
		{
			free(jmap);
			free(lmap);
			ft_show_error("The map isn't in shape!");
		}
		lmap = ft_call_strjoin(lmap, jmap);
		jmap = get_next_line(fd);
	}
	return_map = ft_split(lmap, '\n');
	free(lmap);
	return (return_map);
}
