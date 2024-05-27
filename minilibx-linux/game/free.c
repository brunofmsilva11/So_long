/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmota-si <bmota-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 12:49:57 by bmota-si          #+#    #+#             */
/*   Updated: 2023/05/25 17:01:33 by bmota-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_free_map(t_data *g)
{
	int	i;

	i = 0;
	while (g->map[i])
	{
		free(g->map[i]);
		i++;
	}
	free(g->map);
}

void	ft_free_map2(t_data *g)
{
	int	i;

	i = 0;
	while (g->map_dup[i])
	{
		free(g->map_dup[i]);
		i++;
	}
	free(g->map_dup);
}

int	ft_finish(t_data *g)
{
	mlx_destroy_image(g->mlx, g->floor_img);
	mlx_destroy_image(g->mlx, g->wall_img);
	mlx_destroy_image(g->mlx, g->playera_img);
	mlx_destroy_image(g->mlx, g->playerw_img);
	mlx_destroy_image(g->mlx, g->playerd_img);
	mlx_destroy_image(g->mlx, g->players_img);
	mlx_destroy_image(g->mlx, g->playerf_img);
	mlx_destroy_image(g->mlx, g->exit_img);
	mlx_destroy_image(g->mlx, g->collect_img);
	mlx_destroy_window(g->mlx, g->window);
	mlx_destroy_display(g->mlx);
	ft_free_map(g);
	free(g->mlx);
	exit(0);
}

int	ft_finish2(t_data *g)
{
	mlx_destroy_image(g->mlx, g->floor_img);
	mlx_destroy_image(g->mlx, g->wall_img);
	mlx_destroy_image(g->mlx, g->playera_img);
	mlx_destroy_image(g->mlx, g->playerw_img);
	mlx_destroy_image(g->mlx, g->playerd_img);
	mlx_destroy_image(g->mlx, g->players_img);
	mlx_destroy_image(g->mlx, g->playerf_img);
	mlx_destroy_image(g->mlx, g->exit_img);
	mlx_destroy_image(g->mlx, g->collect_img);
	mlx_destroy_display(g->mlx);
	if (g->map != 0)
		ft_free_map(g);
	free(g->mlx);
	exit(0);
}
