/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnachit <mnachit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 18:43:58 by mnachit           #+#    #+#             */
/*   Updated: 2024/02/17 13:48:42 by mnachit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_flood_fill(int x, int y, char **map)
{
	if (x < 0 || x >= ft_len(map) || y < 0 || (size_t)y >= ft_strlen(map[0])
		|| map[x][y] == '1' || map[x][y] == 'E' || map[x][y] == 'V')
		return ;
	map[x][y] = 'V';
	ft_flood_fill(x - 1, y, map);
	ft_flood_fill(x + 1, y, map);
	ft_flood_fill(x, y - 1, map);
	ft_flood_fill(x, y + 1, map);
}

static int	path_to_exit(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'C')
				return (1);
			if (map[i][j] == 'E' && map[i - 1][j] != 'V'
			&& map[i + 1][j] != 'V'
			&& map[i][j - 1] != 'V' && map[i][j + 1] != 'V')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	check_path(char **map)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	ft_position_player(&x, &y, map);
	ft_flood_fill(x, y, map);
	if (path_to_exit(map))
		return (1);
	return (0);
}
