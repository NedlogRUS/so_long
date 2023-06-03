#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include "../libft/libft.h"
# include "../get_next_line/get_next_line.h"
# include <mlx.h>

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

typedef struct s_data
{
	void	*img;
	void	*mlx;
	void	*win;
}				t_data;

typedef struct s_sprites
{
	char	*path[17];
	void	*field;
	void	*wall;
	void	*bear;
	void	*bear2;
	void	*bearr;
	void	*bearr2;
	void	*honey;
	void	*car;
	void	*caronfire;
	void	*caronfire2;
	void	*bearincar;
	void	*win;
	void	*lose;
	void	*bee;
	void	*bee2;
	void	*beebear;
	void	*tre;
	void	*tmp;
}				t_sprites;

typedef struct s_game
{
	t_map			*map;	
	t_data			*mlx;
	t_sprites		*sprite;
	int				step_count;
	int				end_count;
	char			*step_str;
	char			symbol;

}				t_game;

int		check_rectangular_map(t_map *map);
int		check_map_walls(t_map *map);
int		check_map_components(t_map *map);
int		check_map_valid_path(t_map *map);
int		check_mvp(t_map *map);
int		mapname_validator(char *mapname);
int		ft_line_counter(char *mapname);
int		check_chr(t_map *map, char c);
int		check_map_size(t_map *map);
int		clean_out(t_game *sl);
int		key_hook(int keycode, t_game *sl);
int		animation(t_game *sl);
t_map	*new_map(unsigned int lines);
void	*file_to_image(t_game *sl, char *path);
void	*chose_img(t_game *sl, char symbol);
void	render_map(t_game *sl);
void	eror_out(t_game *game, char *eror_message);
void	read_map(t_game *game, char *mapname);
void	start_game(char *mapname);
void	check_map(t_game *sl);
void	fill(t_map *map, char **m, unsigned int x, unsigned int y);
void	moves(int i, t_game *sl);
void	print_map(t_game *sl);
void	srites_path(t_game *sl);
void	init_sprites(t_game *sl);
void	move_to(t_game *sl, unsigned int y, unsigned int x, char c);
void	end_game(t_game *sl, unsigned int y, unsigned int x);
void	swap_sprites(t_game *sl);
void	bad_end_game(t_game *sl, unsigned int y, unsigned int x);
void	move_it(t_game *sl, unsigned int y, unsigned int x, char c);

#endif