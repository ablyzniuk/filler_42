/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visual_core.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablizniu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/06 17:09:34 by ablizniu          #+#    #+#             */
/*   Updated: 2018/08/06 17:09:59 by ablizniu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visual.h"

void			initialise(t_image *tmp)
{
	tmp->mlx_ptr = NULL;
	tmp->mlx_window = 0;
	tmp->data_buff = NULL;
	tmp->size_line = 0;
	tmp->endian = 0;
}

void			init_(t_image *image)
{
	image->mlx_ptr = mlx_init();
	image->mlx_window = mlx_new_window(image->mlx_ptr, W, H, "filler_vs");
	image->bpp /= 8;
}

void			size_for_field(t_filler **filler)
{
	if ((*filler)->len_x == 99 && (*filler)->len_y == 100)
		v_1(filler);
	else if ((*filler)->len_x == 40 && (*filler)->len_y == 24)
		v_2(filler);
	else if ((*filler)->len_x == 17 && (*filler)->len_y == 15)
		v_3(filler);
}

void			writing_cel(int color, t_filler **filler, t_image *image)
{
	int			i;
	int			j;
	static int	k;

	i = (*filler)->i_0;
	j = (*filler)->j_0;
	while ((*filler)->i_0 < (*filler)->size_of_cell_y + i)
	{
		(*filler)->j_0 = j;
		while ((*filler)->j_0 < (*filler)->size_of_cell_x + j)
		{
			mlx_pixel_put(image->mlx_ptr,
			image->mlx_window, (*filler)->j_0, (*filler)->i_0, color);
			(*filler)->j_0++;
		}
		(*filler)->i_0++;
	}
	k++;
	k_1(filler, &k, &i);
}

void			writing_field(t_filler **filler, t_image *image)
{
	int			i;
	int			j;

	j = 0;
	i = 0;
	while (i < (*filler)->len_y)
	{
		j = 0;
		while (j < (*filler)->len_x)
		{
			if ((*filler)->map[i][j] == '.')
				writing_cel(0xFFFFFF, filler, image);
			else if ((*filler)->map[i][j] == 'X')
				writing_cel(0xFF0000, filler, image);
			else if ((*filler)->map[i][j] == 'O')
				writing_cel(0x0000FF, filler, image);
			else if ((*filler)->map[i][j] == 'x')
				writing_cel(0xffd700, filler, image);
			else if ((*filler)->map[i][j] == 'o')
				writing_cel(0x50fa83, filler, image);
			j++;
		}
		i++;
	}
}
