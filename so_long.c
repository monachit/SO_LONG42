/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnachit <mnachit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 06:46:27 by mnachit           #+#    #+#             */
/*   Updated: 2024/02/13 00:17:44 by mnachit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	ft_checkname(char *map_name)
{
	int	i;

	i = 0;
	while (map_name[i])
	{
		if (map_name[i] == '.' && map_name[i + 1] == 'b'
			&& map_name[i + 2] == 'e'
			&& map_name[i + 3] == 'r'
			&& map_name[i + 4] == '\0')
			return (0);
		i++;
	}
	return (1);
}

void	free_map(char **map, int map_size)
{
	int	i;

	i = 0;
	while (i < map_size)
	{
		free(map[i]);
		i++;
	}
	free(map);
}

static void	ft_so_long(char *read_map)
{
	char	**map;
	char	**fakemap;

	if (ft_checkname(read_map) == 1)
		ft_show_error("error in name map");
	map = ft_read_map(read_map);
	check_error(map);
	fakemap = ft_addfakemap(map);
	if (check_path(fakemap))
	{
		free_map(fakemap, ft_len(fakemap));
		free_map(map, ft_len(map));
		ft_show_error("path not valid!");
	}
	free_map(fakemap, ft_len(fakemap));
	game_plan(map);
}

int	ft_exit(t_vars *game)
{
	mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	free_map(game->map1, ft_len(game->map1));
	exit(0);
	return (0);
}

int	main(int ac, char **av)
{
	if (ac == 2)
		ft_so_long(av[1]);
	else
		ft_show_error("i can't see the map");
}
