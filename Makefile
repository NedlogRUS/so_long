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
MLXFLAGS = -Lmlx -lmlx -framework OpenGL -framework AppKit

all: $(NAME) $(LIBFTA) $(LIBGNLA)

%.o : %.c 
	$(CC) $(CFLAGS) -Imlx -c $< -o $@

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
