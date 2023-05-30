#include "so_long.h"

int	close_q(int keycode, t_data *mlx)
{
	printf("key_hook :%d: !\n", keycode);
	if(keycode == 53)
	{
		mlx_destroy_window(mlx->mlx, mlx->win);
        printf("Window closed from press ESC!\n");
		exit(0);	
	}
	return (0);
}

int	closewindow(void *param)
{
	t_data *mlx = (t_data *)param;
	printf("Window closed from press cross!\n");
	mlx_destroy_window(mlx->mlx, mlx->win);
	exit(0);
	return (0);
}

void render_map(t_game *sl)
{
    sl->mlx = ft_calloc(1, sizeof(t_data));
	char	*path = "./sprites/wall.xpm";
	int		img_width;
	int		img_height;
    int win_h = sl->map->columns * 100;
    int win_w = sl->map->lines * 100;

	sl->mlx->mlx = mlx_init();
	sl->mlx->img = mlx_xpm_file_to_image(sl->mlx->mlx, path, &img_width, &img_height);
	sl->mlx->win = mlx_new_window(sl->mlx->mlx, win_h, win_w, "MLX_TEST");
	mlx_put_image_to_window(sl->mlx->mlx, sl->mlx->win, sl->mlx->img, 0, 0);
	mlx_put_image_to_window(sl->mlx->mlx, sl->mlx->win, sl->mlx->img, 100, 0);
	mlx_put_image_to_window(sl->mlx->mlx, sl->mlx->win, sl->mlx->img, 0, 100);
	mlx_put_image_to_window(sl->mlx->mlx, sl->mlx->win, sl->mlx->img, 100, 100);
	mlx_hook(sl->mlx->win, 2, 1L<<0, close_q, sl->mlx);
	mlx_hook(sl->mlx->win, 17, 1L<<0, closewindow, sl->mlx);
	mlx_loop(sl->mlx->mlx);
}

	void render_map(t_game *sl)
{
	sl->mlx->win = mlx_new_window(sl->mlx->mlx, sl->map->columns * 100, sl->map->lines * 100, "MLX_TEST");

	int x, y;
	for (y = 0; y < sl->map->lines; y++)
	{
		for (x = 0; x < sl->map->columns; x++)
		{
			char symbol = sl->map->mapchars[y][x];
			void *img;

			if (symbol == '1')
				img = wall_xpm; //
			else if (symbol == '7')
				img = field_xpm; // 
			else if (symbol == 'W')
				img = bear_xpm; // 
			else if (symbol == 'J')
				img = honey_xpm; // 
			else if (symbol == 'L')
				img = car_xpm; // 
			else
				continue;

			mlx_put_image_to_window(sl->mlx->mlx, sl->mlx->win, img, x * 100, y * 100);
		}
	}

	mlx_hook(sl->mlx->win, 2, 1L<<0, close_q, sl->mlx);
	mlx_hook(sl->mlx->win, 17, 1L<<0, closewindow, sl->mlx);
	mlx_loop(sl->mlx->mlx);
}