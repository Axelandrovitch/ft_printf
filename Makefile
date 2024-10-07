NAME = libftprintf.a
CC = cc
FLAGS = -Wall -Wextra -Werror

SRC = $(shell find . -name "*.c" ! -name "*_bonus.c")
BONUS_SRC = $(shell find . -name "*_bonus.c")

OBJ = $(SRC:.c=.o)
BONUS_OBJ = $(BONUS_SRC:.c=.o)

.PHONY: all clean fclean re bonus

all: $(NAME)

$(NAME): $(OBJ) Makefile libftprintf.h
	ar rc $(NAME) $(OBJ)

bonus: $(NAME) $(BONUS_OBJ) Makefile libftprintf.h
	ar rc $(NAME) $(BONUS_OBJ)

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

clean:
	@rm -f $(OBJ) $(BONUS_OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all
