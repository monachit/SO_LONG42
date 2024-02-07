NAME = so_long
CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRCS = so_long.c check_error.c check_path.c so_longutils.c ft_read_map.c \
       get_next_line/get_next_line.c get_next_line/get_next_line_utils.c \
       game_plan.c ft_image.c ft_printf/ft_printf.c ft_printf/ft_allfunc.c \
	   ft_printf/ft_adr.c ft_printf/ft_putnbr.c

# Object files
OBJS = $(SRCS:.c=.o)

LIBS = -L/path/to/minilibx -lmlx -lX11 -lXext -lm libft.a 


all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBS)	
	
clean:
	rm -f $(OBJS)
fclean: clean
	rm -f $(NAME)
re: fclean all

.PHONY: all clean fclean re 