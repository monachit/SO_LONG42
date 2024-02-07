/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnachit <mnachit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 16:37:18 by mnachit           #+#    #+#             */
/*   Updated: 2024/02/07 12:01:23 by mnachit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_checkwall0(char **map)
{
	int	i;
	int	len;

	i = 0;
	while (map[0][i])
	{
		if (map[0][i] != '1')
			ft_show_error("The map is not closed!");
		i++;
	}
	i = 0;
	len = ft_len(map) - 1;
	while (map[len][i])
	{
		if (map[len][i] != '1')
			ft_show_error("The map is not closed!");
		i++;
	}
}

static void	ft_checkwall1(char **map)
{
	int	i;

	i = 1;
	while (i < ft_len(map) - 1)
	{
		if (map[i][0] != '1')
			ft_show_error("The map is not closed!");
		i++;
	}
	i = 1;
	while (i < ft_len(map) - 1)
	{
		if (map[i][ft_strlen(map[0]) - 1] != '1')
			ft_show_error("The map is not closed!");
		i++;
	}
}

static void	ft_check_characters(char **map)
{
	if (ft_search(map, 'E') || ft_search(map, 'C')
		|| ft_search(map, 'P') || ft_search(map, '1'))
		ft_show_error("One or some of the characters are missing!");
}

static void	ft_check_duplication(char **map)
{
	int	i;
	int	j;
	int	player;
	int	exit;

	player = 0;
	exit = 0;
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'P')
				player++;
			else if (map[i][j] == 'E')
				exit++;
			if (player > 1 || exit > 1)
				ft_show_error("There's a duplication of characters!");
			j++;
		}
		i++;
	}
}

void	check_error(char **map)
{
	if (!map)
		ft_show_error("have error in map");
	ft_checkwall0(map);
	ft_checkwall1(map);
	ft_check_characters(map);
	ft_check_duplication(map);
}
