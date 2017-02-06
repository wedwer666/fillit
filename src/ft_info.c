
#include "fillit.h"

int	g_i;

void	copy(t_info **info, t_tetriminos *tetriminos)
{
	t_tetriminos	*tmp;

	tmp = (*info)->tetriminoses;
	(*info)->tetriminoses = ft_memalloc(sizeof(t_tetriminos) *
			((*info)->count + 1));
	if ((*info)->tetriminoses)
	{
		ft_memcpy((*info)->tetriminoses, tmp,
				sizeof(t_tetriminos) * (*info)->count);
		ft_memcpy((*info)->tetriminoses + (*info)->count, tetriminos,
				sizeof(t_tetriminos));
		(*info)->count++;
	}
	free(tmp);
}

void	add_tetriminos(t_info **info, t_tetriminos *tetriminos)
{
	if (*info)
	{
		copy(info, tetriminos);
	}
	else
	{
		*info = ft_memalloc(sizeof(t_info));
		if (*info)
		{
			(*info)->tetriminoses = ft_memalloc(sizeof(t_tetriminos));
			if ((*info)->tetriminoses)
			{
				(*info)->count = 1;
				ft_memcpy((*info)->tetriminoses, tetriminos,
						sizeof(t_tetriminos));
			}
		}
	}
}

t_info	*on_return(t_info **rs, int fd, int err)
{
	close(fd);
	if (err)
	{
		ft_memdel((void**)rs);
		return (NULL);
	}
	else
	{
		ft_verf2(rs);
		if (*rs)
			ft_size(rs);
	}
	return (*rs);
}

void	execute(t_info **rs, t_tetriminos *tetriminos, int fd, char **str)
{
	add_tetriminos(rs, tetriminos);
	*str = ft_getline(fd);
}

t_info	*ft_info(char *name)
{
	int				fd;
	int				err;
	t_tetriminos	*tetriminos;
	char			*str;
	t_info			*rs;

	fd = open(name, O_RDONLY);
	if (fd <= 0)
		return (NULL);
	g_i = 0;
	err = 0;
	rs = NULL;
	while ((tetriminos = ft_read('A' + g_i, fd, &err)))
	{
		if (err)
			return (on_return(&rs, fd, err));
		execute(&rs, tetriminos, fd, &str);
		if (!str)
			return (on_return(&rs, fd, err));
		if (strncmp(str, "\n\0", 2))
			return (on_return(&rs, fd, 1));
		g_i++;
		free(tetriminos);
	}
	return (on_return(&rs, fd, 1));
}
