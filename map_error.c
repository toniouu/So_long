/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atovoman <atovoman@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 11:03:46 by atovoman          #+#    #+#             */
/*   Updated: 2024/08/05 14:14:06 by atovoman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	checking_ber(char *map)
{
	int	i;

	i = ft_strlen(map);
	if (map[i - 1] != 'r' || map[i - 2] != 'e'
		|| map[i - 3] != 'b' || map[i - 4] != '.')
	{
		write (1, "Veuillez entrer un map en extension .ber\n", 41);
		exit(EXIT_FAILURE);
	}
}

int	checking_wall(t_map *map)
{
	static int	y;
	static int	x;

	while (map->map[y][x] != '\0')
	{
		if (map->map[y][x++] != '1')
			return (0);
	}
	while (map->map[y] != NULL && map->map[y][x - 1])
	{
		if (map->map[y++][x - 1] != '1')
			return (0);
	}
	while (--x >= 0 && map->map[y - 1][x])
	{
		if (map->map[y - 1][x] != '1')
			return (0);
	}
	while (--y >= 0 && map->map[y])
	{
		if (map->map[y][0] != '1')
			return (0);
	}
	return (1);
}

void	map_closed(char *map)
{
	static int	i;

	while (map[i] != '\0')
	{
		if ((map[i] != '1' && map[i] != '0' && map[i] != 'P' && map[i] != 'C'
				&& map[i] != 'E' && map[i] != '\n') || map[0] != '1')
		{
			ft_putstr("Map Invalide !\n");
			free(map);
			exit (EXIT_FAILURE);
		}
		if (map[i] == '\n' && map[i + 1] == '\n')
		{
			ft_putstr("Map invalide !\n");
			free(map);
			exit (EXIT_FAILURE);
		}
		i++;
	}
}

void	checking_if_rectangle(char **map)
{
	int	y;

	y = 0;
	while (map[y + 1] != NULL && map[y])
	{
		if (ft_strlen(map[y]) != ft_strlen(map[y + 1]))
		{
			ft_free_tab(map);
			ft_putstr("Le map n'est pas rectangulaire !\n");
			exit(EXIT_FAILURE);
		}
		y++;
	}
}
