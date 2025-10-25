/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   6_is_all_elements_presents.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jutocche <jutocche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 10:39:25 by jutocche          #+#    #+#             */
/*   Updated: 2025/10/25 11:22:25 by jutocche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int check_floor_ceiling_and_map(t_cub *cub, int i, int j)
{
    if (check_F(cub, i, j) == 1)
		return (1);
	else if (check_F(cub, i, j) == -1)
		return (-1);
	else if (check_C(cub, i, j) == 1)
		return (1);
	else if (check_C(cub, i, j) == -1)
		return (-1);
	if (check_is_map(cub, i, j) == 1)
		return (1);
	if (check_is_map(cub, i, j) == -1)
		return (-1);
	if (is_invalid_element(cub, i, j) == -1)
		return (-1);
	printf("DEBUG check elements: cas non gere\n"); // debug a supprimer a la fin
	return (0);
}

int check_wall_textures(t_cub *cub, int i, int j)
{
	if (check_NO(cub, i, j) == 1)
		return (1);
	if (check_NO(cub, i, j) == -1)
		return (-1);
	else if (check_SO(cub, i, j) == 1)
		return (1);
	else if (check_SO(cub, i, j) == -1)
		return (-1);
	else if (check_WE(cub, i, j) == 1)
		return (1);
	else if (check_WE(cub, i, j) == -1)
		return (-1);
	else if (check_EA(cub, i, j) == 1)
		return (1);
	else if (check_EA(cub, i, j) == -1)
		return (-1);
	return (0);
}

bool is_all_elements_presents(t_cub *cub)
{
	int i;
	int j;
	int check;
	int check_2;

	i = 0;
	while (cub->map[i])
	{
		j = 0;
		while (cub->map[i][j])
		{
			while (cub->map[i][j] == ' ')
				j++;
			check = check_wall_textures(cub, i, j);
			check_2 = check_floor_ceiling_and_map(cub, i, j);
			if (check < 0 || check_2 < 0)
				return (false);
		}
		i++;
	}
	return (true);
}
