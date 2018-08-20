/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visual_draw.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablizniu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/06 17:00:42 by ablizniu          #+#    #+#             */
/*   Updated: 2018/08/06 17:00:44 by ablizniu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visual.h"

void		v_1(t_filler **filler)
{
	float	size_of_cell_x;
	float	size_of_cell_y;

	(*filler)->i_0 = 0;
	(*filler)->i_1 = H;
	(*filler)->j_0 = 0;
	(*filler)->j_1 = W;
	size_of_cell_x = (float)(((*filler)->j_1 -
	(*filler)->j_0) / (*filler)->len_x - 6);
	size_of_cell_y = (float)(((*filler)->i_1 -
	(*filler)->i_0) / (*filler)->len_y - 6);
	(*filler)->j_0 += W / 8 + 10;
	(*filler)->i_0 = 100;
	(*filler)->j_1 = W - W / 8;
	(*filler)->fuck = (*filler)->j_0;
	(*filler)->k = 99;
	(*filler)->size_of_cell_x = (int)size_of_cell_x;
	(*filler)->size_of_cell_y = (int)size_of_cell_y;
}

void		v_2(t_filler **filler)
{
	float	size_of_cell_x;
	float	size_of_cell_y;

	(*filler)->i_0 = 0;
	(*filler)->i_1 = H;
	(*filler)->j_0 = 0;
	(*filler)->j_1 = W;
	size_of_cell_x = (float)(((*filler)->j_1 -
	(*filler)->j_0) / (*filler)->len_x - 15);
	size_of_cell_y = (float)(((*filler)->i_1 -
	(*filler)->i_0) / (*filler)->len_y - 26);
	(*filler)->i_0 = 100;
	(*filler)->j_0 = W / 5 + 25;
	(*filler)->j_1 = W - W / 5;
	(*filler)->fuck = (*filler)->j_0;
	(*filler)->k = 40;
	(*filler)->size_of_cell_x = (int)size_of_cell_x;
	(*filler)->size_of_cell_y = (int)size_of_cell_y;
}

void		v_3(t_filler **filler)
{
	float	size_of_cell_x;
	float	size_of_cell_y;

	(*filler)->i_0 = 0;
	(*filler)->i_1 = H;
	(*filler)->j_0 = 0;
	(*filler)->j_1 = W;
	(*filler)->k = 17;
	size_of_cell_x = (float)(((*filler)->j_1 -
	(*filler)->j_0) / (*filler)->len_x - 30);
	size_of_cell_y = (float)(((*filler)->i_1 -
	(*filler)->i_0) / (*filler)->len_y - 40);
	(*filler)->i_0 = 100;
	(*filler)->j_0 = W / 5 + 25;
	(*filler)->j_1 = W - W / 5;
	(*filler)->fuck = (*filler)->j_0;
	(*filler)->size_of_cell_x = (int)size_of_cell_x;
	(*filler)->size_of_cell_y = (int)size_of_cell_y;
}

void		k_1(t_filler **filler, int *k, int *i)
{
	if (*k == (*filler)->k)
	{
		*k = 0;
		(*filler)->i_0 += (*filler)->size_of_cell_y;
		(*filler)->j_0 = (*filler)->fuck;
	}
	else
	{
		(*filler)->i_0 = *i;
		(*filler)->j_0 += 3;
	}
}
