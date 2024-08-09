/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atovoman <atovoman@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 13:21:08 by atovoman          #+#    #+#             */
/*   Updated: 2024/08/02 16:03:17 by atovoman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	player_position(t_map *map)
{
	map->y = 0;
	while (map->map[map->y])
	{
		map->x = 0;
		while (map->map[map->y][map->x])
		{
			if (map->map[map->y][map->x] == 'P')
				break ;
			map->x++;
		}
		if (map->map[map->y][map->x] == 'P')
			break ;
		map->y++;
	}
}

void	moving_player_right(t_game *game)
{
	t_map	*t;

	t = game->mapping;
	if (t->map[t->y][t->x + 1] != '1' && t->map[t->y][t->x + 1] != 'E')
		moving_right(game);
	else if (t->map[t->y][t->x + 1] == 'E' && t->map[t->y][t->x + 2] != '1')
	{
		if (t->map[t->y][t->x + 2] == 'C')
			game->mapping->c--;
		game->mapping->map[game->mapping->y][game->mapping->x] = '0';
		game->mapping->x += 2;
		game->mapping->map[game->mapping->y][game->mapping->x] = 'P';
		print_moves(++game->moves);
		ft_putchar('\n');
	}
}

void	moving_player_left(t_game *game)
{
	t_map	*t;

	t = game->mapping;
	if (t->map[t->y][t->x - 1] != '1' && t->map[t->y][t->x - 1] != 'E')
		moving_left(game);
	else if (t->map[t->y][t->x - 1] == 'E' && t->map[t->y][t->x - 2] != '1')
	{
		if (t->map[t->y][t->x - 2] == 'C')
			game->mapping->c--;
		game->mapping->map[game->mapping->y][game->mapping->x] = '0';
		game->mapping->x -= 2;
		game->mapping->map[game->mapping->y][game->mapping->x] = 'P';
		print_moves(++game->moves);
		ft_putchar('\n');
	}
}

void	moving_player_up(t_game *game)
{
	t_map	*t;

	t = game->mapping;
	if (t->map[t->y - 1][t->x] != '1' && t->map[t->y - 1][t->x] != 'E')
		moving_up(game);
	else if (t->map[t->y - 1][t->x] == 'E' && t->map[t->y - 2][t->x] != '1')
	{
		if (t->map[t->y - 2][t->x] == 'C')
			game->mapping->c--;
		game->mapping->map[game->mapping->y][game->mapping->x] = '0';
		game->mapping->y -= 2;
		game->mapping->map[game->mapping->y][game->mapping->x] = 'P';
		print_moves(++game->moves);
		ft_putchar('\n');
	}
}

void	moving_player_down(t_game *game)
{
	t_map	*t;

	t = game->mapping;
	if (t->map[t->y + 1][t->x] != '1' && t->map[t->y + 1][t->x] != 'E')
		moving_down(game);
	else if (t->map[t->y + 1][t->x] == 'E' && t->map[t->y + 2][t->x] != '1')
	{
		if (t->map[t->y + 2][t->x] == 'C')
			game->mapping->c--;
		game->mapping->map[game->mapping->y][game->mapping->x] = '0';
		game->mapping->y += 2;
		game->mapping->map[game->mapping->y][game->mapping->x] = 'P';
		print_moves(++game->moves);
		ft_putchar('\n');
	}
}
