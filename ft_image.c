/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_image.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnachit <mnachit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 14:33:26 by mnachit           #+#    #+#             */
/*   Updated: 2024/02/07 16:44:17 by mnachit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_image_final(int i, int j, char **map, int a)
{
	char	*s;
	int		l;

	l = ft_ft(map);
	if (map[i][j] == '1')
		s = "textures/wall.xpm";
	else if (map[i][j] == '0')
		s = "textures/space.xpm";
	else if (l == 0 && map[i][j] == 'E')
		s = "textures/opendoor.xpm";
	else if (map[i][j] == 'P' && a == 97)
		s = "textures/p_left.xpm";
	else if (map[i][j] == 'P' && a == 100)
		s = "textures/p_right.xpm";
	else if (map[i][j] == 'E')
		s = "textures/exit.xpm";
	else if (map[i][j] == 'C')
		s = "textures/collec.xpm";
	else if (map[i][j] == 'P')
		s = "textures/p_right.xpm";
	return (s);
}

char	*ft_image(int i, int j, char **map)
{
	char	*s;

	if (map[i][j] == '1')
		s = "textures/wall.xpm";
	else if (map[i][j] == '0')
		s = "textures/space.xpm";
	else if (map[i][j] == 'P')
		s = "textures/p_left.xpm";
	else if (map[i][j] == 'E')
		s = "textures/exit.xpm";
	else
		s = "textures/collec.xpm";
	return (s);
}

int	ft_ft(char **map)
{
	int	total_c;
	int	i;
	int	j;

	i = 0;
	total_c = 0;
	while (i < ft_len(map))
	{
		j = 0;
		while ((size_t)j < ft_strlen(map[0]))
		{
			if (map[i][j] == 'C')
				total_c++;
			j++;
		}
		i++;
	}
	return (total_c);
}

char	**ft_addfakemap(char **map)
{
	char	**fake_map;
	int		i;

	i = 0;
	fake_map = malloc((ft_len(map) + 1) * sizeof(char *));
	if (!fake_map)
		ft_show_error("Allocation of the fake map failed!");
	while (map[i])
	{
		fake_map[i] = ft_strdup(map[i]);
		if (!fake_map[i])
			ft_show_error("Allocation of the fake map failed!");
		i++;
	}
	fake_map[i] = NULL;
	return (fake_map);
}
