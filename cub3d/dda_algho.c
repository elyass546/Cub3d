#include "cub3d.h"

void	dda(t_data *img, t_point a, t_point b)
{
	float	xinc;
	float	yinc;
	int		steps;
	int		dx;
	int		dy;
	int		i = 1;

	dx = b.x - a.x;
	dy = b.y - a.y;
	if (abs(dx) > abs(dy))
		steps = abs(dx);
	else
		steps = abs(dy);
	xinc = dx / (float) steps;
	yinc = dy / (float) steps;
	while (i < steps)
	{
		my_mlx_pixel_put(img, a.x, a.y, 0xFF00FF);
		a.x += xinc;
		a.y += yinc;
		i++;
	}
}
