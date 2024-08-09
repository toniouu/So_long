/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atovoman <atovoman@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 11:16:54 by atovoman          #+#    #+#             */
/*   Updated: 2024/08/02 16:04:04 by atovoman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	creating_images(t_game *gm, t_map *map)
{
	map->x = 0;
	map->y = 0;
	map->g = mlx_xpm_file_to_image(gm->mlx, "Assets/0.xpm", &gm->w, &gm->h);
	map->w = mlx_xpm_file_to_image(gm->mlx, "Assets/1.xpm", &gm->w, &gm->h);
	map->cbl = mlx_xpm_file_to_image(gm->mlx, "Assets/C.xpm", &gm->w, &gm->h);
	map->pr = mlx_xpm_file_to_image(gm->mlx, "Assets/P.xpm", &gm->w, &gm->h);
	map->ex = mlx_xpm_file_to_image(gm->mlx, "Assets/E.xpm", &gm->w, &gm->h);
	map->exw = mlx_xpm_file_to_image(gm->mlx, "Assets/W.xpm", &gm->w, &gm->h);
}

void	putting_images(t_game *g, t_map *m)
{
	if (m->map[m->y][m->x] == '1')
		mlx_put_image_to_window(g->mlx, g->win, m->w, m->x * 32, m->y * 32);
	else if (m->map[m->y][m->x] == '0')
		mlx_put_image_to_window(g->mlx, g->win, m->g, m->x * 32, m->y * 32);
	else if (m->map[m->y][m->x] == 'P')
		mlx_put_image_to_window(g->mlx, g->win, m->pr, m->x * 32, m->y * 32);
	else if (m->map[m->y][m->x] == 'C')
		mlx_put_image_to_window(g->mlx, g->win, m->cbl, m->x * 32, m->y * 32);
	else if (m->map[m->y][m->x] == 'E')
		mlx_put_image_to_window(g->mlx, g->win, m->ex, m->x * 32, m->y * 32);
	else if (m->map[m->y][m->x] == 'W')
		mlx_put_image_to_window(g->mlx, g->win, m->exw, m->x * 32, m->y * 32);
}

void	my_put_image_to_window(t_game *game, t_map *map)
{
	static int	i;

	if (i++ != 0)
		clean_images(game, map);
	creating_images(game, map);
	while (map->map[map->y] != NULL)
	{
		map->x = 0;
		while (map->map[map->y][map->x])
		{
			putting_images(game, map);
			map->x++;
		}
		map->y++;
	}
}
