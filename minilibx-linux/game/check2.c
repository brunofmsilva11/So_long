/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmota-si <bmota-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 15:47:05 by bmota-si          #+#    #+#             */
/*   Updated: 2023/05/25 16:58:23 by bmota-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_check_elements(t_data *g)
{
	if (g->numplayers != 1)
	{
		ft_putstr_fd("Error\nWrong number of player elements!\n", 2);
		ft_finish2(g);
		exit (0);
	}
	else if (g->numexit != 1)
	{
		ft_putstr_fd("Error\nWrong number of exit elements!\n", 2);
		ft_finish2(g);
		exit (0);
	}
	else if (g->collect < 1)
	{
		ft_putstr_fd("Error\nWrong number of collectibles elements!\n", 2);
		ft_finish2(g);
		exit (0);
	}
	ft_check_path(g);
}

void	ft_map_dup(t_data *g)
{
	int	i;

	i = 0;
	g->map_dup = ft_calloc(g->lines + 1, sizeof(char *));
	while (i < g->lines)
	{
		g->map_dup[i] = ft_strdup(g->map[i]);
		i++;
	}
}

int	ft_flood_fill(t_data *g, char **map, int x, int y)
{
	static int	c = 0;
	static int	e = 0;

	if (y < 0 || x < 0 || y > g->lines
		|| x > g->columns || map[y][x] == '1'
		|| map[y][x] == 'X')
		return (0);
	if (map[y][x] == 'E')
	{
		e = e + 1;
		map[y][x] = 'X';
		return (0);
	}
	if (map[y][x] == 'C')
		c++;
	map[y][x] = 'X';
	ft_flood_fill(g, map, x + 1, y);
	ft_flood_fill(g, map, x - 1, y);
	ft_flood_fill(g, map, x, y + 1);
	ft_flood_fill(g, map, x, y - 1);
	if (e == 1 && c == g->collect)
		return (1);
	else
		return (0);
}

void	ft_check_path(t_data *g)
{
	ft_map_dup(g);
	if (ft_flood_fill(g, g->map_dup, g->p_x, g->p_y) != 1)
	{
		ft_putstr_fd("Error\nInvalid Map Path\n", 2);
		ft_free_map2(g);
		ft_finish2(g);
	}
	else
		ft_free_map2(g);
}
