#include "so_long.h"

int	key_hook(int keycode, t_game *sl) //HOOK FOR MAC
{
	if(keycode == 53)
	{
		mlx_destroy_window(sl->mlx->mlx, sl->mlx->win);
        printf("Window closed from press ESC!\n"); // DONT FORGET FREE
		exit(0);	
	}
	if(keycode == 0 || keycode == 13 || keycode == 2 || keycode == 1)
		moves(keycode, sl);
	else if(keycode == 123 || keycode == 126 || keycode == 124 || keycode == 125)
		moves(keycode, sl);
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

// int	key_hook(int keycode, t_game *sl) //HOOK FOR LINUX
// {
// 	if(keycode == 53)
// 	{
// 		mlx_destroy_window(sl->mlx->mlx, sl->mlx->win);
//         printf("Window closed from press ESC!\n"); // DONT FORGET FREE
// 		exit(0);	
// 	}
// 	if(keycode == 65361)
// 		moves(123, sl);
// 	if(keycode == 65363)
// 		moves(124, sl);
// 	if(keycode == 65364)
// 		moves(125, sl);
// 	if(keycode == 65362)
// 		moves(126, sl);
// 	return (0);
// }

void srites_path(t_game *sl)
{
	sl->sprite = ft_calloc(1, sizeof(t_sprites));
	sl->sprite->path[0] = "./sprites/field.xpm";
	sl->sprite->path[1] = "./sprites/wall.xpm";
	sl->sprite->path[2] = "./sprites/bear.xpm";
	sl->sprite->path[3] = "./sprites/bearr.xpm";
	sl->sprite->path[4] = "./sprites/honey.xpm";
	sl->sprite->path[5] = "./sprites/car.xpm";
	sl->sprite->path[6] = "./sprites/caronfire.xpm";
	// sl->sprite->path[7] = "./sprites/caronfireb.xpm";
}

void init_sprites(t_game *sl)
{
	sl->sprite->field = file_to_image(sl, sl->sprite->path[0]);
	sl->sprite->wall = file_to_image(sl, sl->sprite->path[1]);
	sl->sprite->bear = file_to_image(sl, sl->sprite->path[2]);
	sl->sprite->bearr = file_to_image(sl, sl->sprite->path[3]);
	sl->sprite->honey = file_to_image(sl, sl->sprite->path[4]);
	sl->sprite->car = file_to_image(sl, sl->sprite->path[5]);
	sl->sprite->caronfire = file_to_image(sl, sl->sprite->path[6]);
}

void	*file_to_image(t_game *sl, char *path)
{
	void	*img;
    int		img_width;
	int		img_height;

	img = mlx_xpm_file_to_image(sl->mlx->mlx, path, &img_width, &img_height);
	if (!img)
		eror_out(sl, "Image init failed!\n");
	return (img);
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

			if (symbol == '1')
				img = sl->sprite->wall;
			else if (symbol == '7' || symbol == '0')
				img = sl->sprite->field; 
			else if (symbol == 'W')
				img = sl->sprite->bear; 
			else if (symbol == 'P')
				img = sl->sprite->bearr; 
			else if (symbol == 'J')
				img = sl->sprite->honey; 
			else if (symbol == 'L' && sl->map->num_honey > 0)
				img = sl->sprite->car; 
			else if (symbol == 'L' && sl->map->num_honey == 0)
				img = sl->sprite->caronfire; 
			else
				continue;
			mlx_put_image_to_window(sl->mlx->mlx, sl->mlx->win, img, x * 100, y * 100);
		}
	}
}


void end_game(t_game *sl)
{
    char	*pathcaronfire = "./sprites/caronfire.xpm";
    void *img;
    int		img_width;
	int		img_height;

    mlx_destroy_window(sl->mlx->mlx, sl->mlx->win);
    free(sl->mlx);
    	sl->mlx = ft_calloc(1, sizeof(t_data));
	sl->mlx->mlx = mlx_init();
	if(!sl->mlx->mlx)
		eror_out(sl, "mlx_init failed!\n");
	sl->mlx->win = mlx_new_window(sl->mlx->mlx, 100, 100, "END_GAME_TEST");
    img = mlx_xpm_file_to_image(sl->mlx->mlx, pathcaronfire, &img_width, &img_height); 
    mlx_put_image_to_window(sl->mlx->mlx, sl->mlx->win, img, 0, 0);
	mlx_hook(sl->mlx->win, 2, 1L<<0, key_hook, sl);
	mlx_hook(sl->mlx->win, 17, 1L<<0, closewindow, sl->mlx);
	mlx_loop(sl->mlx->mlx);
}

	void render_map(t_game *sl)
{
	sl->mlx = ft_calloc(1, sizeof(t_data));
	sl->mlx->mlx = mlx_init();
	if(!sl->mlx->mlx)
		eror_out(sl, "mlx_init failed!\n");
	sl->mlx->win = mlx_new_window(sl->mlx->mlx, sl->map->columns * 100, sl->map->lines * 100, "MLX_TEST");
	init_sprites(sl);
	print_map(sl);
}