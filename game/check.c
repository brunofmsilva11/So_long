/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmota-si <bmota-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 15:10:03 by bmota-si          #+#    #+#             */
/*   Updated: 2023/05/25 16:54:03 by bmota-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_check_rectangle(t_data *g)
{
	int	i;
	int	j;

	i = 0;
	while (i < g->lines)
	{
		j = 0;
		while (g->map[i][j])
			j++;
		if (j == g->columns)
			i++;
		else
		{
			ft_putstr_fd("Error\nThis map is not a rectangle!\n", 2);
			ft_finish2(g);
			exit(0);
		}
	}
	ft_check_columns(g);
}

void	ft_check_columns(t_data *g)
{
	if (g->columns < 3)
	{
		ft_putstr_fd("Error\nYou will need more columns in your map!\n", 2);
		ft_finish2(g);
		exit (0);
	}
	ft_check_lines(g);
}

void	ft_check_lines(t_data *g)
{
	if (g->lines < 3)
	{
		ft_putstr_fd("Error\nYou will need more lines in your map!\n", 2);
		ft_finish2(g);
		exit (0);
	}
	ft_check_letters(g);
}

void	ft_check_letters(t_data *g)
{
	int	y;
	int	x;

	y = 0;
	while (y < g->lines)
	{
		x = 0;
		while (x < g->columns)
		{
			if (g->map[y][x] == '1' || g->map[y][x] == '0' ||
				g->map[y][x] == 'C' || g->map[y][x] == 'P' ||
				g->map[y][x] == 'E')
				x = ft_coordenates(g, x, y);
			else
			{	
				ft_putstr_fd("Error\n Invalid letter in the map\n", 2);
				ft_finish2(g);
			}
		}
		y++;
	}
	ft_check_walls(g);
}

void	ft_check_walls(t_data *g)
{
	int	i;

	i = 0;
	while (i < g->columns)
	{
		if (g->map[0][i] != '1' || g->map[g->lines - 1][i] != '1')
		{
			ft_putstr_fd("Error\nWall not valid!\n", 2);
			ft_finish2(g);
		}
		i++;
	}
	i = 1;
	while (i < g->lines - 1)
	{
		if (g->map[i][0] != '1' || g->map[i][g->columns - 1] != '1')
		{
			ft_putstr_fd("Error\nWall not valid!\n", 2);
			ft_finish2(g);
		}
		i++;
	}
	ft_check_elements(g);
}
