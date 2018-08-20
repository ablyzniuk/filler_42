/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler_core.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablizniu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/12 21:55:53 by ablizniu          #+#    #+#             */
/*   Updated: 2018/06/12 21:55:54 by ablizniu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void				filler_core(t_filler **filler, t_token *token)
{
	char unsigned	enemy;

	enemy = (*filler)->enemy;
	while (!search_emptyness(filler))
	{
		writing_the_number_fields(filler, (*filler)->number);
		(*filler)->enemy = (*filler)->number;
		(*filler)->number++;
	}
	(*filler)->enemy = enemy;
	set_token(filler, token);
}

int					writing_the_number_fields(t_filler **filler, char who)
{
	int				i;
	int				j;

	i = 0;
	j = 0;
	while (i < (*filler)->len_y)
	{
		j = 0;
		while (j < (*filler)->len_x)
		{
			if ((*filler)->map[i][j] == ENEMY ||
				(*filler)->map[i][j] == SMALL_ENEMY)
				filling_fields_1(filler, j, i, who);
			j++;
		}
		i++;
	}
	return (0);
}

void				filling_fields_1(t_filler **filler, int x, int y, char who)
{
	c_0(filler, x, y, who);
	c_1(filler, x, y, who);
	c_2(filler, x, y, who);
	c_3(filler, x, y, who);
}

int					search_emptyness(t_filler **filler)
{
	int				i;
	int				j;

	i = 0;
	j = 0;
	while (i < (*filler)->len_y)
	{
		j = 0;
		while (j < (*filler)->len_y)
		{
			if ((*filler)->map[i][j] == '.')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
