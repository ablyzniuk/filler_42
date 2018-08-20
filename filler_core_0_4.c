/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler_core_0_4.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablizniu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/07 17:17:19 by ablizniu          #+#    #+#             */
/*   Updated: 2018/08/07 17:17:22 by ablizniu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void		final_sets(t_filler **filler, t_token *token, t_position *set)
{
	int		i;

	i = 0;
	while (set[i].summ == 0 && i < token->struct_len)
		i++;
	(*filler)->x = set[i].x;
	(*filler)->y = set[i].y;
	(*filler)->number = 1;
	output_coords(filler);
	(*filler)->x = 0;
	(*filler)->y = 0;
	free_set(set, token);
	free_token(token);
}

void		summ_for_set(t_token *token, t_position *set)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (j < token->struct_len)
	{
		i = 0;
		set[j].summ = 0;
		while (i < token->shapes)
		{
			set[j].summ += set[j].value[i];
			i++;
		}
		j++;
	}
}

int			count_variants(t_filler **filler, t_token *token)
{
	int		count;

	count = 0;
	(*filler)->x = 0;
	(*filler)->y = 0;
	while ((*filler)->y <= (*filler)->len_y - token->size_y)
	{
		(*filler)->x = 0;
		while ((*filler)->x <= (*filler)->len_x - token->size_x)
		{
			if (compare(filler, token))
				count++;
			(*filler)->x++;
		}
		(*filler)->y++;
	}
	(*filler)->x = 0;
	(*filler)->y = 0;
	return (count);
}

void		free_set(t_position *set, t_token *token)
{
	int		i;

	i = 0;
	if (set == NULL)
		return ;
	while (i < token->struct_len)
	{
		set[i].x = 0;
		set[i].y = 0;
		set[i].summ = 0;
		ft_memdel((void *)&set[i].value);
		i++;
	}
	free(set);
	set = NULL;
}

void		free_token(t_token *token)
{
	int		i;

	i = 0;
	if (token->token == NULL)
		return ;
	token->counts = 0;
	token->shapes = 0;
	token->size_x = 0;
	while (i < token->size_y)
	{
		if (token->token[i] != NULL)
			ft_strdel(&token->token[i]);
		i++;
	}
	token->size_y = 0;
	ft_memdel((void **)&token->token);
	if (token->coord_x != NULL)
		ft_memdel((void *)&token->coord_x);
	if (token->coord_y != NULL)
		ft_memdel((void *)&token->coord_y);
}
