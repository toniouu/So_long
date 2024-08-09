/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moving_player.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atovoman <atovoman@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 20:36:08 by atovoman          #+#    #+#             */
/*   Updated: 2024/08/07 15:59:34 by atovoman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	moving_right(t_game *game)
{
	t_map	*t;

	t = game->mapping;
	if (t->map[t->y][t->x + 1] == 'W')
	{
		print_moves(++game->moves);
		ft_putchar('\n');
		ft_putstr("Féliciations ! Vous avez terminé le jeu !\n");
		clean_all(game, game->mapping);
		exit(EXIT_SUCCESS);
	}
	if (t->map[t->y][t->x + 1] == 'C')
		game->mapping->c--;
	game->mapping->map[game->mapping->y][game->mapping->x++] = '0';
	game->mapping->map[game->mapping->y][game->mapping->x] = 'P';
	print_moves(++game->moves);
	ft_putchar('\n');
}

void	moving_left(t_game *game)
{
	t_map	*t;

	t = game->mapping;
	if (t->map[t->y][t->x - 1] == 'W')
	{
		print_moves(++game->moves);
		ft_putchar('\n');
		ft_putstr("Féliciations ! Vous avez terminé le jeu !\n");
		clean_all(game, game->mapping);
		exit(EXIT_SUCCESS);
	}
	if (t->map[t->y][t->x - 1] == 'C')
		game->mapping->c--;
	else if (!t->map[t->y][t->x - 1])
		return ;
	game->mapping->map[game->mapping->y][game->mapping->x--] = '0';
	game->mapping->map[game->mapping->y][game->mapping->x] = 'P';
	print_moves(++game->moves);
	ft_putchar('\n');
}

void	moving_up(t_game *game)
{
	t_map	*t;

	t = game->mapping;
	if (t->map[t->y - 1][t->x] == 'W')
	{
		print_moves(++game->moves);
		ft_putchar('\n');
		ft_putstr("Féliciations ! Vous avez terminé le jeu !\n");
		clean_all(game, game->mapping);
		exit(EXIT_SUCCESS);
	}
	if (t->map[t->y - 1][t->x] == 'C')
		game->mapping->c--;
	game->mapping->map[game->mapping->y--][game->mapping->x] = '0';
	game->mapping->map[game->mapping->y][game->mapping->x] = 'P';
	print_moves(++game->moves);
	ft_putchar('\n');
}

void	moving_down(t_game *game)
{
	t_map	*t;

	t = game->mapping;
	if (t->map[t->y + 1][t->x] == 'W')
	{
		print_moves(++game->moves);
		ft_putchar('\n');
		ft_putstr("Féliciations ! Vous avez terminé le jeu !\n");
		clean_all(game, game->mapping);
		exit(EXIT_SUCCESS);
	}
	if (t->map[t->y + 1][t->x] == 'C')
		game->mapping->c--;
	game->mapping->map[game->mapping->y++][game->mapping->x] = '0';
	game->mapping->map[game->mapping->y][game->mapping->x] = 'P';
	print_moves(++game->moves);
	ft_putchar('\n');
}
