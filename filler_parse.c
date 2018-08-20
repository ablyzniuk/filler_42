/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler_parse.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablizniu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/12 21:55:35 by ablizniu          #+#    #+#             */
/*   Updated: 2018/06/12 21:55:37 by ablizniu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int					read_validator(char *line, t_filler **filler)
{
	char			*s;
	int				i;

	i = 0;
	if (ft_strstr(line, "Plateau"))
	{
		s = ft_strdup("Plateau");
		while (line[i] && (line[i] == s[i] || line[i] == ' '))
			i++;
		(*filler)->len_y = ft_atoi(&line[i]);
		while (ft_isdigit(line[i]))
			i++;
		(*filler)->len_x = ft_atoi(&line[i]);
		ft_strdel(&s);
		if ((*filler)->map == NULL)
		{
			if (!((*filler)->map = (char **)
			ft_memalloc(sizeof(char *) * (*filler)->len_y)))
				set_null();
			all_null(filler);
		}
		return (1);
	}
	else
		return (0);
}

void				map_creator(t_filler **filler,
					t_token *token, char *line)
{
	unsigned int	start;
	char			*buff;
	int				i;

	i = 0;
	start = 0;
	buff = NULL;
	if (!read_validator(line, filler))
	{
		while (get_next_line((*filler)->fd, &buff) > 0)
		{
			if (parser_line(buff, &start, filler) && i < (*filler)->len_y)
			{
				((*filler)->map[i] == NULL) ?
				((*filler)->map[i] = ft_strdup(buff + 4)) :
				(write_in(filler, buff, 4, i));
				ft_strdel(&buff);
				i++;
			}
			else if (kostil_for_map_creator(filler, buff, token, &i))
				break ;
		}
	}
}

int					parser_line(char *line, unsigned int *i, t_filler **filler)
{
	int				k;

	k = 0;
	while (ft_isdigit(line[*i]) || line[*i] == ' ')
		*i += 1;
	while (line[*i + k] == '.' ||
	(line[*i + k] == ME || line[*i + k] == SMALL_ME)
	|| (line[*i + k] == ENEMY || line[*i + k] == SMALL_ENEMY))
		k++;
	if (k == 0)
		return (0);
	else
		return (1);
}

void				write_in(t_filler **filler,
					char *line, int start, int index)
{
	ft_bzero((*filler)->map[index], (size_t)(*filler)->len_x);
	ft_memcpy((*filler)->map[index], line + start, (size_t)(*filler)->len_x);
}

void				all_null(t_filler **filler)
{
	int				i;

	i = 0;
	while (i < (*filler)->len_y)
	{
		(*filler)->map[i] = NULL;
		i++;
	}
}
