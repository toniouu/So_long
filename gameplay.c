/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gameplay.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atovoman <atovoman@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 10:33:40 by atovoman          #+#    #+#             */
/*   Updated: 2024/08/05 14:25:56 by atovoman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	handling_keypress(int key, t_game *game)
{
	player_position(game->mapping);
	if (key == 'd' || key == 'D' || key == 65363)
		moving_player_right(game);
	else if (key == 'a' || key == 'A' || key == 65361)
		moving_player_left(game);
	else if (key == 'w' || key == 'W' || key == 65362)
		moving_player_up(game);
	else if (key == 's' || key == 'S' || key == 65364)
		moving_player_down(game);
	else if (key == 65307)
	{
		ft_putstr("Fermeture de fenetre !\n");
		clean_all(game, game->mapping);
		exit(EXIT_SUCCESS);
	}
	if (game->mapping->c == 0)
		player_win(game->mapping);
	my_put_image_to_window(game, game->mapping);
	return (0);
}

void	player_win(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (map->map[i] != NULL)
	{
		j = 0;
		while (map->map[i][j] != '\0')
		{
			if (map->map[i][j] == 'E')
			{
				map->map[i][j] = 'W';
				return ;
			}
			j++;
		}
		i++;
	}
}
