/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmota-si <bmota-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 11:15:09 by bmota-si          #+#    #+#             */
/*   Updated: 2023/05/26 12:28:01 by bmota-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/libft.h"
# include "../minilibx-linux/mlx.h"
# include "../minilibx-linux/mlx_int.h"
# include <stdio.h>
# include <stdlib.h>
# include <X11/X.h>
# include <fcntl.h>
# include <unistd.h>
# include <signal.h>

# define WALL "../images/wall2.xpm"
# define FLOOR "../images/floor2.xpm"
# define COLLECT "../images/collect2.xpm"
# define PLAYERA "../images/playera2.xpm"
# define PLAYERS "../images/players2.xpm"
# define PLAYERW "../images/playerw2.xpm"
# define PLAYERD "../images/playerd2.xpm"
# define PLAYERF "../images/playerf2.xpm"
# define EXIT "../images/portal.xpm"
# define SIZE 45

typedef struct s_game
{
	void	*wall_img;
	void	*floor_img;
	void	*collect_img;
	void	*playera_img;
	void	*playerw_img;
	void	*players_img;
	void	*playerd_img;
	void	*playerf_img;
	void	*exit_img;
	void	*mlx;
	int		lines;
	char	**map;
	char	**map_dup;
	void	*window;
	int		fd;
	int		x;
	int		y;
	int		p_x;
	int		p_y;
	int		f_x;
	int		f_y;
	int		moves;
	int		collect;
	int		numplayers;
	int		numexit;
	int		columns;
}				t_data;

//main
int		main(int ac, char **av);
void	ft_get_images(t_data *g);

//map.c
int		ft_count_lines(t_data *g);
void	ft_remove_paragraph_in_lines(t_data *g);
void	place_images_in_game(t_data *g);
void	place_images_in_game2(t_data *g, int x, int y);
void	map_reading(t_data *g, char *av);

//utils.c
void	ft_init_stack(t_data *g);
void	ft_init_stack2(t_data *g);

//move.c
void	ft_put_image(t_data *g, int y, int x, char flag);
int		ft_move_player(t_data *g, int y, int x, char flag);
int		handle_input(int keysym, t_data *game);

//free.c
void	ft_free_map(t_data *g);
int		ft_finish(t_data *g);
int		ft_finish2(t_data *g);
void	ft_free_map2(t_data *g);

//check.c
void	ft_check_rectangle(t_data *g);
void	ft_check_columns(t_data *g);
void	ft_check_lines(t_data *g);
void	ft_check_letters(t_data *g);
void	ft_check_walls(t_data *g);

//check2.c
void	ft_check_elements(t_data *g);
void	ft_map_dup(t_data *g);
int		ft_flood_fill(t_data *g, char **map, int x, int y);
void	ft_check_path(t_data *g);

//coordenates
int		ft_coordenates(t_data *g, int x, int y);
int		last_move(t_data *g, int y, int x);

#endif
