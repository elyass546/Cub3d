CC = @cc

FLAGS = -lmlx -framework OpenGL -framework AppKit

CFLAGS = -Wall -Werror -Wextra -fsanitize=address -g3

FILES = cub3d.c dda_algho.c new_window.c\
		line_counter.c get_next_line.c  \
		Map.c

NAME = cub3d

C_RED = \033[1;31m
C_GREEN = \033[1;32m
C_L_BLUE = \033[1;34m
C_RES = \033[0m

all : $(NAME)

$(NAME) : $(FILES)
		$(CC) $(CFLAGS) $(FLAGS) $(FILES) -o $(NAME)
		@echo "$(C_GREEN)["cub3d" CREATED]$(C_RES)"

clean :
	@rm -f $(NAME)
	@echo "$(C_RED)["cub3d" REMOVED]$(C_RES)"

fclean : clean

re : fclean all