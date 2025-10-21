/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0_free_cub_and_close.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jutocche <jutocche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 14:11:55 by jutocche          #+#    #+#             */
/*   Updated: 2025/10/20 15:11:35 by jutocche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void free_cub_map(t_cub *cub)
{
	int i;

	i = 0;
	while (i < cub->line_count)
	{
		if (cub->map[i])
		{
			free(cub->map[i]);
			cub->map[i] = NULL;
		}
		i++;
	}
	free(cub->map);
}

void free_cub_filename(t_cub *cub)
{
	if (cub->filename)
	{
		free(cub->filename);
		cub->filename = NULL;
	}
}

void free_cub_and_close(t_cub *cub)
{
	if (cub->fd >= 0)
		close(cub->fd);
	free_cub_filename(cub);
	free_cub_map(cub);






	free(cub);
}

