/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   11_textures_NO_valid.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jutocche <jutocche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 12:49:33 by jutocche          #+#    #+#             */
/*   Updated: 2025/10/25 13:30:57 by jutocche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

bool	is_path_readable_NO(t_cub *cub)
{
	cub->fd = open(cub->path_textures_NO, O_RDONLY);
	if (cub->fd < 0)
		return (false);
	return (true);
}

bool	is_file_extension_xpm_correct(char *line, char *to_find)
{
	int		len_file;
	int		index;
	int		i;

	len_file = ft_strlen(line);
	index = 0;
	while (file[index] != '.' && file[index] != '\0')
		index++;
	if (len_file - 4 < index)
		return (false);
	index = 0;
	i = 0;
	while (file[index] != '.')
		index++;
	while (file[index + i] && to_find[i] && file[index + i] == to_find[i])
	{
		i++;
		if (file[index + i] == '\0')
			return (true);
	}
	return (false);
}


int	path_textures_NO(t_cub *cub)
{
	int start;
	int end;
	int len_path;
	
	start = 0;
	while (cub->map[cub->line_NO][cub->index_path_NO] != ' '
		|| cub->map[cub->line_NO][cub->index_path_NO] != '\0')
		cub->index_path_NO++;
	if (cub->map[cub->line_NO][cub->index_path_NO] == '\0')
		return (-1);
	start = cub->index_path_NO;
	while (cub->map[cub->line_NO][cub->index_path_NO] != ' '
		|| cub->map[cub->line_NO][cub->index_path_NO] != '\0')
		cub->index_path_NO++;
	end = cub->index_path_NO;
	len_path = end - start;
	if (len_path < 4)
		return (-2);
	cub->path_textures_NO = ft_strndup(cub->map[cub->line_NO] + start, len_path); // a rajouter dans free
	if (cub->path_textures_NO == NULL)
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
			error_empty_path("NO");
		else if (path == -2)
			error_extension_path("NO");
		else if (path == -3)
			ft_printf("Error\nft_strndup cub->map[... failed\n");
		return (false);
	}
	if (is_file_extension_xpm_correct(cub->path_textures_NO) == false)
	{
		error_extension_path("NO");
		return (false);
	}
	close(cub->fd);
	if (is_path_readable(cub) == false)
	{
		error_no_readable_path("NO");
		return (false);
	}
	return (true);
}
