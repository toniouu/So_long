/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atovoman <atovoman@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 10:32:58 by atovoman          #+#    #+#             */
/*   Updated: 2024/08/05 14:26:20 by atovoman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	creating_window(t_map *map, t_game *game)
{
	map_size(map, game);
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, game->w, game->h, "so_long");
	if (!game->mlx || !game->win)
	{
		ft_free_tab(map->map);
		exit(EXIT_FAILURE);
	}
	game->mapping = map;
	mlx_hook(game->win, 17, 0, closing_window, game);
	mlx_key_hook(game->win, handling_keypress, game);
}

int	closing_window(t_game *game)
{
	ft_putstr("Fermeture de fenetre !\n");
	clean_all(game, game->mapping);
	exit(EXIT_SUCCESS);
	return (0);
}
