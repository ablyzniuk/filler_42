/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visual_start.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablizniu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/06 17:00:52 by ablizniu          #+#    #+#             */
/*   Updated: 2018/08/06 17:00:53 by ablizniu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visual.h"

void		final_score(t_filler **filler)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	(*filler)->x = 0;
	(*filler)->o = 0;
	while (i < (*filler)->len_y)
	{
		j = 0;
		while (j < (*filler)->len_x)
		{
			if ((*filler)->map[i][j] == 'X' || (*filler)->map[i][j] == 'x')
				(*filler)->x++;
			else if ((*filler)->map[i][j] == 'O' || (*filler)->map[i][j] == 'o')
				(*filler)->o++;
			j++;
		}
		i++;
	}
	output_score(filler);
}

void		output_score(t_filler **filler)
{
	if ((*filler)->x > (*filler)->o)
		kostil_4(filler);
	if ((*filler)->x < (*filler)->o)
		kostil_5(filler);
	mlx_do_sync(g_image.mlx_ptr);
}

int			exit_1(int keycode, t_filler **filler)
{
	if (keycode == 53)
	{
		free_filler(filler);
		free(*filler);
		exit(0);
	}
	return (1);
}

void		init_filler(t_filler **filler)
{
	*filler = (t_filler *)ft_memalloc(sizeof(t_filler));
	(*filler)->fd = 0;
	(*filler)->me = 0;
	(*filler)->map = NULL;
}

void		free_filler(t_filler **filler)
{
	int		i;

	i = 0;
	while (i < (*filler)->len_y)
	{
		ft_strdel(&(*filler)->map[i]);
		i++;
	}
	ft_memdel((void **)&(*filler)->map);
}
