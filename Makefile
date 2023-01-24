NAME  = libftprintf.a
CC    = gcc
LIB   = ft_printf.h
FLAGS = -Wall -Wextra -Werror
AR    = ar rc
RUN   = ranlib
RM    = rm -rf
SRC   = ft_printf.c ft_printf_helpers.c
OBJ   = $(patsubst %.c, %.o, $(SRC))

# Colors
RESET  = \033[0
RED    = \033[31m
GREEN  = \033[32m
YELLOW = \033[33m

all: $(NAME)

$(NAME) : $(OBJ) Makefile $(LIB)
	@$(AR) $(NAME) $(OBJ)
	@$(RUN) $(NAME)
	@echo "$(GREEN)All done successfully!$(RESET)"

%.o : %.c
	@echo "$(YELLOW)Making object files...$(RESET)"
	@$(CC) $(FLAGS) -c $< -o $@

clean:
	@echo "$(RED)Deleting all object files.. $(RESET)"
	@$(RM) $(OBJ)

fclean: clean
	@echo "$(RED)Deleting $(NAME)... $(RESET)"
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re