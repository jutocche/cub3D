/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   4_fill_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jutocche <jutocche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 15:49:31 by jutocche          #+#    #+#             */
/*   Updated: 2025/10/20 14:34:32 by jutocche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int fill_map_utils(t_cub *cub, int i, int j, char *line)
{
	int tab;

	tab = 0;
	if (line[j] == '\t')
	{
		while (tab < 4)
		{
			cub->map[i][j] = ' ';
			j++;
			tab++;
		}
	}
	else if (line[j] != '\n' && line[j] != '\r' && line[j] != '\0')
	{
		cub->map[i][j] = line[j];
		j++;
	}
	else
	{
		cub->map[i][j] = ' ';
		j++;
	}
	return (j);
}

void fill_map(t_cub *cub)
{
	char *line;
	int i;
	int j;

	line = get_next_line(cub->fd);
	i = 0;
	while (line && i < cub->line_count)
	{
		j = 0;
		while(j < cub->line_len)
			j = fill_map_utils(cub, i, j, line);
		cub->map[i][j] = '\0';
		i++;
		j = 0;
		free(line);
		line = get_next_line(cub->fd);
	}
	if (line)
		free(line);
}
