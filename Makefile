NAME = so_long
NAMEB = so_long_bonus
SRCDIR = src
OBJDIR = obj
SRCBDIR = srcb
OBJBDIR = objb
SRCS = $(addprefix $(SRCDIR)/, so_long.c check_map.c check_map_2.c render_map.c moves.c exit.c)
OBJS = $(patsubst $(SRCDIR)/%.c, $(OBJDIR)/%.o, $(SRCS))
SRCB = $(addprefix $(SRCBDIR)/, so_long_bonus.c check_map_bonus.c check_map_2_bonus.c \
render_map_bonus.c moves_bonus.c exit_bonus.c)
OBJB = $(patsubst $(SRCBDIR)/%.c, $(OBJBDIR)/%.o, $(SRCB))
CC = cc
RM = rm -rf
CFLAGS = -Wall -Wextra -Werror
LIBFT = ./libft
LIBFTA = $(LIBFT)/libft.a
LIBGNL = ./get_next_line
LIBGNLA = $(LIBGNL)/libgnl.a
LIBS = -L$(LIBFT) -lft -L$(LIBGNL) -lgnl
MLXFLAGS = -lmlx -framework OpenGL -framework AppKit
HEADER = $(SRCDIR)/so_long.h
HEADERB = $(SRCBDIR)/so_long_bonus.h

all: $(NAME)

$(OBJDIR)/%.o: $(SRCDIR)/%.c $(HEADER)
	mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -Imlx -c $< -o $@

$(NAME): $(OBJS) $(LIBFTA) $(LIBGNLA)
	$(CC) $(CFLAGS) $(OBJS) $(LIBS) $(MLXFLAGS) -o $(NAME)

$(LIBFTA):
	@$(MAKE) -C $(LIBFT)

$(LIBGNLA):
	@$(MAKE) -C $(LIBGNL)

bonus: $(NAMEB)

$(NAMEB): $(OBJB) $(LIBFTA) $(LIBGNLA)
	$(CC) $(CFLAGS) $(OBJB) $(LIBS) $(MLXFLAGS) -o $(NAMEB)

$(OBJBDIR)/%.o: $(SRCBDIR)/%.c $(HEADERB)
	mkdir -p $(OBJBDIR)
	$(CC) $(CFLAGS) -Imlx -c $< -o $@

clean:
	$(RM) $(OBJS) $(OBJB)
	$(RM) $(OBJDIR) $(OBJBDIR)
	@$(MAKE) -C $(LIBFT) clean
	@$(MAKE) -C $(LIBGNL) clean

fclean: clean
	$(RM) $(NAME) $(NAMEB)
	@$(MAKE) -C $(LIBFT) fclean
	@$(MAKE) -C $(LIBGNL) fclean

re: fclean all

.PHONY: all clean fclean re bonus