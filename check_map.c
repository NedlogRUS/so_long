#include "so_long.h"

int	check_rectangular_map(t_map *map)
{
	unsigned int	i;
	unsigned int	columns;

	i = 0;
	columns = ft_strlen(map->mapchars[0]);
	while (i < map->lines)
		if (ft_strlen(map->mapchars[i++]) != columns)
			return (1);
	map->columns = columns;
	return (0);
}

int	check_map_walls(t_map *map)
{
	unsigned int	i;

	i = -1;
	while (map->lines > ++i)
		if (map->mapchars[i][0] != '1' || map->mapchars[i][map->columns - 1] != '1')
			return (1);
	i = -1;
	while (map->columns > ++i)
		if (map->mapchars[0][i] != '1' || map->mapchars[map->lines - 1][i] != '1')
			return (1);
	return (0);
}

int check_map_components(t_map *map)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	while (map->mapchars[i])
	{
		while (map->mapchars[i][j] && map->mapchars[i])
		{
			if (map->mapchars[i][j] == 'E')
				map->num_cars += 1;
			else if (map->mapchars[i][j] == 'P')
				map->num_bears += 1;
			else if (map->mapchars[i][j] == 'C')
				map->num_raspberry += 1;
			else if (map->mapchars[i][j] && map->mapchars[i][j] != '0' && map->mapchars[i][j] != '1')
				return (1);
			j++;
		}
		j = 0;
		i++;
	}
	if (map->num_cars != 1 || map->num_bears != 1 || map->num_raspberry < 1)
		return (1);
	return (0);
}

void fill(t_map *map, char **m, unsigned int x, unsigned int y)
{
	if (x <= 0 || x >= ft_strlen(m[y]) || y <= 0
		|| m[y] == NULL || !(m[y][x] == 'C'
		|| m[y][x] == '0' || m[y][x] == 'E'
		|| m[y][x] == 'P'))
		return ;
	m[y][x] += 7;
	if (m[y][x] == 'L')
		return ;
	fill(map, map->mapchars, x - 1, y);
	fill(map, map->mapchars, x, y - 1);
	fill(map, map->mapchars, x, y + 1);
	fill(map, map->mapchars, x + 1, y);
}

int check_mvp(t_map *map)
{
	while (map->mapchars[map->b_y])
	{
		while (map->mapchars[map->b_y][map->b_x])
		{
			if (map->mapchars[map->b_y][map->b_x] == 'P')
				break ;
			map->b_x += 1;
		}
		if (map->mapchars[map->b_y][map->b_x] == 'P')
			break ;
		map->b_x = 0;
		map->b_y +=1;
	}
	fill(map, map->mapchars, map->b_x, map->b_y);
	if (check_chr(map, 'C') != 0 || check_chr(map, 'E') != 0)
		return (1);
	return (0);
}

int	check_chr(t_map *map, char c)
{
	int	i;
	int j;

	i = 0;
	j = 0;
	while (map->mapchars[i])
	{
		while (map->mapchars[i][j])
		{
			if (map->mapchars[i][j] == c)
				return (1);
			j++;
		}
		j = 0;
		i++;
	}
	return (0);
}

void	check_map(t_game *sl)
{
	if (sl->map->lines == 0)
		eror_out(sl, "Mapfile is empty!\n");
	if (check_rectangular_map(sl->map) != 0)
		eror_out(sl, "Not rectangular map!\n");
	if (check_map_walls(sl->map) != 0)
		eror_out(sl, "Map is not surrounded by walls.\n");
	if (check_map_components(sl->map) != 0)
		eror_out(sl, "Map has wrong components.\n");
	if (check_mvp(sl->map) != 0)
		eror_out(sl, "Map is not passable.\n");
}