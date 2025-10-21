/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0_cub3D.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jutocche <jutocche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 15:28:15 by jutocche          #+#    #+#             */
/*   Updated: 2025/10/20 15:04:07 by jutocche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	main(int argc, char **argv)
{
	t_cub	*cub;
	if (is_name_file_correct(argc, argv[1]) == false)
		return (-1);
	cub = calloc(1, sizeof(t_cub));
	if (cub == NULL)
	{
		ft_printf("Error\nCalloc cub failed\n");
		return (-2);
	}
	if (first_opening_file(cub, argv[1]) == false)
		return (-3);
	if (is_data_file_correct(cub) == false)
		return (-4);



	free_cub_and_close(cub);
	return (0);
}

/*
malloc ou calloc pour zero
t_cub *cub ou t_cub cub
comment parser .cub
fd reste il ? non mais on peut

ligne de 1 ou colonne de 1
=> non
nbr pair de 1
=> non

		1111111111111111111111111
		1000000000110000000000001
		1011000001110000000000001
		1001000000000000000000001
111111111011000001110000000000001
100000000011000001110111111111111
11110111111111011100000010001
11110111111111011101010010001
11000000110101011100000010001
10000000000000001100000010001
10000000000000001101010010001
11000001110101011111011110N0111
11110111 1110101 101111010001
11111111 1111111 111111111111


*/
