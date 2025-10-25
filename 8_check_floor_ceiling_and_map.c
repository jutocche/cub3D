/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   8_check_floor_ceiling_and_map.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jutocche <jutocche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 10:43:06 by jutocche          #+#    #+#             */
/*   Updated: 2025/10/25 11:41:29 by jutocche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int is_invalid_element(t_cub *cub, int i, int j)
{
	if ((ft_strncmp(cub->map[i] + j, "NO", 2) != 0) &&
		(ft_strncmp(cub->map[i] + j, "SO", 2) != 0) &&
		(ft_strncmp(cub->map[i] + j, "WE", 2) != 0) &&
		(ft_strncmp(cub->map[i] + j, "EA", 2) != 0) &&
		(ft_strncmp(cub->map[i] + j, "F", 1) != 0) &&
		(ft_strncmp(cub->map[i] + j, "C", 1) != 0) &&
		(cub->map[i][j] != '1'))
	{
		if (cub->map[i][j] == '0')
			error_empty_space();
		if (cub->map[i][j] == 'N')
			error_start_position('N')
		if (cub->map[i][j] == 'S')
			error_start_position('S')
		if (cub->map[i][j] == 'E')
			error_start_position('E')
		if (cub->map[i][j] == 'W')
			error_start_position('W')
		else
			error_invalid_element(void);
		return (-1);
	}	
	return (0);
}

int check_is_map(t_cub *cub, int i, int j)
{
	if (ft_strncmp(cub->map[i] + j, "1", 1) == 0)
	{
		cub->MAP = 1;
		if (cub->TOTAL_ELEMENTS++; != 6)
		{
			printf("Error\nOnly %d element(s) parse before the map. Map must always be the last, after the 6 elements (NO, SO, WE, EA, F, C).\n", TOTAL);
			return (-1)
		}
		cub->line_START_MAP = i;
		return (1);
	}
	return (0);
}

void check_C(t_cub *cub, int i, int j)
{
	if (ft_strncmp(cub->map[i] + j, "C", 1) == 0)
	{
		if (cub->C == 0)
		{
			cub->C = 1;
			cub->TOTAL_ELEMENTS++;
			cub->line_C = i;
			cub->index_RGB_C = j+1;
			return (1);
		}
		else
		{
			error_number_element("C");
			return (-1);
		}
	}
	return (0);
}
void check_F(t_cub *cub, int i, int j)
{
	if (ft_strncmp(cub->map[i] + j, "F", 1) == 0)
	{
		if (cub->F == 0)
		{
			cub->F = 1;
			cub->TOTAL_ELEMENTS++;
			cub->line_F = i;
			cub->index_RGB_F = j+1;
			return (1);
		}
		else
		{
			error_number_element("F");
			return (-1);
		}
	}
	return (0);
}
