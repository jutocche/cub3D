/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   10_is_wall_textures_valid.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jutocche <jutocche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 10:48:49 by jutocche          #+#    #+#             */
/*   Updated: 2025/10/25 13:35:45 by jutocche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

bool is_wall_textures_valid(t_cub *cub)
{
	if (textures_NO_valid(cub) == false) // ajouter || lecture avec minilibx de .xpm interpretable
	{
		free_cub_and_close(cub);
		return (false);
	}
	if (textures_NO_valid(cub) == false) // ajouter || lecture avec minilibx de .xpm interpretable
	{
		free_cub_and_close(cub);
		return (false);
	}
	if (textures_NO_valid(cub) == false) // ajouter || lecture avec minilibx de .xpm interpretable
	{
		free_cub_and_close(cub);
		return (false);
	}
	if (textures_NO_valid(cub) == false) // ajouter || lecture avec minilibx de .xpm interpretable
	{
		free_cub_and_close(cub);
		return (false);
	}
	return (true);
}





// R 800 800
NO cub3d-tester/textures/wall.xpm
SO cub3d-tester/textures/bricks.xpm
WE cub3d-tester/textures/gold.xpm
EA cub3d-tester/textures/wood.xpm
// S cub3d-tester/textures/enemy.xpm
F 220,111,119
C 225,111,200




North texture
North texture:
NO ./path_to_the_north_texture
· identifier: NO
· path to the north texture
∗ South texture:
SO ./path_to_the_south_texture
· identifier: SO
· path to the south texture
∗ West texture:
WE ./path_to_the_west_texture
· identifier: WE
· path to the west texture
∗ East texture:
EA ./path_to_the_east_texture
· identifier: EA
· path to the east texture
∗ Floor color:
· identifier: F
· R,G,B colors in range [0,255]: 0, 255, 255

Red Blue Green

Ceiling color:
identifier: C
· R,G,B colors in range [0,255]: 0, 255, 255

Resolution

fichier pas en .xpm
no vide  pas de chemin 
resolution 500 500 800800 800 ou 80000000 ou vide 
rgb en dehors plage 1 255 ou vide 
+255
+4 couleur 
klettre à lq place
1 de chaque 
fichier .xpm
le fichier est lisible 
pad de doublon no ou autre 
pas autre chose que no ou autree 

rgb 
pas autres lettres que c et f 
couleur 0 255
3 nbr 
1 f et 1 c 

une ou plusieurs ligne entre chaque elements
un ou plusieurs espaces par ligne par element par informations 
ordre non specifique pour chaque element
chaque element commence par son identifiant et le chemin vers la texture 
