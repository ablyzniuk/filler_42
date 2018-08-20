/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler_core_0_3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablizniu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/06 20:54:04 by ablizniu          #+#    #+#             */
/*   Updated: 2018/08/06 20:54:05 by ablizniu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void		set_for(t_filler **filler, t_token *token, t_position set)
{
	int		k;

	k = 0;
	while (k < token->shapes)
	{
		set.value[k] = (*filler)->map[(*filler)->y +
		token->coord_y[k]][(*filler)->x + token->coord_x[k]];
		k++;
	}
}

void		remove_me_from_and_sort(t_filler **filler,
			t_token *token, t_position set)
{
	int		i;

	i = 0;
	while (i < token->shapes)
	{
		if (((int)ME == set.value[i] || SMALL_ME == set.value[i])
		|| (set.value[i] == ENEMY || set.value[i] == SMALL_ENEMY))
			set.value[i] = 0;
		i++;
	}
	sort_arr_struct(set.value, token);
}

int			trim(const int *arr, t_token *token)
{
	int		i;

	i = 0;
	while (i + 1 < token->shapes)
	{
		if (arr[i] > arr[i + 1])
			return (0);
		i++;
	}
	return (1);
}

void		sort_arr_struct(int *tab, t_token *token)
{
	int		*tmp;
	int		tmp_1;
	int		i;

	tmp = tab;
	while (trim(tmp, token) == 0)
	{
		tab = tmp;
		i = 0;
		while (i + 1 < token->shapes)
		{
			if (tab[i] > tab[i + 1])
			{
				tmp_1 = tab[i];
				tab[i] = tab[i + 1];
				tab[i + 1] = tmp_1;
			}
			i++;
		}
	}
}

int			trim_1(t_position *set, t_token *token)
{
	int		i;

	i = 0;
	while (i < token->struct_len - 1)
	{
		if (set[i].summ > set[i + 1].summ)
			return (0);
		i++;
	}
	return (1);
}
