R 800 800
NO cub3d-tester/textures/wall.xpm
SO cub3d-tester/textures/bricks.xpm
WE cub3d-tester/textures/gold.xpm
EA cub3d-tester/textures/wood.xpm
S cub3d-tester/textures/enemy.xpm
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


void check(char *line, int j)
{
	if (ft_strncmp(line + j, "NO", 2) == 0)
	{
		if (NO == 0)
			NO = 1;
			nbr_entree++;
		else
			NO += 1;
	}

	else if (ft_strncmp(line + j, "SO", 2) == 0)
		SO = 1;
	else if (ft_strncmp(line + j, "WE", 2) == 0)
		WE = 1;
	else if (ft_strncmp(line + j, "EA", 2) == 0)
		EA = 1;
	else if (ft_strncmp(line + j, "F", 1) == 0)
		F = 1;
	else if (ft_strncmp(line + j, "C", 1) == 0)
		C = 1;
	else if (ft_strncmp(line + j, "R", 1) == 0)
		R = 1;
		ne pas le compter dans all included mais en parametre pour la resolution feetre 
	else if (ft_strncmp(line + j, "1", 1) == 0)
		MAP = 1;
	else
		Wrong = 1;
}

void
{
	int i;
	int j;

	i = 0;
	while (cub->map[i])
	{
		j = 0;
		while (cub->map[i][j])
		{
			while (cub->map[i][j] == ' ')
				j++;
			 (cub->map[i], j)



		}
		i++;
		all_is_entry
	}

	}

si fin du fichier et pas map et pas tout
	erreur
si map avant tout le reste erreur
	flag all is included
si map apres le reste mais pas all included (manque un)
	erreur
	donc forcement on les bons flags
si on en a error = 1;
	une mauvaise entree dans le fichier
si on a plusieurs fois une entree genre no = 2;
on pourrait compter le nbr d'entree et voir si on a le bon nombre mais a voir
si on compte sprite ou pas
