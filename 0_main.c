/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0_main.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jutocche <jutocche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 15:28:15 by jutocche          #+#    #+#             */
/*   Updated: 2025/10/18 15:42:42 by jutocche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	main(int argc, char **argv)
{
	t_vars	vars;
	int		fd;

	if (argc != 2)
	{
		ft_printf("%s", "Usage: ./a.out map.fdf\n");
		return (1);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		ft_printf("%s", "Error: Could not open file\n");
		return (-1);
	}
	close(fd);
	vars.map = malloc(sizeof(t_map));
	if (!vars.map)
		return (2);
	count_lines_and_columns(vars.map, fd, argv[1]);
	vars.win_width = 1000;
	vars.win_height = 1000;
	mlx_functions(&vars);
	free_map_data(vars.map);
	vars.map = NULL;
	return (0);
}
