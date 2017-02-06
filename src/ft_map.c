

#include "fillit.h"

t_map				*createmap(size_t size)
{
	t_map	*rs;
	size_t	i;
	size_t	j;

	rs = malloc(sizeof(t_map));
	if (rs)
	{
		rs->size = size;
		rs->map = malloc(sizeof(char*) * size);
		if (rs->map)
		{
			i = 0;
			while (i < size)
			{
				rs->map[i] = malloc(size);
				j = 0;
				while (j < size)
				{
					rs->map[i][j++] = '.';
				}
				i++;
			}
		}
	}
	return (rs);
}

void				deletemap(t_map **map)
{
	int	i;

	i = 0;
	while (i < (*map)->size)
	{
		free((*map)->map[i]);
		i++;
	}
	free((*map)->map);
	free(*map);
	*map = NULL;
}

int					place(t_tetriminos *tetriminos, t_map *map, int x, int y)
{
	int i;
	int j;

	i = 0;
	while (i < tetriminos->width)
	{
		j = 0;
		while (j < tetriminos->height)
		{
			if (tetriminos->map[j][i] == 1 && map->map[y + j][x + i] != '.')
				return (0);
			j++;
		}
		i++;
	}
	set_piece(tetriminos, map, createpoint(x, y), tetriminos->name);
	return (1);
}

void				set_piece(t_tetriminos *tetriminos, t_map *map,
		t_point *point, char c)
{
	int i;
	int j;

	i = 0;
	while (i < tetriminos->width)
	{
		j = 0;
		while (j < tetriminos->height)
		{
			if (tetriminos->map[j][i] == 1)
				map->map[point->y + j][point->x + i] = c;
			j++;
		}
		i++;
	}
	free(point);
}

t_point				*createpoint(int x, int y)
{
	t_point	*point;

	point = malloc(sizeof(t_point));
	point->x = x;
	point->y = y;
	return (point);
}
