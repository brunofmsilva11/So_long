/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmota-si <bmota-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 11:38:41 by bmota-si          #+#    #+#             */
/*   Updated: 2023/05/26 12:27:42 by bmota-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_count_lines(t_data *g)
{
	int		i;
	char	*temp;

	i = 0;
	while (1)
	{
		temp = get_next_line(g->fd);
		if (!temp)
		{
			free(temp);
			break ;
		}
		free(temp);
		i++;
	}
	return (i);
}

void	ft_remove_paragraph_in_lines(t_data *g)
{
	int		i;
	char	*temp;

	i = 0;
	while (i <= g->lines)
	{
		temp = get_next_line(g->fd);
		if (!temp)
		{
			free(temp);
			break ;
		}
		g->map[i] = ft_strtrim(temp, "\n");
		free(temp);
		i++;
	}
		g->columns = ft_strlen(g->map[0]);
}

void	place_images_in_game2(t_data *g, int x, int y)
{
	if (g->map[y][x] == '1')
		mlx_put_image_to_window(g->mlx, g->window,
			g->wall_img, x * SIZE, y * SIZE);
	else if (g->map[y][x] == '0')
		mlx_put_image_to_window(g->mlx, g->window,
			g->floor_img, x * SIZE, y * SIZE);
	else if (g->map[y][x] == 'C')
		mlx_put_image_to_window(g->mlx, g->window,
			g->collect_img, x * SIZE, y * SIZE);
	else if (g->map[y][x] == 'P')
		mlx_put_image_to_window(g->mlx, g->window,
			g->players_img, x * SIZE, y * SIZE);
	else if (g->map[y][x] == 'E')
		mlx_put_image_to_window(g->mlx, g->window,
			g->exit_img, x * SIZE, y * SIZE);
}

void	place_images_in_game(t_data *g)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < g->lines)
	{
		x = 0;
		while (g->map[y][x] != '\0')
		{
			place_images_in_game2(g, x, y);
			x++;
		}
		y++;
	}
}

void	map_reading(t_data *g, char *av)
{
	g->fd = open(av, O_RDONLY);
	g->lines = ft_count_lines(g);
	close (g->fd);
	g->fd = open(av, O_RDONLY);
	g->map = ft_calloc(g->lines + 1, sizeof(char *));
	ft_remove_paragraph_in_lines(g);
	ft_check_rectangle(g);
	g->window = mlx_new_window(g->mlx,
			ft_strlen(g->map[0]) * SIZE, g->lines * SIZE, "window");
	if (g->window == NULL)
	{
		free(g->window);
		return ;
	}
	place_images_in_game(g);
	close(g->fd);
}
