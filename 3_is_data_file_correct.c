/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3_is_data_file_correct.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jutocche <jutocche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 14:04:54 by jutocche          #+#    #+#             */
/*   Updated: 2025/10/20 15:24:49 by jutocche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

bool	is_allocation_map_success(t_cub *cub)
{
	int	i;

	i = 0;
	cub->map = malloc(sizeof(char *) * (cub->line_count + 1));
	if (cub->map == NULL)
	{
		ft_printf("Error\nMalloc cub->map failed\n");
		free_cub_and_close(cub);
		return (false);
	}
	while (i < cub->line_count)
	{
		cub->map[i] = malloc(sizeof(char) * (cub->line_len + 1));
		if (cub->map[i] == NULL)
		{
			ft_printf("Error\nMalloc cub->map[i] failed\n");
			free_cub_and_close(cub);
			return (false);
		}
		i++;
	}
	cub->map[i] = NULL;
	return (true);
}

int	count_i(char *line)
{
	int	i;

	i = 0;
	while (line[i] && line[i] != '\n' && line[i] != '\r')
	{
		if (line[i] == '\t')
			i += 4;
		else
			i++;
	}
	return (i);
}

bool	is_line(t_cub *cub, char *line)
{
	if (line == NULL)
	{
		printf("Error\nget next line failed\n");
		free_cub_and_close(cub);
		return (false);
	}
	return (true);
}

int	line_len_and_line_count(t_cub *cub)
{
	char	*line;
	int		i;

	printf("%d\n", cub->fd);
	line = get_next_line(cub->fd);
	if (is_line(cub, line) == false)
		return (1);
	while (line)
	{
		i = count_i(line);
		if (i > cub->line_len)
			cub->line_len = i;
		cub->line_count++;
		free(line);
		line = get_next_line(cub->fd);
	}
	if (line)
		free(line);
	return (0);
}

bool	is_data_file_correct(t_cub *cub)
{
	if (line_len_and_line_count(cub) == 1)
		return (false);
	close(cub->fd);
	if (is_opening_file_possible(cub) == false)
		return (false);
	if (is_allocation_map_success(cub) == false)
		return (false);
	fill_map(cub);
	return (true);
}
