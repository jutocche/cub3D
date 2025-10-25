/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   13_textures_WE_valid.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jutocche <jutocche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 12:49:33 by jutocche          #+#    #+#             */
/*   Updated: 2025/10/25 13:26:59 by jutocche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

bool	is_path_readable_WE(t_cub *cub)
{
	cub->fd = open(cub->path_textures_WE, O_RDONLY);
	if (cub->fd < 0)
		return (false);
	return (true);
}

int	path_textures_NO(t_cub *cub)
{
	int start;
	int end;
	int len_path;
	
	start = 0;
	while (cub->map[cub->line_WE][cub->index_path_WE] != ' '
		|| cub->map[cub->line_WE][cub->index_path_WE] != '\0')
		cub->index_path_WE++;
	if (cub->map[cub->line_WE][cub->index_path_WE] == '\0')
		return (-1);
	start = cub->index_path_WE;
	while (cub->map[cub->line_WE][cub->index_path_WE] != ' '
		|| cub->map[cub->line_WE][cub->index_path_WE] != '\0')
		cub->index_path_WE++;
	end = cub->index_path_WE;
	len_path = end - start;
	if (len_path < 4)
		return (-2);
	cub->path_textures_WE = ft_strndup(cub->map[cub->line_WE] + start, len_path); // a rajouter dans free
	if (cub->path_textures_WE == NULL)
		return (-3);
	return (0);
}

bool textures_NO_valid(t_cub *cub)
{
	int path;

	path = path_textures_NO;
	if (path < 0)
	{
		if (path == -1)
			error_empty_path("WE");
		else if (path == -2)
			error_extension_path("WE");
		else if (path == -3)
			ft_printf("Error\nft_strndup cub->map[... failed\n");
		return (false);
	}
	if (is_file_extension_xpm_correct(cub->path_textures_WE) == false)
	{
		error_extension_path("WE");
		return (false);
	}
	close(cub->fd);
	if (is_path_readable(cub) == false)
	{
		error_no_readable_path("WE");
		return (false);
	}
	return (true);
}
