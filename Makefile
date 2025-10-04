NAME = fdf
CC = cc
CFLAGS = -Wall -Wextra -Werror -g

SRCS = main.c\
	main_data_func.c\
	main_img_func.c\
	counting.c\
	mapping.c\
	drawing.c\
	bresenham_func.c\
	bresenham_func2.c

LIBFTDIR = ./libft
LIBFTFILE = libft.a
LIBFT = $(LIBFTDIR)/$(LIBFTFILE)

GNLDIR = ./get_next_line
GNLFILE = get_next_line.a
GNL = $(GNLDIR)/$(GNLFILE)

MLXDIR = ./mlx_linux
MLXFLAGS = -L$(MLXDIR) -lmlx -lX11 -lXext -lm
MLX = $(MLXDIR)/libmlx.a

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	make -C $(LIBFTDIR)
	make -C $(GNLDIR)
	make -C $(MLXDIR)
	$(CC) $(CFLAGS) $(OBJS) $(GNL) $(LIBFT) $(MLXFLAGS) -o $(NAME)

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	make -C $(LIBFTDIR) clean
	make -C $(GNLDIR) clean
	rm -rf $(OBJS)

fclean: clean
	make -C $(LIBFTDIR) fclean
	make -C $(GNLDIR) fclean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re