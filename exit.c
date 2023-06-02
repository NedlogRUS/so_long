#include "so_long.h"

int	closewindow(t_game *sl)
{
	mlx_destroy_window(sl->mlx->mlx, sl->mlx->win);
	system("leaks so_long");
	exit(0);
	return (0);
}

void eror_out(t_game *sl, char *eror_message)
{
	(void)sl;
	ft_putstr_fd(eror_message, 2);
	system("leaks so_long");
	exit(1);
}