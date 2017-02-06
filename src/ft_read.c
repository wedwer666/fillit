

#include "fillit.h"

static short			ft_get(char c)
{
	if (c == '#')
		return (1);
	else
		return (0);
}

static void				ft_insert(t_tetriminos *t, char *str, int i)
{
	size_t	j;

	j = 0;
	while (j < 4)
	{
		t->map[i][j] = ft_get(str[j]);
		j++;
	}
}

static t_tetriminos		*is_error(int i, char *str, int *err,
									t_tetriminos **tetriminos)
{
	if (i == 0)
		if (str)
			*err = 1;
		else
			*err = 0;
	else
		*err = 1;
	ft_memdel((void**)tetriminos);
	return (NULL);
}

t_tetriminos			*ft_read(char name, int fd, int *err)
{
	t_tetriminos	*rs;
	size_t			i;
	char			*buff;
	char			*str;

	rs = ft_memalloc(sizeof(t_tetriminos));
	if (rs)
	{
		rs->name = name;
		i = 0;
		while (i < 4)
		{
			str = ft_getline(fd);
			buff = ft_verf(str);
			if (buff)
			{
				ft_insert(rs, buff, i++);
			}
			else
			{
				return (is_error(i, str, err, &rs));
			}
		}
	}
	return (rs);
}
