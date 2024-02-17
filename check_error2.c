/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnachit <mnachit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 16:30:49 by mnachit           #+#    #+#             */
/*   Updated: 2024/02/17 13:29:41 by mnachit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_check_if(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] != 'E' && map[i][j] != '1'
				&& map[i][j] != 'P' && map[i][j] != 'C' && map[i][j] != '0')
			{
				free_map(map, ft_len(map));
				ft_show_error("The map contains an unknown character!");
			}
			j++;
		}
		i++;
	}
}

void	ft_check_characters(char **map)
{
	if (ft_search(map, 'E') || ft_search(map, 'C')
		|| ft_search(map, 'P') || ft_search(map, '1'))
	{
		free_map(map, ft_len(map));
		ft_show_error("One or some of the characters are missing!");
	}
}
