/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablizniu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/12 21:23:38 by ablizniu          #+#    #+#             */
/*   Updated: 2018/08/07 23:00:48 by ablizniu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int				main(void)
{
	char		*line;
	t_token		token;
	t_filler	*filler;

	filler = (t_filler *)ft_memalloc(sizeof(t_filler));
	filler->number = 1;
	filler->me = 0;
	filler->map = NULL;
	token.token = NULL;
	filler->fd = 0;
	if (get_next_line(filler->fd, &line) > 0 && filler->me == 0)
	{
		(filler->me == 0) ? (choose_player(&filler, line)) : (0);
		ft_strdel(&line);
	}
	while (get_next_line(filler->fd, &line) > 0)
	{
		if (ft_strstr(line, "==") || ft_strstr(line, "<got "))
			break ;
		map_creator(&filler, &token, line);
		free(line);
	}
	free_map(&filler);
	free(filler);
	return (0);
}

void			free_map(t_filler **filler)
{
	int			i;

	i = 0;
	while (i < (*filler)->len_y)
	{
		free((*filler)->map[i]);
		i++;
	}
	free((*filler)->map);
}

void			choose_player(t_filler **filler, char *line)
{
	if (*(ft_strchr(line, 'p') + 1) == '1')
	{
		(*filler)->me = 'O';
		(*filler)->enemy = 'X';
	}
	else if (*(ft_strchr(line, 'p') + 1) == '2')
	{
		(*filler)->me = 'X';
		(*filler)->enemy = 'O';
	}
}

int				kostil_for_map_creator(t_filler **filler,
				char *buff, t_token *token, int *i)
{
	if (*i == (*filler)->len_y)
	{
		*i = 0;
		read_token(buff, filler, token);
		ft_strdel(&buff);
		return (1);
	}
	return (0);
}
