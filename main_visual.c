/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_visual.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablizniu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/07 21:48:53 by ablizniu          #+#    #+#             */
/*   Updated: 2018/08/07 21:48:58 by ablizniu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visual.h"

int				main(void)
{
	char		*line;
	t_filler	*filler;
	int			i;

	i = 0;
	init_(&g_image);
	filler = NULL;
	init_filler(&filler);
	line = NULL;
	while (get_next_line(filler->fd, &line) && i < 8)
	{
		i++;
		free(line);
	}
	mlx_hook(g_image.mlx_window, 2, 5, exit_1, &filler);
	mlx_loop_hook(g_image.mlx_ptr, filler_funk, &filler);
	mlx_loop(g_image.mlx_ptr);
	return (0);
}

int				filler_funk(t_filler **filler)
{
	char		*line;

	line = NULL;
	while (get_next_line((*filler)->fd, &line) > 0)
	{
		map_creator(filler, line);
		if ((*filler)->good_for_output == 1)
		{
			(*filler)->good_for_output = 0;
			mlx_clear_window(g_image.mlx_ptr, g_image.mlx_window);
			writing_field(filler, &g_image);
			mlx_do_sync(g_image.mlx_ptr);
			size_for_field(filler);
		}
		ft_strdel(&line);
	}
	final_score(filler);
	return (1);
}

int				read_validator(char *line, t_filler **filler)
{
	char		*s;
	int			i;

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
			(*filler)->map = (char **)ft_memalloc(sizeof(char *)
			* (*filler)->len_y);
			size_for_field(filler);
		}
		return (1);
	}
	else
		return (0);
}

void			map_creator(t_filler **filler, char *line)
{
	char		*buff;
	int			i;

	i = 0;
	buff = NULL;
	if (!read_validator(line, filler))
	{
		while (get_next_line((*filler)->fd, &buff) > 0)
		{
			if (ft_strlen(buff + 4) == (size_t)(*filler)->len_x)
			{
				if ((*filler)->map[i] == NULL && i != (*filler)->len_y)
					kostil_1(filler, buff, &i);
				if ((*filler)->map[i] != NULL && i != (*filler)->len_y)
					kostil_2(filler, buff, &i);
			}
			else if (kostil_3(filler, buff))
				break ;
		}
	}
}

int				read_token_1(t_filler **filler)
{
	char		*line;

	line = NULL;
	while (get_next_line((*filler)->fd, &line) > 0)
	{
		if (ft_strstr(line, "<got "))
		{
			ft_strdel(&line);
			return (1);
		}
		ft_strdel(&line);
	}
	return (1);
}
