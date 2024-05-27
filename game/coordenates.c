/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coordenates.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmota-si <bmota-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 15:30:29 by bmota-si          #+#    #+#             */
/*   Updated: 2023/05/25 17:00:27 by bmota-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_coordenates(t_data *g, int x, int y)
{
	if (g->map[y][x] == 'P')
	{
		g->p_y = y;
		g->p_x = x;
		g->numplayers++;
	}
	if (g->map[y][x] == 'E')
	{
		g->f_y = y;
		g->f_x = x;
		g->numexit++;
	}
	if (g->map[y][x] == 'C')
		g->collect++;
	x++;
	return (x);
}

int	last_move(t_data *g, int y, int x)
{
	if (((g->f_y - 1 == y && g->f_x == x)
			|| (g->f_y + 1 == y && g->f_x == x)
			|| (g->f_y == y && g->f_x - 1 == x)
			|| (g->f_y == y && g->f_x + 1 == x))
		&& (g->map[y][x] == '0' || g->map[y][x] == 'C')
			&& g->collect == 0)
	{
		mlx_put_image_to_window(g->mlx, g->window, g->floor_img,
			g->p_x * SIZE, g->p_y * SIZE);
		mlx_put_image_to_window(g->mlx, g->window, g->playerf_img,
			x * SIZE, y * SIZE);
		g->map[g->p_y][g->p_x] = '0';
		g->map[y][x] = 'P';
		g->p_y = y;
		g->p_x = x;
		g->moves++;
		return (1);
	}
	return (0);
}
