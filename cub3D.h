/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jutocche <jutocche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 15:28:18 by jutocche          #+#    #+#             */
/*   Updated: 2025/10/20 15:03:16 by jutocche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "libft.h"
# include "mlx.h"
# include "mlx_int.h"
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>


// typedef struct	s_
// {

// }				t_;


typedef struct	s_cub
{
	int			fd;
	char		*filename;
	int			line_len;
	int			line_count;
	char		**map;


}				t_cub;

// 0_cub3D.c
int				main(int argc, char **argv);

// 0_free_cub_and_close.c
void			free_cub_and_close(t_cub *cub);
void			free_cub_filename(t_cub *cub);
void			free_cub_map(t_cub *cub);

// 1_is_name_file_correct.c
bool			is_name_file_correct(int argc, char *argv);
bool			is_file_argument(char *argv);
bool			is_number_argument_correct(int argc);
bool			is_file_extension_correct(char *file);

// 2_is_opening_file_possible.c
bool			first_opening_file(t_cub *cub, char *file);
bool			is_opening_file_possible(t_cub *cub);

// 3_is_data_file_correct.c
bool			is_data_file_correct(t_cub *cub);
int				line_len_and_line_count(t_cub *cub);
bool			is_line(t_cub *cub, char *line);
int				count_i(char *line);
bool			is_allocation_map_success(t_cub *cub);

// 4_fill_map.c
void			fill_map(t_cub *cub);
int				fill_map_utils(t_cub *cub, int i, int j, char *line);

#endif
