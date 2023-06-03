#include "so_long_bonus.h"

void	move_to(t_game *sl, unsigned int y, unsigned int x, char c)
{
	while (1)
	{
		if (sl->map->mapchars[y][x] == 'B')
			bad_end_game(sl, y, x);
		if (sl->map->mapchars[y][x] == '1')
			return ;
		if (sl->map->mapchars[y][x] == '7')
			break ;
		if (sl->map->mapchars[y][x] == 'J')
		{
			sl->map->num_honey -= 1;
			break ;
		}
		if (sl->map->mapchars[y][x] == 'L' && sl->map->num_honey == 0)
			end_game(sl, y, x);
		else
			return ;
	}
	move_it(sl, y, x, c);
	return ;
}

void	moves(int i, t_game *sl)
{
	if (sl->end_count > 0)
		return ;
	if (i == 124 || i == 2)
		move_to(sl, sl->map->b_y, sl->map->b_x + 1, 'P');
	if (i == 123 || i == 0)
		move_to(sl, sl->map->b_y, sl->map->b_x - 1, 'W');
	if (i == 126 || i == 13)
		move_to(sl, sl->map->b_y - 1, sl->map->b_x, 'P');
	if (i == 125 || i == 1)
		move_to(sl, sl->map->b_y + 1, sl->map->b_x, 'W');
}

int	key_hook(int keycode, t_game *sl)
{
	if (keycode == 53)
	{
		clean_out(sl);
	}
	if (keycode == 0 || keycode == 13 || keycode == 2 || keycode == 1)
		moves(keycode, sl);
	else if (keycode == 123 || keycode == 126 || \
	keycode == 124 || keycode == 125)
		moves(keycode, sl);
	return (0);
}

void	srites_path(t_game *sl)
{
	sl->sprite = ft_calloc(1, sizeof(t_sprites));
	if (!sl->sprite)
		eror_out(sl, "Allocation sprite failed!\n");
	sl->sprite->path[0] = "./sprites/field.xpm";
	sl->sprite->path[1] = "./sprites/wall.xpm";
	sl->sprite->path[2] = "./sprites/bear.xpm";
	sl->sprite->path[3] = "./sprites/bearr.xpm";
	sl->sprite->path[4] = "./sprites/honey.xpm";
	sl->sprite->path[5] = "./sprites/car.xpm";
	sl->sprite->path[6] = "./sprites/caronfire.xpm";
	sl->sprite->path[7] = "./sprites/bearincar.xpm";
	sl->sprite->path[8] = "./sprites/win.xpm";
	sl->sprite->path[9] = "./sprites/bear2.xpm";
	sl->sprite->path[10] = "./sprites/bearr2.xpm";
	sl->sprite->path[11] = "./sprites/caronfire2.xpm";
	sl->sprite->path[12] = "./sprites/bee.xpm";
	sl->sprite->path[13] = "./sprites/bee2.xpm";
	sl->sprite->path[14] = "./sprites/beebear.xpm";
	sl->sprite->path[15] = "./sprites/lose.xpm";
	sl->sprite->path[16] = "./sprites/lose.xpm";
}

int	mapname_validator(char *mapname)
{
	size_t	len;

	len = ft_strlen(mapname);
	if (len < 4)
		return (0);
	return (ft_strnstr(mapname + (len - 4), ".ber", 4) != NULL);
}
