#include "so_long.h"


void	map_print(t_map *map)
{
	unsigned int	i;
	i = 0;
	printf("Height: %u\n", map->columns);
	printf("Width: %u\n", map->lines);
	printf("Bears: %u\n", map->num_bears);
	printf("Cars: %u\n", map->num_cars);
	printf("Honey: %u\n", map->num_honey);
	while (i < map->lines)
		printf("%s\n", map->mapchars[i++]);
}

void eror_out(t_game *sl, char *eror_message)
{
	//free_game(sl);
	(void)sl;
	ft_putstr_fd(eror_message, 2);
	exit(1);
}

t_map	*new_map(unsigned int lines)
{
	t_map	*map;

	map = ft_calloc(1, sizeof(t_map));
	if (!map)
		return (NULL);
	map->mapchars = ft_calloc(lines + 1, sizeof(char *));
	if (!map->mapchars)
	{
		free(map);
		return (NULL);
	}
	map->lines = lines;
	return (map);
}

int	ft_line_counter(char *mapname)
{
	int		fd;
	int		line_counter;
	char	*tmp;

	line_counter = 0;
	fd = open(mapname, O_RDONLY);
	if (fd < 0)
		return(1);
	while (1)
	{
		tmp = get_next_line(fd);
		if (!tmp)
			break ;
		line_counter++;
		free(tmp);
	}
	close(fd);
	return (line_counter);
}

void	read_map(t_game *game, char *mapname)
{
	int				fd;
	char			*tmp;
	unsigned int	i;

	i = 0;
	game->map = new_map(ft_line_counter(mapname));
	if (!game->map)
		return;
	fd = open(mapname, O_RDONLY);
	if (fd < 0)
		return;
	while (i < game->map->lines)
	{
		tmp = get_next_line(fd);
		if (!tmp)
			return;
		game->map->mapchars[i] = ft_strtrim(tmp, "\n");
		if (!game->map->mapchars[i++])
			return;
		free(tmp);
	}
	close(fd);
}

void	start_game(char *mapname)
{
	t_game	sl;

	ft_bzero(&sl, sizeof(t_game));
	read_map(&sl, mapname);
	check_map(&sl);
	map_print(sl.map);
	sl.step_count = 0;
	srites_path(&sl);
	render_map(&sl);
	mlx_hook(sl.mlx->win, 2, 1L<<0, key_hook, &sl);
	mlx_hook(sl.mlx->win, 17, 1L<<0, closewindow, sl.mlx);
	mlx_loop(sl.mlx->mlx);
}

int	mapname_validator(char *mapname)
{
	size_t	len;

	len = ft_strlen(mapname);
	if (len < 4)
		return (0);
	return (ft_strnstr(mapname + (len - 4), ".ber", 4) != NULL);
}


int	main(int argc, char **argv)
{	
	if (argc != 2)
		eror_out(NULL, "Incorrect size of argument!\n");
	if (!mapname_validator(argv[1]) || mapname_validator(argv[1]) == 0)
    	eror_out(NULL, "name of mapfile must end in .ber !\n"); 
	if(read(open(argv[1], O_RDONLY), 0, 0) < 0)
        eror_out(NULL, "File does not exist!\n");	
	start_game(argv[1]);
    return(0);
}
