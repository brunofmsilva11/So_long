/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmota-si <bmota-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 12:14:17 by bmota-si          #+#    #+#             */
/*   Updated: 2023/05/26 12:02:11 by bmota-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_init_stack(t_data *g)
{
	g->wall_img = 0;
	g->floor_img = 0;
	g->collect_img = 0;
	g->playera_img = 0;
	g->playerw_img = 0;
	g->playerd_img = 0;
	g->players_img = 0;
	g->playerf_img = 0;
	g->exit_img = 0;
	g->mlx = 0;
	g->lines = 0;
	g->map = 0;
}

void	ft_init_stack2(t_data *g)
{
	g->map_dup = 0;
	g->window = 0;
	g->fd = 0;
	g->x = 0;
	g->y = 0;
	g->p_x = 0;
	g->p_y = 0;
	g->f_x = 0;
	g->f_y = 0;
	g->moves = 0;
	g->collect = 0;
	g->numplayers = 0;
	g->numexit = 0;
	g->columns = 0;
}
