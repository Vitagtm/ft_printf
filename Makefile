NAME = libftprintf.a

CC = cc

CFILES = base_printf.c ft_print_hex.c ft_print_pointer.c ft_printf.c

CFLAGS = -Wall -Wextra -Werror

OBJS = $(CFILES:.c=.o)

all: $(NAME)

$(NAME):$(OBJS)
	@echo "Compiling $(NAME)"
	@ar -rc $(NAME) $(OBJS)

clean:
	@echo "removing obj"
	rm -f $(OBJS)
fclean: clean
	@echo "removing $(NAME)"
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
