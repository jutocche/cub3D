/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   9_error_message_check.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jutocche <jutocche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 10:43:10 by jutocche          #+#    #+#             */
/*   Updated: 2025/10/25 10:43:12 by jutocche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void error_invalid_element(void)
{
	printf("Error\nUnknown element in file .cub. 6 elements are required (NO, SO, WE, EA, F, C) and in last the map.\n");
}

void error_number_element(char *element)
{
	printf("Error\nToo many element %s in file .cub\n", element);
}

void error_empty_space()
{
	printf("Error\nEmpty space '0' must be inside the map. The map must be closed/surrounded by walls.\n")
}

void error_start_position(char c)
{
	printf("Error\nThe player's start position and spawning orientation '%c' must be inside the map. The map must be closed/surrounded by walls.\n", c);
}
