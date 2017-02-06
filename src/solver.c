

#include "fillit.h"

static int		solve_map(t_map *map, t_info *info, size_t i)
{
	int					x;
	int					y;
	t_tetriminos		*tetri;

	if (i >= info->count)
		return (1);
	y = 0;
	tetri = info->tetriminoses + i;
	while (y < map->size - tetri->height + 1)
	{
		x = 0;
		while (x < map->size - tetri->width + 1)
		{
			if (place(tetri, map, x, y))
			{
				if (solve_map(map, info, i + 1))
					return (1);
				else
					set_piece(tetri, map, createpoint(x, y), '.');
			}
			x++;
		}
		y++;
	}
	return (0);
}

static int		high_sqrt(int n)
{
	int size;

	size = 2;
	while (size * size < n)
		size++;
	return (size);
}

t_map			*solve(t_info *info)
{
	t_map	*map;
	int		size;

	size = high_sqrt(info->count * 4);
	map = createmap(size);
	while (!solve_map(map, info, 0))
	{
		size++;
		deletemap(&map);
		map = createmap(size);
	}
	return (map);
}
