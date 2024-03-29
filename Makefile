NAME = libgnl.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRCS = get_next_line.c get_next_line_utils.c
OBJS = $(SRCS:%.c=%.o)

INCS = get_next_line.h

all: $(NAME)

$(NAME): $(OBJS)
	ar -rc $(NAME) $(OBJS)
%.o: %.c $(INCS)
	$(CC) $(CFLAGS) -c $< -o $@
clean:
	rm -f $(OBJS)
fclean: clean
	rm -f $(NAME)
re: fclean all

.PHONY: all clean fclean re
