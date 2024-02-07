/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnachit <mnachit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 06:46:27 by mnachit           #+#    #+#             */
/*   Updated: 2024/02/07 17:31:58 by mnachit          ###   ########.fr       */
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

static void	ft_so_long(char *read_map)
{
	char	**map;
	char	**fakemap;

	if (ft_checkname(read_map) == 1)
		ft_show_error("error in name map");
	map = ft_read_map(read_map);
	check_error(map);
	fakemap = ft_addfakemap(map);
	check_path(fakemap);
	game_plan(map);
	
}

int	main(int ac, char **av)
{
	if (ac == 2)
		ft_so_long(av[1]);
	else
		ft_show_error("i can't see the map");
}
