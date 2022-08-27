#ifndef CUB3D_H
# define CUB3D_H
# include <math.h>
# include <mlx.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct s_gnl {
	char	c;
	char	*str;
	int		read_return;
	char	*temp;
}				t_gnl;

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct	s_vars {
	void	*mlx;
	void	*win;
	float	x1;
	float	y1;
	float	x2;
	float	y2;
	float	x3;
	float	y3;
	float	pdx;
	float	pdy;
	int		angle;
	char	**map;
	int		lines;
	t_data	img;
}				t_vars;

typedef struct s_point {
	float x;
	float y;
}	t_point;

void	DrawCircle(int r, t_vars *vars);
void	dda(t_data *img, t_point a, t_point b);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
int		keys_hook(int key, t_vars *vars);
void	new_win(t_vars *vars, int height, int fd);
void	ft_line_counter(int	*count, char *s, t_vars *vars);
void	DrawSquare(t_vars *vars, int x, int y, int color);
void	ft_putstr(char *str);
char	*get_next_line(int fd);
size_t	ft_strlen(char *str);

#endif