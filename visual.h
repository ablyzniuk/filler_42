/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visual.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablizniu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/07 21:49:25 by ablizniu          #+#    #+#             */
/*   Updated: 2018/08/07 21:49:28 by ablizniu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VISUAL_H
# define VISUAL_H

# include "libft/libft.h"
# include "mlx.h"
# include <limits.h>
# include <errno.h>
# include <stdio.h>
# include <math.h>
# include <time.h>
# define W 1200
# define H 1000

typedef struct			s_image
{
	char				*data_buff;
	void				*mlx_ptr;
	void				*mlx_window;
	void				*image_ptr;
	int					bpp;
	int					size_line;
	int					endian;
	int					current_x;
	int					current_y;
}						t_image;

typedef struct			s_filler
{
	int					k;
	int					i_0;
	int					i_1;
	int					j_0;
	int					j_1;
	int					fuck;
	int					size_of_cell_x;
	int					size_of_cell_y;
	int					good_for_output;
	int					fd;
	int					len_x;
	int					len_y;
	char unsigned		me;
	char unsigned		enemy;
	int					x;
	int					o;
	char				**map;
	struct s_image		*image;
}						t_filler;

t_image					g_image;

void					kostil_5(t_filler **filler);
void					kostil_4(t_filler **filler);
int						kostil_3(t_filler **filler, char *buff);
void					kostil_2(t_filler **filler, char *buff, int *i);
void					kostil_1(t_filler **filler, char *buff, int *i);
void					k_1(t_filler **filler, int *k, int *i);
void					v_1(t_filler **filler);
void					v_2(t_filler **filler);
void					v_3(t_filler **filler);
void					output_score(t_filler **filler);
void					final_score(t_filler **filler);
void					free_filler(t_filler **filler);
int						exit_1(int keycode, t_filler **filler);
int						filler_funk(t_filler **filler);
void					init_filler(t_filler **filler);
void					size_for_field(t_filler **filler);
void					map_creator(t_filler **filler, char *line);
int						read_validator(char *line,
						t_filler **filler);
void					writing_cel(int color,
						t_filler **filler, t_image *image);
void					writing_field(t_filler **filler, t_image *image);
void					init_(t_image *image);
int						read_token_1(t_filler **filler);

#endif
