// #include <mlx.h>

// int	main(void)
// {
// 	void	*img;
// 	void	*mlx;
// 	void	*mlx_win;
// 	unsigned int x = 10;
// 	unsigned int y = 5;

// 	mlx = mlx_init();
// 	img = mlx_new_image(mlx, 50, 50);
// 	mlx_win = mlx_new_window(mlx, x * 50, y * 50, "Hello world!");
// 	mlx_loop(mlx);
// }

#include <mlx.h>
#include <stdlib.h>

typedef struct	s_data {
	void	*img;
	void	*mlx;
	void	*win;
}				t_data;

int	close(int keycode, t_data *test)
{
	if(keycode == 53)
	{
		mlx_destroy_window(test->mlx, test->win);
		exit(0);	
	}
	return (0);
}

int	main(void)
{
	t_data	test;
	char	*path = "./wall.xpm";
	int		img_width;
	int		img_height;

	test.mlx = mlx_init();
	test.img = mlx_xpm_file_to_image(test.mlx, path, &img_width, &img_height);
	test.win = mlx_new_window(test.mlx, 200, 200, "MLX_TEST");
	mlx_put_image_to_window(test.mlx, test.win, test.img, 0, 0);
	mlx_put_image_to_window(test.mlx, test.win, test.img, img_width, 0);
	mlx_put_image_to_window(test.mlx, test.win, test.img, 0, img_height);
	mlx_put_image_to_window(test.mlx, test.win, test.img, img_width, img_height);
	mlx_hook(test.win, 2, 1L<<0, close, &test);
	mlx_loop(test.mlx);
}