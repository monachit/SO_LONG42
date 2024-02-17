/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_longutils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnachit <mnachit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 16:37:15 by mnachit           #+#    #+#             */
/*   Updated: 2024/02/11 16:55:00 by mnachit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_len(char **map)
{
	int	i;

	i = 0;
	while (map[i] != NULL)
		i++;
	return (i);
}

int	ft_strlen_pro(char *str, char c)
{
	int	i;

	i = 0;
	if (c == '\n')
	{
		while (str[i] && str[i] != c)
			i++;
		return (i);
	}
	return (0);
}

void	ft_show_error(char *msg)
{
	ft_printf("Error\n %s", msg);
	exit(1);
}

int	ft_search(char **map, char c)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == c)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	ft_position_player(int *x, int *y, char **map)
{
	int	x1;
	int	y1;

	x1 = 0;
	while (map[x1])
	{
		y1 = 0;
		while (map[x1][y1])
		{
			if (map[x1][y1] == 'P')
			{
				*x = x1;
				*y = y1;
				return ;
			}
			y1++;
		}
		x1++;
	}
}
