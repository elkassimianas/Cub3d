/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-kass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 13:21:08 by ael-kass          #+#    #+#             */
/*   Updated: 2020/12/05 16:27:21 by ael-kass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	    Map[11][15] = {{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
                   	   {1,0,0,0,0,0,0,0,0,0,0,0,1,0,1},
                   	   {1,0,0,1,0,1,0,0,0,1,0,0,1,0,1},
                   	   {1,1,1,1,1,0,0,0,0,0,1,0,1,0,1},
                   	   {1,0,0,0,0,0,0,0,0,0,1,0,1,0,1},
                   	   {1,0,0,0,1,0,0,0,0,0,0,0,0,0,1},
                   	   {1,0,0,1,1,1,1,1,1,1,1,1,0,0,1},
            	   	   {1,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
                   	   {1,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
                   	   {1,0,0,0,0,0,0,1,0,0,0,0,0,0,1},
                   	   {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}};


void		drawing_cub_walls(t_data *data)
{
	int		x;
	int		y;

	x = (TILE_SIZE * MINIMAP_SCALE_FACTOR) + g_player.tilex;
	y = (TILE_SIZE * MINIMAP_SCALE_FACTOR) + g_player.tiley;
	while (g_player.tiley < y)
	{
		while (g_player.tilex < x)
		{
			data->addr[(int)g_player.tiley * g_ray.win_w + (int)g_player.tilex] =
				g_tilecolor;
			g_player.tilex += 0.1;
		}
		g_player.tilex -= (TILE_SIZE * MINIMAP_SCALE_FACTOR);
		g_player.tiley += 0.1;
	}
}

void		map(t_data *data)
{
	int		i;
	int		j;

	g_player.tilex = 0;
	g_player.tiley = 0;
	i = -1;
	while (++i < NUM_ROWS)
	{
		j = -1;
		while (++j < NUM_COLS)
		{
			g_player.tilex = j * TILE_SIZE * MINIMAP_SCALE_FACTOR;
			g_player.tiley = i * TILE_SIZE * MINIMAP_SCALE_FACTOR;
			if (Map[i][j] == 1)
			{
				g_tilecolor = 0x5C413B;
				drawing_cub_walls(data);
			}
			else if (Map[i][j] == 0)
			{
				g_tilecolor = 0xC4C0C0;
				drawing_cub_walls(data);
			}
		}
	}
}
