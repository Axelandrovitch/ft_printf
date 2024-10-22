NAME = libftprintf.a
CC = cc
FLAGS = -Wall -Wextra -Werror -g

SRC  = ft_printf.c handle_hexadecimal.c handle_pointer.c handle_int.c handle_char.c handle_str.c handle_unsigned.c
OBJ_DIR = obj
OBJ = $(SRC:%.c=$(OBJ_DIR)/%.o)

TEST = test.c
TEST_PATH = ./test

all:		$(NAME)

$(NAME):	$(OBJ_DIR) $(SRC) Makefile ft_printf.h
		@$(MAKE) $(OBJ)
		@ar rc	$(NAME) $(OBJ)

$(OBJ_DIR):
		@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: %.c Makefile ft_printf.h
	$(CC) $(FLAGS) -c $< -o $@

test:		$(OBJ_DIR) $(OBJ) $(TEST_PATH)/$(TEST)
		$(CC) $(FLAGS) $(TEST_PATH)/$(TEST) $(OBJ) -o unit_test

clean:
		@rm -rf $(OBJ_DIR)

fclean:	clean
		@rm -rf $(NAME) unit_test

re:	fclean all

.PHONY: all clean fclean re test
