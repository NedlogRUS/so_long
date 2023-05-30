#include "so_long.h"

int	close_q(int keycode, t_data *mlx)
{
	if(keycode == 53)
	{
		mlx_destroy_window(mlx->mlx, mlx->win);
        printf("Window closed from press ESC!\n"); // DONT FORGET FREE
		exit(0);	
	}
	return (0);
}

int	closewindow(void *param)
{
	t_data *mlx = (t_data *)param;
	printf("Window closed from press cross!\n"); // DONT FORGET FREE
	mlx_destroy_window(mlx->mlx, mlx->win);
	exit(0);
	return (0);
}

int	key_hook(int keycode, t_game *sl)
{
	printf("key_hook :%d: !\n", keycode);
	if(keycode == 123)
		moves(123, sl);
	if(keycode == 124)
		moves(124, sl);
	if(keycode == 125)
		moves(125, sl);
	if(keycode == 126)
		moves(126, sl);
	return (0);
}

void print_map(t_game *sl)
{
	unsigned int x, y;
	for (y = 0; y < sl->map->lines; y++)
	{
		for (x = 0; x < sl->map->columns; x++)
		{
			char symbol = sl->map->mapchars[y][x];
			void *img;
			char	*pathfield = "./sprites/field.xpm";
			char	*pathwall = "./sprites/wall.xpm";
			char	*pathbear = "./sprites/bear.xpm";
			char	*pathbearr = "./sprites/bearr.xpm";
			char	*pathhoney = "./sprites/honey.xpm";
			char	*pathcar = "./sprites/car.xpm";
			char	*pathcaronfire = "./sprites/caronfire.xpm";
			int		img_width;
			int		img_height;

			if (symbol == '1')
				img = mlx_xpm_file_to_image(sl->mlx->mlx, pathwall, &img_width, &img_height);
			else if (symbol == '7' || symbol == '0')
				img = mlx_xpm_file_to_image(sl->mlx->mlx, pathfield, &img_width, &img_height); 
			else if (symbol == 'W')
				img = mlx_xpm_file_to_image(sl->mlx->mlx, pathbear, &img_width, &img_height); 
			else if (symbol == 'P')
				img = mlx_xpm_file_to_image(sl->mlx->mlx, pathbearr, &img_width, &img_height); 
			else if (symbol == 'J')
				img = mlx_xpm_file_to_image(sl->mlx->mlx, pathhoney, &img_width, &img_height); 
			else if (symbol == 'L' && sl->map->num_honey > 0)
				img = mlx_xpm_file_to_image(sl->mlx->mlx, pathcar, &img_width, &img_height); 
			else if (symbol == 'L' && sl->map->num_honey == 0)
				img = mlx_xpm_file_to_image(sl->mlx->mlx, pathcaronfire, &img_width, &img_height); 
			else
				continue;
			mlx_put_image_to_window(sl->mlx->mlx, sl->mlx->win, img, x * 100, y * 100);
		}
	}
}

	void render_map(t_game *sl)
{
	sl->mlx = ft_calloc(1, sizeof(t_data));
	sl->mlx->mlx = mlx_init();
	sl->mlx->win = mlx_new_window(sl->mlx->mlx, sl->map->columns * 100, sl->map->lines * 100, "MLX_TEST");
	print_map(sl);
	mlx_hook(sl->mlx->win, 2, 1L<<0, close_q, sl->mlx);
	mlx_hook(sl->mlx->win, 17, 1L<<0, closewindow, sl->mlx);
	mlx_key_hook(sl->mlx->win, key_hook, sl);
	mlx_loop(sl->mlx->mlx);
}