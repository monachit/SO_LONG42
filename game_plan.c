/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_plan.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnachit <mnachit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 13:42:43 by mnachit           #+#    #+#             */
/*   Updated: 2024/02/17 14:02:42 by mnachit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	push_window(t_vars *game, int x, int y, int a)
{
	void	*img_ptr;

	img_ptr = mlx_xpm_file_to_image(game->mlx, "textures/space.xpm", \
			&game->heigth, &game->width);
	if (!img_ptr)
		ft_show_error("mlx_xpm_file_to_image function fails!");
	mlx_put_image_to_window(game->mlx, game->win \
				, img_ptr, game->player_y * T, game->player_x * T);
	mlx_destroy_image(game->mlx, img_ptr);
	img_ptr = mlx_xpm_file_to_image(game->mlx, ft_image_final(a), \
			&game->heigth, &game->width);
	if (!img_ptr)
		ft_show_error("mlx_xpm_file_to_image function fails!");
	mlx_put_image_to_window(game->mlx, game->win \
				, img_ptr, y * T, x * T);
	mlx_destroy_image(game->mlx, img_ptr);
	game->player_x = x;
	game->player_y = y;
}

static void	move_player(t_vars *game, int new_x, int new_y, int a)
{
	static int	i;

	if (game->map1[new_x][new_y] == '0' || game->map1[new_x][new_y] == 'P'
		|| game->map1[new_x][new_y] == 'C')
	{
		push_window(game, new_x, new_y, a);
		i++;
		ft_printf("move : %d\n", i);
		if (game->map1[new_x][new_y] == 'C')
			game->map1[new_x][new_y] = '0';
	}
	else if (game->map1[new_x][new_y] == 'E' && ft_ft(game->map1) == 0)
	{
		push_window(game, new_x, new_y, 'E');
		ft_printf("congratulations you win in %d move\n", i);
		mlx_destroy_window(game->mlx, game->win);
		mlx_destroy_display(game->mlx);
		free_map(game->map1, ft_len(game->map1));
		free(game->mlx);
		exit(0);
	}
}

int	key_hook(int keycode, t_vars *game)
{
	if (keycode == 119)
		move_player(game, game->player_x - 1, game->player_y, 119);
	else if (keycode == 115)
		move_player(game, game->player_x + 1, game->player_y, 115);
	else if (keycode == 97)
		move_player(game, game->player_x, game->player_y - 1, 97);
	else if (keycode == 100)
		move_player(game, game->player_x, game->player_y + 1, 100);
	else if (keycode == 65307)
	{
		mlx_destroy_window(game->mlx, game->win);
		mlx_destroy_display(game->mlx);
		free_map(game->map1, ft_len(game->map1));
		free(game->mlx);
		exit(0);
	}
	return (0);
}

static void	ft_map(char **map, t_vars *vars)
{
	char	*s;
	void	*img_ptr;
	int		i;
	int		j;

	i = 0;
	while (i < ft_len(map))
	{
		j = 0;
		while ((size_t)j < ft_strlen(map[0]))
		{
			s = ft_image(i, j, map);
			img_ptr = mlx_xpm_file_to_image(vars->mlx, s, \
					&vars->width, &vars->heigth);
			if (!img_ptr)
				ft_show_error("mlx_xpm_file_to_image function fails!");
			mlx_put_image_to_window(vars->mlx, vars->win, img_ptr, \
					j * T, i * T);
			mlx_destroy_image(vars->mlx, img_ptr);
			j++;
		}
		i++;
	}
}

void	game_plan(char **map)
{
	t_vars	vars;

	vars.mlx = mlx_init();
	if (!vars.mlx)
		ft_show_error("mlx_init function fails!");
	vars.win = mlx_new_window(vars.mlx, ft_strlen(map[0]) * T, \
			ft_len(map) * T, "Map Display");
	if (!vars.win)
		ft_show_error("mlx_new_window function fails");
	ft_position_player(&vars.player_x, &vars.player_y, map);
	ft_map(map, &vars);
	vars.map1 = map;
	mlx_key_hook(vars.win, key_hook, &vars);
	mlx_hook(vars.win, 17, 0, ft_exit, &vars);
	mlx_loop(vars.mlx);
}
