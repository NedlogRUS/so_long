#ifndef SO_LONG_H
# define SO_LONG_H

#include "libft/libft.h"
#include "get_next_line/get_next_line.h"
#include <mlx.h> //FOR_MAC
#include <stdio.h>
// #include "./mlx-linux/mlx.h" //FOR_LINUX


typedef struct s_map
{
	char			**mapchars;
	unsigned int	columns;
	unsigned int	lines;
	unsigned int	num_honey;
	unsigned int	num_cars;
	unsigned int	num_bears;
	unsigned int	b_y;
	unsigned int	b_x;
}				t_map;

typedef struct	s_data {
	void	*img;
	void	*mlx;
	void	*win;
}				t_data;

typedef struct s_game
{
	t_map			*map;	
	t_data			*mlx;
	unsigned int	step_count;
}				t_game;

void render_map(t_game *sl);
void	map_print(t_map *map);
void eror_out(t_game *game, char *eror_message);
t_map	*new_map(unsigned int lines);
int	ft_line_counter(char *mapname);
void	read_map(t_game *game, char *mapname);
void	start_game(char *mapname);
int	mapname_validator(char *mapname);
void	check_map(t_game *sl);
int	check_rectangular_map(t_map *map);
int	check_map_walls(t_map *map);
int check_map_components(t_map *map);
int check_map_valid_path(t_map *map);
int check_mvp(t_map *map);
void fill(t_map *map, char **m, unsigned int x, unsigned int y);
int	check_chr(t_map *map, char c);
int check_map_size(t_map *map);
void moves(int i, t_game *sl);
void move_right(t_game *sl);
void print_map(t_game *sl);

#endif