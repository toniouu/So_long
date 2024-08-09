/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   searching_way.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atovoman <atovoman@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 09:58:26 by atovoman          #+#    #+#             */
/*   Updated: 2024/08/07 15:58:24 by atovoman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	remaking_map(t_map *map)
{
	int	y;
	int	x;

	y = 0;
	while (map->map[y] != NULL)
	{
		x = 0;
		while (map->map[y][x])
		{
			if (map->map[y][x] == 'L')
				map->map[y][x] = '0';
			else if (map->map[y][x] == 'c')
				map->map[y][x] = 'C';
			x++;
		}
		y++;
	}
}

int	checking_if_accessible(t_map *map, int x, int y)
{
	if (map->map[y - 1][x] == 'L' || map->map[y - 1][x] == 'c'
		|| map->map[y - 1][x] == 'P')
		return (1);
	if (map->map[y + 1][x] == 'L' || map->map[y + 1][x] == 'c'
		|| map->map[y + 1][x] == 'P')
		return (1);
	if (map->map[y][x - 1] == 'L' || map->map[y][x - 1] == 'c'
		|| map->map[y][x - 1] == 'P')
		return (1);
	if (map->map[y][x + 1] == 'L' || map->map[y][x + 1] == 'c'
		|| map->map[y][x + 1] == 'P')
		return (1);
	return (0);
}

void	searching_way(t_map *map, int x, int y)
{
	if (map->map[y][x] == '1' || map->map[y][x] == 'L')
		return ;
	if (map->map[y][x] == '0')
		map->map[y][x] = 'L';
	if (map->map[y][x] == 'C')
		map->map[y][x] = 'c';
	if (map->map[y][x - 1] == '0' || map->map[y][x - 1] == 'C'
		|| (map->map[y][x - 1] == 'E' && map->map[y][x - 2] != '1'))
		searching_way(map, x - 1, y);
	if (map->map[y][x + 1] == '0' || map->map[y][x + 1] == 'C'
		|| (map->map[y][x + 1] == 'E' && map->map[y][x + 2] != '1'))
		searching_way(map, x + 1, y);
	if (map->map[y - 1][x] == '0' || map->map[y - 1][x] == 'C'
		|| (map->map[y - 1][x] == 'E' && map->map[y - 2][x] != '1'))
		searching_way(map, x, y - 1);
	if (map->map[y + 1][x] == '0' || map->map[y + 1][x] == 'C'
		|| (map->map[y + 1][x] == 'E' && map->map[y + 2][x] != '1'))
		searching_way(map, x, y + 1);
}

int	start_searching(t_map *map)
{
	int	y;
	int	x;

	y = 0;
	player_position(map);
	searching_way(map, map->x, map->y);
	while (map->map[y] != NULL)
	{
		x = 0;
		while (map->map[y][x])
		{
			if ((map->map[y][x] == 'C' || map->map[y][x] == 'E')
				&& checking_if_accessible(map, x, y) == 0)
				return (0);
			x++;
		}
		y++;
	}
	remaking_map(map);
	return (1);
}
