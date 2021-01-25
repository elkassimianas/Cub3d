/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stock_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-kass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/31 15:14:44 by ael-kass          #+#    #+#             */
/*   Updated: 2021/01/25 11:52:28 by ael-kass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int			resolution(int b)
{
	char	**line;

	line = ft_split(g_p.ln, ' ');
	ft_strlen(line[0]) != 1 ? ft_print_errors(2) : 1;
	if (g_str[0] == '1')
		ft_print_errors(15);
	else
		g_str[0] = '1';
	nu_information(line) != 3 ? ft_print_errors(1) : 3;
	g_ray.win_w = ft_atoi(line[1]);
	g_ray.win_w == -1 ? ft_print_errors(1) : g_ray.win_w;
	g_ray.win_w = g_ray.win_w > WIN_WMAX ? WIN_WMAX : g_ray.win_w;
	g_ray.win_h = ft_atoi(line[2]);
	g_ray.win_h == -1 ? ft_print_errors(1) : g_ray.win_h;
	g_ray.win_h = g_ray.win_h > WIN_HMAX ? WIN_HMAX : g_ray.win_h;
	return (b + 1);
}

void		ft_floor(char **line)
{
	int		i;
	int		a;

	nu_information(line) != 2 ? ft_print_errors(12) : 2;
	i = -1;
	a = 0;
	while (line[1][++i] != '\0')
	{
		if (line[1][i] == ',')
		{
			if (line[1][i + 1] == ',')
				ft_print_errors(13);
			a++;
		}
		a != 2 && line[1][i + 1] == '\0' ? ft_print_errors(13) : a;
	}
	line = ft_split(line[1], ',');
	nu_information(line) != 3 ? ft_print_errors(12) : 2;
	g_tex.rf = ft_atoi(line[0]);
	g_tex.rf == -1 || g_tex.rf > 255 ? ft_print_errors(12) : g_tex.rf;
	g_tex.gf = ft_atoi(line[1]);
	g_tex.gf == -1 || g_tex.gf > 255 ? ft_print_errors(12) : g_tex.gf;
	g_tex.bf = ft_atoi(line[2]);
	g_tex.bf == -1 || g_tex.bf > 255 ? ft_print_errors(12) : g_tex.bf;
}

void		ft_ceilling(char **line)
{
	int		i;
	int		a;

	nu_information(line) != 2 ? ft_print_errors(14) : 2;
	i = -1;
	a = 0;
	while (line[1][++i] != '\0')
	{
		if (line[1][i] == ',')
		{
			if (line[1][i + 1] == ',')
				ft_print_errors(13);
			a++;
		}
		a != 2 && line[1][i + 1] == '\0' ? ft_print_errors(13) : a;
	}
	line = ft_split(line[1], ',');
	nu_information(line) != 3 ? ft_print_errors(14) : 2;
	g_tex.rc = ft_atoi(line[0]);
	g_tex.rc == -1 || g_tex.rc > 255 ? ft_print_errors(14) : g_tex.rc;
	g_tex.gc = ft_atoi(line[1]);
	g_tex.gc == -1 || g_tex.gc > 255 ? ft_print_errors(14) : g_tex.gc;
	g_tex.bc = ft_atoi(line[2]);
	g_tex.bc == -1 || g_tex.bc > 255 ? ft_print_errors(14) : g_tex.bc;
}

void		no_so_we_ea_s(int dx1, int dx2)
{
	char	**line;

	line = ft_split(g_p.ln, ' ');
	if (dx1 == 1)
	{
		if (!mlx_xpm_file_to_image(g_data.mlx, line[1], &g_tex.width,
					&g_tex.height) || nu_information(line) != 2)
		{
			dx2 == 1 ? ft_print_errors(3) : dx2;
			dx2 == 2 ? ft_print_errors(4) : dx2;
			dx2 == 3 ? ft_print_errors(9) : dx2;
			dx2 == 4 ? ft_print_errors(10) : dx2;
			dx2 == 5 ? ft_print_errors(11) : dx2;
		}
		else
		{
			g_tex.filenameup = dx2 == 1 ? line[1] : g_tex.filenameup;
			g_tex.filenamedown = dx2 == 2 ? line[1] : g_tex.filenamedown;
			g_tex.filenameleft = dx2 == 3 ? line[1] : g_tex.filenameleft;
			g_tex.filenameright = dx2 == 4 ? line[1] : g_tex.filenameright;
			g_tex.filesprite = dx2 == 5 ? line[1] : g_tex.filesprite;
		}
	}
}

size_t		nu_information(char **line)
{
	size_t		i;

	i = 0;
	while (line[i] != 0)
		i++;
	return (i);
}