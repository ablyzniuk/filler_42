/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler_core_0_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablizniu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/06 20:53:58 by ablizniu          #+#    #+#             */
/*   Updated: 2018/08/06 20:54:00 by ablizniu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void		set_token(t_filler **filler, t_token *token)
{
	coord_x(token);
	coord_y(token);
	(*filler)->y = 0;
	(*filler)->x = 0;
	token->counts = 0;
	token->counts = count_variants(filler, token);
	if (!final_check(filler, token))
	{
		ft_putnbr(0);
		ft_putchar(' ');
		ft_putnbr(0);
		ft_putchar('\n');
		free_token(token);
		return ;
	}
}

void		coord_x(t_token *token)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	k = 0;
	if (!(token->coord_x = (int *)ft_memalloc(sizeof(int) * token->shapes)))
		return ;
	while (i < token->size_y)
	{
		j = 0;
		while (j < token->size_x)
		{
			if (token->token[i][j] == '*')
			{
				token->coord_x[k] = j;
				k++;
			}
			j++;
		}
		i++;
	}
}

void		coord_y(t_token *token)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	k = 0;
	if (!(token->coord_y = (int *)ft_memalloc(sizeof(int) * token->shapes)))
		return ;
	while (i < token->size_y)
	{
		j = 0;
		while (j < token->size_x)
		{
			if (token->token[i][j] == '*')
			{
				token->coord_y[k] = i;
				k++;
			}
			j++;
		}
		i++;
	}
}

int			compare(t_filler **filler, t_token *token)
{
	int		i;
	int		j;
	int		k;

	k = 0;
	i = (*filler)->y;
	j = (*filler)->x;
	while (k < token->shapes)
	{
		if ((TOKEN_ON_MAP == (*filler)->me || TOKEN_ON_MAP ==
			ft_tolower((*filler)->me)) && (TOKEN_ON_MAP !=
			(*filler)->enemy || TOKEN_ON_MAP !=
			ft_tolower((*filler)->enemy)))
			return (1);
		k++;
	}
	return (0);
}

void		output_coords(t_filler **filler)
{
	ft_putnbr((*filler)->y);
	ft_putchar(' ');
	ft_putnbr((*filler)->x);
	ft_putchar('\n');
}
