/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atovoman <atovoman@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 10:33:20 by atovoman          #+#    #+#             */
/*   Updated: 2024/08/05 14:23:47 by atovoman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	opening_file(char *map)
{
	int	fd;

	fd = open(map, O_RDONLY);
	if (fd == -1)
	{
		ft_putstr("Ce map n'existe pas !\n");
		exit(EXIT_FAILURE);
	}
	return (fd);
}

char	*read_map(char *map)
{
	int		fd;
	int		len_readed;
	char	*buf;
	char	*game;

	fd = opening_file(map);
	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		exit(EXIT_FAILURE);
	len_readed = 1;
	game = ft_strdup("");
	while (len_readed != 0)
	{
		len_readed = read(fd, buf, BUFFER_SIZE);
		if (len_readed == -1 || (len_readed == 0 && game[0] == '\0'))
		{
			free(buf);
			free(game);
			exit(EXIT_FAILURE);
		}
		buf[len_readed] = '\0';
		game = add_to_readed(game, buf);
	}
	free(buf);
	return (game);
}

void	map_splited(char *av, t_map *map)
{
	char	*map_brut;

	map_brut = read_map(av);
	map_closed(map_brut);
	map->map = ft_split(map_brut, '\n');
	free(map_brut);
	checking_if_rectangle(map->map);
	count_elements(map);
	if (checking_wall(map) == 0)
	{
		ft_putstr("Le map doit etre encadre par des murs !\n");
		ft_free_tab(map->map);
		exit(EXIT_FAILURE);
	}
	if (map->c <= 0 || map->e != 1
		|| map->p != 1 || start_searching(map) == 0)
	{
		ft_putstr("Map Invalide !\n");
		ft_free_tab(map->map);
		exit(EXIT_FAILURE);
	}
}

void	map_size(t_map *map, t_game *game)
{
	map->y = 0;
	map->x = 0;
	while (map->map[map->y][map->x] != '\0')
		map->x++;
	while (map->map[map->y] != NULL)
		map->y++;
	game->w = map->x * 32;
	game->h = map->y * 32;
	if (map->x == map->y)
	{
		write (1, "Le map doit être rectangulaire !\n", 33);
		ft_free_tab(map->map);
		exit(EXIT_FAILURE);
	}
}

void	count_elements(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	map->c = 0;
	map->p = 0;
	map->e = 0;
	while (map->map[i] != NULL)
	{
		j = 0;
		while (map->map[i][j] != '\0')
		{
			if (map->map[i][j] == 'C')
				map->c++;
			if (map->map[i][j] == 'P')
				map->p++;
			if (map->map[i][j] == 'E')
				map->e++;
			j++;
		}
		i++;
	}
}
