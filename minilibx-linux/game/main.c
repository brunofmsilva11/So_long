/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmota-si <bmota-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 11:10:18 by bmota-si          #+#    #+#             */
/*   Updated: 2023/05/25 18:00:50 by bmota-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_map_file(t_data *g, char *file_name)
{
	int	i;

	i = 0;
	g->fd = open(file_name, O_RDONLY);
	i = ft_strlen(file_name) - 1;
	while (file_name[i] != '.')
		i--;
	if (ft_strncmp((file_name + i), ".ber", 4) != 0)
	{
		ft_putstr_fd("\033[1;31mInvalid file type!\n\033[0m", 2);
		close(g->fd);
		exit(1);
	}
	if (g->fd < 0)
	{
		ft_putstr_fd("\033[1;31mError\nInvalid FD\n", 2);
		close(g->fd);
		exit(1);
	}
	close(g->fd);
}

void	ft_get_images(t_data *g)
{
	g->wall_img = mlx_xpm_file_to_image(g->mlx, WALL, &g->x, &g->y);
	g->floor_img = mlx_xpm_file_to_image(g->mlx, FLOOR, &g->x, &g->y);
	g->collect_img = mlx_xpm_file_to_image(g->mlx, COLLECT, &g->x, &g->y);
	g->exit_img = mlx_xpm_file_to_image(g->mlx, EXIT, &g->x, &g->y);
	g->players_img = mlx_xpm_file_to_image(g->mlx, PLAYERS, &g->x, &g->y);
	g->playera_img = mlx_xpm_file_to_image(g->mlx, PLAYERA, &g->x, &g->y);
	g->playerw_img = mlx_xpm_file_to_image(g->mlx, PLAYERW, &g->x, &g->y);
	g->playerd_img = mlx_xpm_file_to_image(g->mlx, PLAYERD, &g->x, &g->y);
	g->playerf_img = mlx_xpm_file_to_image(g->mlx, PLAYERF, &g->x, &g->y);
}

int	main(int ac, char **av)
{
	t_data	g;

	if (ac != 2)
	{
		ft_putstr_fd("\033[1;31mError\nCheck the input!\n\033[0m", 2);
		return (0);
	}
	ft_init_stack(&g);
	ft_init_stack2(&g);
	if (ac == 2)
	{
		check_map_file(&g, av[1]);
		g.mlx = mlx_init();
		ft_get_images(&g);
		map_reading(&g, av[1]);
		mlx_hook(g.window, KeyPress, KeyPressMask, handle_input, &g);
		mlx_hook(g.window, DestroyNotify, ButtonPressMask, ft_finish, &g);
		mlx_loop(g.mlx);
	}
	return (0);
}
