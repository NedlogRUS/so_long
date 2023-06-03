#include "so_long_bonus.h"

void	bad_end_game(t_game *sl, unsigned int y, unsigned int x)
{
	sl->end_count = 1;
	sl->map->mapchars[sl->map->b_y][sl->map->b_x] = '7';
	sl->map->mapchars[y][x] = 'Q';
	sl->map->b_y = y;
	sl->map->b_x = x;
	sl->step_count += 1;
	free (sl->step_str);
	sl->step_str = ft_itoa(sl->step_count);
	print_map(sl);
	mlx_put_image_to_window(sl->mlx->mlx, sl->mlx->win, sl->sprite->lose, 0, 0);
	mlx_string_put(sl->mlx->mlx, sl->mlx->win, 65, 50, 0xFFFFFF, "STEPS :");
	mlx_string_put(sl->mlx->mlx, sl->mlx->win, 150, 50, 0xFFFFFF, sl->step_str);
	mlx_loop(sl->mlx->mlx);
}

void	swap_sprites(t_game *sl)
{
	sl->sprite->tmp = sl->sprite->bear;
	sl->sprite->bear = sl->sprite->bear2;
	sl->sprite->bear2 = sl->sprite->tmp;
	sl->sprite->tmp = sl->sprite->bearr;
	sl->sprite->bearr = sl->sprite->bearr2;
	sl->sprite->bearr2 = sl->sprite->tmp;
	sl->sprite->tmp = sl->sprite->caronfire;
	sl->sprite->caronfire = sl->sprite->caronfire2;
	sl->sprite->caronfire2 = sl->sprite->tmp;
	sl->sprite->tmp = sl->sprite->bee;
	sl->sprite->bee = sl->sprite->bee2;
	sl->sprite->bee2 = sl->sprite->tmp;
}

int	animation(t_game *sl)
{
	static int	i;

	if (sl->end_count > 0)
		return (0);
	if (i % 2000 == 0)
		i = 0;
	if (i % 1000 == 0)
	{
		swap_sprites(sl);
		print_map(sl);
	}
	i++;
	return (0);
}

void	move_it(t_game *sl, unsigned int y, unsigned int x, char c)
{
	sl->map->mapchars[sl->map->b_y][sl->map->b_x] = '7';
	sl->map->mapchars[y][x] = c;
	sl->map->b_y = y;
	sl->map->b_x = x;
	sl->step_count += 1;
	free (sl->step_str);
	sl->step_str = ft_itoa(sl->step_count);
}
