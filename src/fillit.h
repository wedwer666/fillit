

#ifndef FILLIT_H
# define FILLIT_H
# include <libft.h>
# include <fcntl.h>

typedef struct		s_tetriminos
{
	char				name;
	short				map[4][4];
	int					width;
	int					height;
}					t_tetriminos;

typedef struct		s_info
{
	size_t			count;
	t_tetriminos	*tetriminoses;
}					t_info;

typedef struct		s_map
{
	int				size;
	char			**map;
}					t_map;

typedef struct		s_point
{
	int				x;
	int				y;
}					t_point;

t_info				*ft_info(char *name);
char				*ft_verf(char *str);
void				ft_verf2(t_info **info);
void				ft_move(t_info **info);
t_tetriminos		*ft_read(char name, int fd, int *err);
void				ft_size(t_info **info);
t_map				*createmap(size_t size);
void				deletemap(t_map **map);
void				set_piece(t_tetriminos *tetriminos, t_map *map,
								t_point *point, char c);
int					place(t_tetriminos *tetriminos, t_map *map,
							int x, int y);
t_map				*solve(t_info *info);
t_point				*createpoint(int x, int y);

#endif
