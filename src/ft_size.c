

#include "fillit.h"

static int				has_line(t_tetriminos *tetriminos, int i)
{
	int j;

	j = 0;
	while (j < 4)
	{
		if (tetriminos->map[i][j] == 1)
			return (1);
		j++;
	}
	return (0);
}

static int				has_row(t_tetriminos *tetriminos, int j)
{
	int i;

	i = 0;
	while (i < 4)
	{
		if (tetriminos->map[i][j] == 1)
			return (1);
		i++;
	}
	return (0);
}

static void				get_width(t_tetriminos *tetriminos)
{
	int i;

	i = 0;
	while (has_row(tetriminos, i) && i < 4)
	{
		i++;
	}
	tetriminos->width = i;
}

static void				get_height(t_tetriminos *tetriminos)
{
	int i;

	i = 0;
	while (has_line(tetriminos, i) && i < 4)
	{
		i++;
	}
	tetriminos->height = i;
}

void					ft_size(t_info **info)
{
	size_t i;

	i = 0;
	while (i < (*info)->count)
	{
		get_width((*info)->tetriminoses + i);
		get_height((*info)->tetriminoses + i);
		i++;
	}
}
