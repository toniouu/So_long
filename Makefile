NAME = so_long

SRC = so_long.c gameplay.c image.c map.c player.c moving_player.c utils.c window.c ft_split.c searching_way.c map_error.c ft_clean.c

CFLAGS = -Wall -Wextra -Werror

OBJ = ${SRC:.c=.o}

MLXDIR = ./minilibx-linux
MLXLIB = ${MLXDIR}/libmlx.a
MLXFLAGS = -L$(MLXDIR) -lmlx -lXext -lX11 -lm


all: $(MLXLIB) $(NAME)

$(NAME): $(OBJ)
		cc $(OBJ) $(MLXFLAGS) -o $(NAME)

$(MLXLIB):
		@make -C $(MLXDIR)

.c.o:
		cc $(CFLAGS) -c $< -o $@

clean:
		rm -f $(OBJ)
		@make -C $(MLXDIR) clean

fclean: clean
		rm -f $(NAME)
		@make -C $(MLXDIR) clean

re: fclean all

.PHONY: all clean fclean re