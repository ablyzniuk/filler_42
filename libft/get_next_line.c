/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablizniu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/28 21:09:38 by ablizniu          #+#    #+#             */
/*   Updated: 2018/01/28 21:09:41 by ablizniu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_arr	*funk_list(const int fd, t_arr *list)
{
	t_arr	*new_elem;
	t_arr	*time;
	int		temp_fd;

	if (!list)
	{
		list = (t_arr*)ft_memalloc(sizeof(t_arr));
		list->fd = fd;
		list->arr = NULL;
		list->next = list;
		return (list);
	}
	temp_fd = list->fd;
	while (list->fd != fd && list->next->fd != temp_fd)
		list = list->next;
	if (list->fd == fd)
		return (list);
	new_elem = (t_arr*)ft_memalloc(sizeof(t_arr));
	new_elem->fd = fd;
	new_elem->arr = NULL;
	time = list->next;
	new_elem->next = time;
	list->next = new_elem;
	return (new_elem);
}

static int		ft_cheackbuff(char **line, char *buff, char **arr)
{
	if (ft_strchr(buff, '\n'))
	{
		*line = ft_strsub(buff, 0, ft_strchr(buff, '\n') - buff);
		if (*(ft_strchr(buff, '\n') + 1))
			*arr = ft_strdup(ft_strchr(buff, '\n') + 1);
		return (1);
	}
	else if ((*line = ft_strdup(buff)))
		ft_strdel(arr);
	return (0);
}

static int		ft_line_join(char **line, char *buff, char **arr)
{
	char	*time_str;
	char	*one_more_line;

	if (ft_strchr(buff, '\n'))
	{
		time_str = *line;
		one_more_line = ft_strsub(buff, 0, ft_strchr(buff, '\n') - buff);
		*line = ft_strjoin(*line, one_more_line);
		ft_strdel(&time_str);
		ft_strdel(&one_more_line);
		*arr = ft_strdup(ft_strchr(buff, '\n') + 1);
		return (1);
	}
	else
	{
		time_str = *line;
		*line = ft_strjoin(*line, buff);
		ft_strdel(&time_str);
	}
	return (0);
}

static void		ft_checktail(char **line, char **arr)
{
	char	*buff;

	if (*arr && !**arr)
		ft_strdel(arr);
	if (*arr && **arr)
	{
		if (!ft_strchr(*arr, '\n') && (*line = ft_strdup(*arr)))
			ft_strdel(arr);
		else
		{
			*line = ft_strsub(*arr, 0, ft_strchr(*arr, '\n') - *arr);
			buff = *arr;
			*arr = ft_strdup(ft_strchr(*arr, '\n') + 1);
			ft_strdel(&buff);
		}
	}
}

int				get_next_line(const int fd, char **line)
{
	int				file;
	static t_arr	*list;
	char			*buff;

	if (fd < 0 || BUFF_SIZE <= 0 || !line)
		return (-1);
	list = funk_list(fd, list);
	*line = NULL;
	ft_checktail(line, &(list->arr));
	buff = ft_strnew(BUFF_SIZE);
	while (!(list->arr) && (file = (int)read(list->fd, buff, BUFF_SIZE)) > 0)
	{
		if (!*line)
		{
			if (ft_cheackbuff(line, buff, &(list->arr)) == 1)
				break ;
		}
		else if (*line && ft_line_join(line, buff, &(list->arr)) == 1)
			break ;
		ft_bzero((void*)buff, BUFF_SIZE);
	}
	ft_strdel(&buff);
	if (file < 0)
		return (-1);
	return (*line ? 1 : 0);
}
