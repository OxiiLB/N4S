##
## EPITECH PROJECT, 2022
## makefile
## File description:
## makefile
##

NAME	=	ai

PREFIX =	src/

FILES =	main.c						\
		str_to_command_array.c		\
		get_speed_and_degree.c		\
		array_utils.c				\
		get_track_cleared.c			\
		my_strtok.c					\
		print_car_instructions.c

SRC	=	$(addprefix $(PREFIX), $(FILES))

OBJ = $(SRC:.c=.o)

CFLAGS = -Wall -Wextra -I ./include

all: $(NAME)

$(NAME): $(OBJ)
	gcc -o $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)
	rm -f *.gcda
	rm -f *.gcno
	rm -f *~

re: fclean all

.PHONY: clean fclean all re NAME
