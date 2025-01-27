CC = cc
CFLAGS = -Wall -Wextra -Werror
LFLAGS = -lmlx -framework OpenGL -framework AppKit

NAME = so_long
NAME_BONUS = so_long_bonus

SRC = mandatory/so_long.c mandatory/utils/utils.c mandatory/utils/get_next_line.c mandatory/utils/get_next_line_utils.c mandatory/utils/ft_split.c mandatory/check_map.c mandatory/check_path.c mandatory/game_ren.c mandatory/events.c mandatory/error.c mandatory/find_pos.c mandatory/ft_free.c
SRC_BONUS = bonus/so_long_bonus.c   bonus/utils/utils_bonus.c bonus/utils/get_next_line_bonus.c bonus/utils/get_next_line_utils_bonus.c bonus/utils/ft_split_bonus.c bonus/check_map_bonus.c bonus/check_path_bonus.c bonus/game_ren_bonus.c bonus/events_bonus.c bonus/error_bonus.c bonus/enemy_patrol_bonus.c bonus/enemy_moves_bonus.c bonus/find_pos_bonus.c bonus/ft_free_bonus.c

OBJ = $(SRC:.c=.o)
OBJ_BONUS = $(SRC_BONUS:.c=.o)

all : $(NAME)

bonus : $(NAME_BONUS)

$(NAME_BONUS) : $(OBJ_BONUS)
	$(CC) $(LFLAGS) -o $(NAME_BONUS) $(OBJ_BONUS)  

$(NAME) : $(OBJ)
	$(CC) $(LFLAGS) -o $(NAME) $(OBJ)

mandatory/%.o: mandatory/%.c mandatory/so_long.h
	$(CC) $(CFLAGS) -c $< -o $@

bonus/%.o: bonus/%.c bonus/so_long_bonus.h
	$(CC) $(CFLAGS) -c $< -o $@  

clean:
	rm -f $(OBJ) $(OBJ_BONUS)

fclean: clean
	rm -f $(NAME) $(NAME_BONUS)

re: fclean all