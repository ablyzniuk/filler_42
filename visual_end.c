/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visual_end.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablizniu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/06 17:01:03 by ablizniu          #+#    #+#             */
/*   Updated: 2018/08/06 17:01:04 by ablizniu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visual.h"

void	kostil_1(t_filler **filler, char *buff, int *i)
{
	(*filler)->map[*i] = ft_strdup(buff + 4);
	*i += 1;
	ft_strdel(&buff);
}

void	kostil_2(t_filler **filler, char *buff, int *i)
{
	ft_memcpy((*filler)->map[*i], buff + 4, (size_t)(*filler)->len_x);
	*i += 1;
	ft_strdel(&buff);
}

int		kostil_3(t_filler **filler, char *buff)
{
	if (ft_strstr(buff, "Piece "))
	{
		if (read_token_1(filler))
		{
			ft_strdel(&buff);
			(*filler)->good_for_output = 1;
			return (1);
		}
	}
	return (0);
}

void	kostil_4(t_filler **filler)
{
	mlx_string_put(g_image.mlx_ptr, g_image.mlx_window,
	150, 900, 0x0000FF, "O Lost :");
	mlx_string_put(g_image.mlx_ptr, g_image.mlx_window,
	150, 950, 0x0000FF, ft_itoa((*filler)->o));
	mlx_string_put(g_image.mlx_ptr, g_image.mlx_window,
	1000, 900, 0xFF0000, "X Win :");
	mlx_string_put(g_image.mlx_ptr, g_image.mlx_window,
	1000, 950, 0xFF0000, ft_itoa((*filler)->x));
}

void	kostil_5(t_filler **filler)
{
	mlx_string_put(g_image.mlx_ptr, g_image.mlx_window,
	150, 900, 0x0000FF, "O Win :");
	mlx_string_put(g_image.mlx_ptr, g_image.mlx_window,
	150, 950, 0x0000FF, ft_itoa((*filler)->o));
	mlx_string_put(g_image.mlx_ptr, g_image.mlx_window,
	1000, 900, 0xFF0000, "X Lost :");
	mlx_string_put(g_image.mlx_ptr, g_image.mlx_window,
	1000, 950, 0xFF0000, ft_itoa((*filler)->x));
}
