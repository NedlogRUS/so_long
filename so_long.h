#ifndef SO_LONG_H
# define SO_LONG_H

#include "libft/libft.h"
#include "get_next_line/get_next_line.h"
#include <stdio.h>

typedef struct s_map
{
	char			**mapchars;
	unsigned int	columns;
	unsigned int	lines;
	unsigned int	num_raspberry;
	unsigned int	num_cars;
	unsigned int	num_bears;
	unsigned int	b_y;
	unsigned int	b_x;
}				t_map;

typedef struct s_game
{
	t_map			*map;	
}				t_game;

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
int file_exists(const char *filename);



#endif