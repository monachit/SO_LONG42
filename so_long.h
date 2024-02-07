/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnachit <mnachit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 14:17:00 by mnachit           #+#    #+#             */
/*   Updated: 2024/02/07 16:27:08 by mnachit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H

# define SO_LONG_H
# include <mlx.h>
# include "libft/libft.h"
# include "ft_printf/ft_printf.h"
# include "get_next_line/get_next_line.h"

# define T 64

typedef struct s_vars
{
	char	**map1;
	int		player_x;
	int		player_y;
	int		heigth;
	int		width;
	void	*mlx;
	void	*win;
}	t_vars;

void	check_error(char **map);
char	**ft_read_map(char *nmap);
int		ft_strlen_pro(char *str, char c);
void	ft_show_error(const char *msg);
int		ft_search(char **map, char c);
char	**ft_addfakemap(char **map);
int		ft_len(char **map);
void	check_path(char **map);
void	game_plan(char **map);
void	ft_position_player(int *x, int *y, char **map);
char	*ft_image_final(int i, int j, char **map, int a);
char	*ft_image(int i, int j, char **map);
int		ft_ft(char **map);
#endif
