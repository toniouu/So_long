/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atovoman <atovoman@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 10:44:31 by atovoman          #+#    #+#             */
/*   Updated: 2024/08/05 13:39:53 by atovoman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_putchar(char c)
{
	write (1, &c, 1);
}

void	ft_putstr(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		ft_putchar(s[i]);
		i++;
	}
}

void	print_moves(int moves)
{
	if (moves > 9)
	{
		print_moves(moves / 10);
		print_moves(moves % 10);
	}
	else
		ft_putchar(moves + 48);
}

int	main(int ac, char **av)
{
	t_map	map;
	t_game	game;

	if (ac != 2)
	{
		ft_putstr("Veuillez ajouter un map s'il vous plait !\n");
		exit(EXIT_FAILURE);
	}
	checking_ber(av[1]);
	game.moves = 0;
	map_splited(av[1], &map);
	creating_window(&map, &game);
	my_put_image_to_window(&game, &map);
	mlx_loop(game.mlx);
	return (0);
}
