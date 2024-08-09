/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clean.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atovoman <atovoman@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 14:51:07 by atovoman          #+#    #+#             */
/*   Updated: 2024/07/30 12:43:07 by atovoman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	clean_images(t_game *game, t_map *map)
{
	mlx_destroy_image(game->mlx, map->cbl);
	mlx_destroy_image(game->mlx, map->ex);
	mlx_destroy_image(game->mlx, map->exw);
	mlx_destroy_image(game->mlx, map->pr);
	mlx_destroy_image(game->mlx, map->w);
	mlx_destroy_image(game->mlx, map->g);
}

void	clean_all(t_game *game, t_map *map)
{
	ft_free_tab(map->map);
	clean_images(game, map);
	mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
}
