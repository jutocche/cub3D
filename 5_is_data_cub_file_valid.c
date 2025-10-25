/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   5_is_data_cub_file_valid.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jutocche <jutocche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 14:30:44 by jutocche          #+#    #+#             */
/*   Updated: 2025/10/25 10:54:29 by jutocche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

bool	is_data_cub_file_valid(t_cub *cub)
{
	if (is_all_elements_presents(cub) == false) // 7
	{
		free_cub_and_close(cub);
		return (false);
	}
	if (is_wall_textures_valid(cub) == false) // 4
	{
		free_cub_and_close(cub);
		return (false);
	}
	if (is_floor_or_ceiling_valid(cub) == false) // 2
	{
		free_cub_and_close(cub);
		return (false);
	}
	if (is_map_valid() == false) //1
	{
		free_cub_and_close(cub);
		return (false);
	}
	return (true);
}



