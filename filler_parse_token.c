/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler_parse_token.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablizniu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/03 18:00:04 by ablizniu          #+#    #+#             */
/*   Updated: 2018/07/03 18:00:06 by ablizniu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void			read_token(char *line, t_filler **filler, t_token *token)
{
	if (read_token_size(line, token))
		read_token_1(token, filler);
}

int				read_token_size(char *line, t_token *token)
{
	if (ft_strstr(line, "Piece"))
	{
		token->size_y = ft_atoi(ft_strchr(line, ' ') + 1);
		token->size_x = ft_atoi(ft_strchr(line, ' ') + 3);
		return (1);
	}
	return (0);
}

void			read_token_1(t_token *token, t_filler **filler)
{
	char		*line;
	int			i;

	i = 0;
	if (token->token == NULL)
		token->token = (char **)ft_memalloc(sizeof(char *) * token->size_y);
	while (get_next_line((*filler)->fd, &line) > 0)
	{
		if (!(token->token[i] = (char *)
		ft_memalloc(sizeof(char) * token->size_x)) && i < token->size_y)
		{
			set_null();
			return ;
		}
		token->token[i] = ft_memcpy(token->token[i],
		line, (size_t)token->size_x);
		ft_strdel(&line);
		i++;
		if (i == token->size_y)
		{
			token->shapes = quantity_of_shapes(token);
			filler_core(filler, token);
			break ;
		}
	}
}

int				quantity_of_shapes(t_token *token)
{
	char		**map;
	int			i;
	int			j;
	int			k;

	j = 0;
	k = 0;
	map = token->token;
	while (j < token->size_y && map[j] != NULL)
	{
		i = 0;
		while (i < token->size_x)
		{
			if (map[j][i] == '*')
				k++;
			i++;
		}
		j++;
	}
	return (k);
}

void			set_null(void)
{
	ft_putnbr(0);
	ft_putchar(' ');
	ft_putnbr(0);
	ft_putchar('\n');
}
