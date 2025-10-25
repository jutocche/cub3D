/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jutocche <jutocche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 15:28:18 by jutocche          #+#    #+#             */
/*   Updated: 2025/10/25 13:34:35 by jutocche         ###   ########.fr       */
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
	int 		NO;
	int 		SO;
	int 		WE;
	int 		EA;
	int 		F;
	int			C;
	int			MAP;
	int			TOTAL_ELEMENTS;
	int			line_START_MAP;
	int			line_EA;
	int			index_path_EA;
	int			line_WE;
	int			index_path_WE;
	int			line_SO;
	int			index_path_SO;
	int			line_NO;
	int			index_path_NO;
	int			line_C;
	int			index_RGB_C;
	int			line_F;
	int			index_RGB_F;
	char *path_textures_NO;
	char *path_textures_SO;
	char *path_textures_EA;
	char *path_textures_WE;
	char *RGB_color_F;
	char *RGB_color_C;
	
	


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
bool			is_file_extension_cub_correct(char *file);

// 2_first_opening_file.c
bool			first_opening_file(t_cub *cub, char *file);
bool			is_opening_file_possible(t_cub *cub);

// 3_is_cub_file_readable.c
bool			is_cub_file_readable(t_cub *cub);
int				line_len_and_line_count(t_cub *cub);
bool			is_line(t_cub *cub, char *line);
int				count_i(char *line);
bool			is_allocation_map_success(t_cub *cub);

// 4_fill_map.c
void			fill_map(t_cub *cub);
int				fill_map_utils(t_cub *cub, int i, int j, char *line);

// 5_is_data_cub_file_valid.c
bool			is_data_cub_file_valid(t_cub *cub);

// 6_is_all_elements_presents.c
bool			is_all_elements_presents(t_cub *cub);
int				check_wall_textures(t_cub *cub, int i, int j);
int				check_floor_ceiling_and_map(t_cub *cub, int i, int j);

// 7_check_wall_textures.c
void			check_NO(t_cub *cub, int i, int j);
void			check_SO(t_cub *cub, int i, int j);
void			check_WE(t_cub *cub, int i, int j);
void			check_EA(t_cub *cub, int i, int j);

// 8_check_floor_ceiling_and_map.c
void			check_F(t_cub *cub, int i, int j);
void			check_C(t_cub *cub, int i, int j);
int				check_is_map(t_cub *cub, int i, int j);
int				is_invalid_element(t_cub *cub, int i, int j);

// 9_error_message_check.c
void			error_start_position(char c);
void			error_empty_space();
void			error_number_element(char *element);
void			error_invalid_element(void);

// 10_is_wall_textures_valid.c
bool			is_wall_textures_valid(t_cub *cub);

// 11_textures_NO_valid.c
bool textures_NO_valid(t_cub *cub);
int	path_textures_NO(t_cub *cub);
bool	is_file_extension_xpm_correct(char *line);
bool	is_path_readable_NO(t_cub *cub);

// 12_textures_SO_valid.c
bool textures_SO_valid(t_cub *cub);
int	path_textures_SO(t_cub *cub);
bool	is_path_readable_SO(t_cub *cub);

// 13_textures_WE_valid.c
bool textures_WE_valid(t_cub *cub);
int	path_textures_WE(t_cub *cub);
bool	is_path_readable_WE(t_cub *cub);

// 14_textures_EA_valid.c
bool textures_EA_valid(t_cub *cub);
int	path_textures_EA(t_cub *cub);
bool	is_path_readable_EA(t_cub *cub);

// 15_error_message_textures.c
void	error_empty_path(char *path);
void	error_extension_path(char *path);
void error_no_readable_path(char *path);

#endif
