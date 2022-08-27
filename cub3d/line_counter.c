/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_counter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ie-laabb <ie-laabb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 19:40:27 by ie-laabb          #+#    #+#             */
/*   Updated: 2022/07/28 17:19:02 by ie-laabb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_strcmp(char *str)
{
	char	*s1;
	char	*s2;
	int		i;

	s1 = &str[ft_strlen(str) - 4];
	s2 = ".ber";
	i = 0;
	while (s1[i])
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (0);
}

void	map_maker(t_vars *vars, char *str, int i, int j)
{
	int	k;

	k = 0;
	while (str[k])
	{
		if (str[k] == '1')
			DrawSquare(vars, i, j, 0xAB16C3);
		else if (str[k] == '0')
			DrawSquare(vars, i, j, 0xFFFFFF);
		k++;
		i += 50;
	}
}

void	ft_line_counter(int	*count, char *s, t_vars *vars)
{
	int		i, j;
	char	*str;
	int		fd;

	i = 0, j = 0;
	fd = open(s, O_RDONLY);
	if (fd < 0)
	{
		ft_putstr("Error\nmap name is unacceptable\n");
		exit(1);
	}
	str = get_next_line(fd);
	count[1] = ft_strlen(str);
	while (str)
	{
		map_maker(vars, str, i, j);
		j += 50;
		i = 0;
		free (str);
		str = get_next_line(fd);
	}
	count[0] = i;
}
