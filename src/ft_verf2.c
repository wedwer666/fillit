

#include "fillit.h"

static int				sum_arr(t_tetriminos *tetriminos)
{
	int		rs;
	size_t	i;
	size_t	j;

	i = 0;
	rs = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			rs += tetriminos->map[i][j++];
		}
		i++;
	}
	return (rs);
}

static void				cond(int i, int j, int *b, t_tetriminos *tetriminos)
{
	if (i < 3 && tetriminos->map[i + 1][j])
		(*b)++;
	if (i > 0 && tetriminos->map[i - 1][j])
		(*b)++;
	if (j < 3 && tetriminos->map[i][j + 1])
		(*b)++;
	if (j > 0 && tetriminos->map[i][j - 1])
		(*b)++;
}

static int				connection(t_tetriminos *tetriminos)
{
	int		i;
	int		j;
	int		b;

	i = 0;
	b = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (tetriminos->map[i][j] == 1)
			{
				cond(i, j, &b, tetriminos);
			}
			j++;
		}
		i++;
	}
	return (b == 6 || b == 8);
}

void					ft_verf2(t_info **info)
{
	size_t	i;
	int		b;

	b = 0;
	i = 0;
	while (i < (*info)->count && !b)
	{
		if (sum_arr((*info)->tetriminoses + i) != 4)
			b = 1;
		if (!connection((*info)->tetriminoses + i))
			b = 1;
		i++;
	}
	if (b)
		ft_memdel((void**)info);
	else
		ft_move(info);
}
