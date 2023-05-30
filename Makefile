NAME = so_long
SRCS = so_long.c check_map.c render_map.c
OBJS = $(SRCS:%.c=%.o)
CC = cc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror
LIBFT = ./libft
LIBFTA = $(LIBFT)/libft.a
LIBGNL = ./get_next_line
LIBGNLA = $(LIBGNL)/libgnl.a
LIBS = -L$(LIBFTA) -lft -L$(LIBGNLA) -lft
#FOR_MAC
#MLXFLAGS = -Lmlx -lmlx -framework OpenGL -framework AppKit
#FOR_LINUX
MLXFLAGS = -Lmlx_linux -lmlx_Linux -L./mlx-linux -Imlx_linux -lXext -lX11 -lm -lz

all: $(NAME) $(LIBFTA) $(LIBGNLA)

#FOR_MAC
# %.o : %.c 
# 	$(CC) $(CFLAGS) -Imlx -c $< -o $@

#FOR_LINUX
%.o: %.c
	$(CC) $(CFLAGS) -I./mlx-linux -Imlx_linux -O3 -c $< -o $@

$(NAME): $(LIBFTA) $(LIBGNLA) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFTA) $(LIBGNLA) $(MLXFLAGS) -o $(NAME)

$(LIBFTA):
	@$(MAKE) -C $(LIBFT)

$(LIBGNLA):
	@$(MAKE) -C $(LIBGNL)

clean:
	$(RM) $(OBJS)
	@$(MAKE) -C $(LIBFT) clean
	@$(MAKE) -C $(LIBGNL) clean

fclean: clean
	$(RM) $(NAME)
	@$(MAKE) -C $(LIBFT) fclean
	@$(MAKE) -C $(LIBGNL) fclean

re: fclean all

.PHONY : all clean fclean re
