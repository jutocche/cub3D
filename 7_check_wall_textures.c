/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   7_check_wall_textures.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jutocche <jutocche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 10:42:58 by jutocche          #+#    #+#             */
/*   Updated: 2025/10/25 11:29:16 by jutocche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void check_EA(t_cub *cub, int i, int j)
{
	if (ft_strncmp(cub->map[i] + j, "EA", 2) == 0)
	{
		if (cub->EA == 0)
		{
			cub->EA = 1;
			cub->TOTAL_ELEMENTS++;
			cub->line_EA = i;
			cub->index_path_EA = j+2;
			return (1);
		}
		else
		{
			error_number_element("EA");
			return (-1);
		}
	}
	return (0);
}
void check_WE(t_cub *cub, int i, int j)
{
	if (ft_strncmp(cub->map[i] + j, "WE", 2) == 0)
	{
		if (cub->WE == 0)
		{
			cub->WE = 1;
			cub->TOTAL_ELEMENTS++;
			cub->line_WE = i;
			cub->index_path_WE = j+2;
			return (1);
		}
		else
		{
			error_number_element("WE");
			return (-1);
		}
	}
	return (0);
}

void check_SO(t_cub *cub, int i, int j)
{
	if (ft_strncmp(cub->map[i] + j, "SO", 2) == 0)
	{
		if (cub->SO == 0)
		{
			cub->SO = 1;
			cub->TOTAL_ELEMENTS++;
			cub->line_SO = i;
			cub->index_path_SO = j+2;
			return (1);
		}
		else
		{
			error_number_element("SO");
			return (-1);
		}
			
	}
	return (0);
}

void check_NO(t_cub *cub, int i, int j)
{
	if (ft_strncmp(cub->map[i] + j, "NO", 2) == 0)
	{
		if (cub->NO == 0)
		{
			cub->NO = 1;
			cub->TOTAL_ELEMENTS++;
			cub->line_NO = i;
			cub->index_path_NO = j+2;
			return (1);
		}
		else
		{
			error_number_element("NO");
			return (-1);
		}
	}
	return (0);
}
