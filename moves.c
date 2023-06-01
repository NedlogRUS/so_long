#include "so_long.h"

void	move_to(t_game *sl, unsigned int y, unsigned int x, char c)
{
	while (1)
	{
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
			end_game(sl);
		else
			return ;
	}
	sl->map->mapchars[sl->map->b_y][sl->map->b_x] = '7';
	sl->map->mapchars[y][x] = c;
	sl->map->b_y = y;
	sl->map->b_x = x;
	sl->step_count += 1;
	print_map(sl);
	return ;
}

void	moves(int i, t_game *sl)
{
	if (i == 124 || i == 2)
		move_to(sl, sl->map->b_y, sl->map->b_x + 1, 'P');
	if (i == 123 || i == 0)
		move_to(sl, sl->map->b_y, sl->map->b_x - 1, 'W');
	if (i == 126 || i == 13)
		move_to(sl, sl->map->b_y - 1, sl->map->b_x, 'P');
	if (i == 125 || i == 1)
		move_to(sl, sl->map->b_y + 1, sl->map->b_x, 'W');
}
