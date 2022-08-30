/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_counter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ie-laabb <ie-laabb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 19:40:27 by ie-laabb          #+#    #+#             */
/*   Updated: 2022/08/30 12:43:14 by ie-laabb         ###   ########.fr       */
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
			DrawSquare(vars, i, j, 0x8E8E8E);
		else if (str[k] == '0')
			DrawSquare(vars, i, j, 0x000000);
		k++;
		i += 50;
	}
}

void	ft_line_counter(t_vars *vars)
{
	int		i, j;
	char	*str;

	vars->mapa.fd = open(vars->mapa.av, O_RDONLY);
	i = 0, j = 0;
	if (vars->mapa.fd < 0)
	{
		ft_putstr("Error\nmap name is unacceptable\n");
		exit(1);
	}
	str = get_next_line(vars->mapa.fd);
	if (str)
		vars->mapa.i[1] = ft_strlen(str);
	else
	{
		printf("Error 404\n");
		exit(1);
	}
	while (str)
	{
		map_maker(vars, str, i, j);
		j += 50;
		i = 0;
		free (str);
		str = get_next_line(vars->mapa.fd);
	}
	vars->mapa.i[0] = i;
}

void	Show_Map(t_vars *vars)
{
	ft_line_counter(vars);
	// new_win(vars,vars->mapa.i[0], vars->mapa.fd);
	// map_maker(vars, )
}
