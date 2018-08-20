/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler_core_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablizniu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/07 19:16:01 by ablizniu          #+#    #+#             */
/*   Updated: 2018/07/07 19:16:03 by ablizniu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int					final_check(t_filler **filler, t_token *token)
{
	t_position		*set;
	int				i;

	i = 0;
	if (!(set = (t_position *)
	ft_memalloc(sizeof(t_position) * (token->counts) + 1)))
		return (0);
	while ((*filler)->y <= (*filler)->len_y - token->size_y)
	{
		(*filler)->x = 0;
		while ((*filler)->x <= (*filler)->len_x - token->size_x)
		{
			if (compare(filler, token))
			{
				if (!kostil_final_check(filler, set, token, i))
					return (0);
				i++;
			}
			(*filler)->x++;
		}
		(*filler)->y++;
	}
	if ((kostil_final_check_2(filler, set, token, i)))
		return (1);
	return (0);
}

void				sort_struct(t_filler **filler,
					t_token *token, t_position *set)
{
	t_position		*start;
	t_position		buff;
	int				i;

	i = 0;
	start = set;
	while (trim_1(set, token) == 0)
	{
		i = 0;
		set = start;
		while (i < token->struct_len - 1)
		{
			if (set[i].summ > set[i + 1].summ)
			{
				buff = set[i];
				set[i] = set[i + 1];
				set[i + 1] = buff;
			}
			i++;
		}
	}
	final_sets(filler, token, set);
}

void				edit_struct_arr(t_token *token, t_position *set)
{
	int				i;
	int				j;
	int				k;

	k = 0;
	i = 0;
	while (i < token->struct_len)
	{
		j = 0;
		while (j < token->shapes)
		{
			if (set[i].value[j] == 0)
				k++;
			j++;
		}
		if (k >= 2)
			set[i].summ = 0;
		k = 0;
		i++;
	}
}

int					kostil_final_check(t_filler **filler,
					t_position *set, t_token *token, int i)
{
	set[i].x = (*filler)->x;
	set[i].y = (*filler)->y;
	set[i].summ = 0;
	if (!(set[i].value = (int *)ft_memalloc(sizeof(int) * token->shapes)))
		return (0);
	set_for(filler, token, set[i]);
	remove_me_from_and_sort(filler, token, set[i]);
	return (1);
}

int					kostil_final_check_2(t_filler **filler,
					t_position *set, t_token *token, int i)
{
	token->struct_len = i;
	summ_for_set(token, set);
	edit_struct_arr(token, set);
	if (i > 0)
	{
		sort_struct(filler, token, set);
		return (1);
	}
	return (0);
}
