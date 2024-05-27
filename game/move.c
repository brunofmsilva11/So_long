/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmota-si <bmota-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 12:34:30 by bmota-si          #+#    #+#             */
/*   Updated: 2023/05/25 16:52:35 by bmota-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_put_image(t_data *g, int y, int x, char flag)
{
	if (flag == 'A')
		mlx_put_image_to_window(g->mlx, g->window, g->playera_img,
			x * SIZE, y * SIZE);
	else if (flag == 'W')
		mlx_put_image_to_window(g->mlx, g->window, g->playerw_img,
			x * SIZE, y * SIZE);
	else if (flag == 'S')
		mlx_put_image_to_window(g->mlx, g->window, g->players_img,
			x * SIZE, y * SIZE);
	else
		mlx_put_image_to_window(g->mlx, g->window, g->playerd_img,
			x * SIZE, y * SIZE);
}

int	ft_move_player(t_data *g, int y, int x, char flag)
{
	if (g->map[y][x] == 'C')
		g->collect--;
	if (last_move(g, y, x) == 1)
		return (1);
	if (g->map[y][x] == '0' || g->map[y][x] == 'C')
	{
		mlx_put_image_to_window(g->mlx, g->window, g->floor_img,
			g->p_x * SIZE, g->p_y * SIZE);
		ft_put_image(g, y, x, flag);
		g->map[g->p_y][g->p_x] = '0';
		g->map[y][x] = 'P';
		g->p_y = y;
		g->p_x = x;
		g->moves++;
		return (1);
	}
	else if (g->map[y][x] == 'E' && g->collect == 0)
	{
		ft_printf("Total Moves: %d\n", g->moves + 1);
		ft_finish(g);
	}
	return (0);
}

int	handle_input(int keysym, t_data *g)
{
	int	result;

	result = 0;
	if (keysym == XK_Escape)
		ft_finish (g);
	if (keysym == XK_w)
		result = ft_move_player(g, g->p_y - 1, g->p_x, 'W');
	if (keysym == XK_a)
		result = ft_move_player(g, g->p_y, g->p_x - 1, 'A');
	if (keysym == XK_s)
		result = ft_move_player(g, g->p_y + 1, g->p_x, 'S');
	if (keysym == XK_d)
		result = ft_move_player(g, g->p_y, g->p_x + 1, 'D');
	if (result == 1)
	{
		ft_printf("Move number: %d\n", g->moves);
		ft_printf("Collect number: %d\n", g->collect);
	}
	return (0);
}
