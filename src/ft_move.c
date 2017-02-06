

#include "fillit.h"

static int			forf(t_tetriminos *t)
{
	int		i;
	int		j;
	int		x;

	x = -1;
	i = 0;
	while (i < 4 && x < 0)
	{
		j = 0;
		while (j < 4 && x < 0)
		{
			if (t->map[i][j] == 1)
			{
				x = i;
			}
			j++;
		}
		i++;
	}
	return (x);
}

static int			forf2(t_tetriminos *t)
{
	int i;
	int j;
	int x;

	x = -1;
	j = 0;
	while (j < 4 && x < 0)
	{
		i = 0;
		while (i < 4 && x < 0)
		{
			if (t->map[i][j] == 1)
			{
				x = j;
			}
			i++;
		}
		j++;
	}
	return (x);
}

static void			fori(t_tetriminos *t)
{
	size_t	i;
	size_t	j;
	int		b;

	b = forf(t);
	if (b)
	{
		i = b;
		while (i < 4)
		{
			j = 0;
			while (j < 4)
			{
				t->map[i - b][j] = t->map[i][j];
				t->map[i][j] = 0;
				j++;
			}
			i++;
		}
	}
}

static void			forj(t_tetriminos *t)
{
	size_t	i;
	size_t	j;
	int		b;

	b = forf2(t);
	if (b)
	{
		i = b;
		while (i < 4)
		{
			j = 0;
			while (j < 4)
			{
				t->map[j][i - b] = t->map[j][i];
				t->map[j][i] = 0;
				j++;
			}
			i++;
		}
	}
}

void				ft_move(t_info **info)
{
	size_t	i;

	i = 0;
	while (i < (*info)->count)
	{
		fori((*info)->tetriminoses + i);
		forj((*info)->tetriminoses + i);
		i++;
	}
}
