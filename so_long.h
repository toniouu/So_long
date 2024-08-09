/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atovoman <atovoman@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 10:24:39 by atovoman          #+#    #+#             */
/*   Updated: 2024/08/05 14:33:11 by atovoman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "minilibx-linux/mlx.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

typedef struct s_game
{
	void			*mlx;
	void			*win;
	char			*map;
	int				w;
	int				h;
	int				moves;
	struct s_map	*mapping;
}	t_game;

typedef struct s_map
{
	void	*w;
	void	*g;
	void	*pr;
	void	*cbl;
	void	*ex;
	void	*exw;
	int		x;
	int		y;
	int		c;
	int		p;
	int		e;
	char	**map;
}	t_map;

typedef struct s_player
{
	int	x;
	int	y;
}	t_player;

int		ft_strlen(char *readed);
int		closing_window(t_game *game);
int		handling_keypress(int key, t_game *game);
int		start_searching(t_map *map);
int		checking_wall(t_map *map);
void	checking_ber(char *map);

char	*ft_strdup(char *s);
char	*add_to_readed(char *readed, char *buf);
char	*ft_substr(char *s, int start, int len);
char	*read_map(char *map);
char	**ft_split(char *s, char c);

void	ft_putchar(char c);
void	ft_putstr(char *s);
void	map_splited(char *av, t_map *map);
void	map_size(t_map *map, t_game *game);
void	creating_window(t_map *map, t_game *game);
void	my_put_image_to_window(t_game *game, t_map *map);
void	player_position(t_map *map);
void	moving_player_right(t_game *game);
void	moving_player_left(t_game *game);
void	moving_player_up(t_game *game);
void	moving_player_down(t_game *game);
void	moving_right(t_game *game);
void	moving_left(t_game *game);
void	moving_up(t_game *game);
void	moving_down(t_game *game);
void	count_elements(t_map *map);
void	player_win(t_map *map);
void	ft_free_tab(char **s);
void	clean_all(t_game *game, t_map *map);
void	clean_images(t_game *game, t_map *map);
void	print_moves(int moves);
void	checking_ber(char *map);
void	map_closed(char *map);
void	checking_if_rectangle(char **map);

#endif
