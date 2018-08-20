/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablizniu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/12 21:28:22 by ablizniu          #+#    #+#             */
/*   Updated: 2018/06/12 21:28:24 by ablizniu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H
# define SMALL_ENEMY ((*filler)->enemy + 32)
# define ENEMY (*filler)->enemy
# define SMALL_ME ((*filler)->me + 32)
# define ME (*filler)->me
# define TOKEN_ON_MAP (*filler)->map[i+token->coord_y[k]][j+token->coord_x[k]]
# include <stdio.h>
# include "libft/libft.h"

typedef struct			s_filler
{
	int					x;
	int					y;
	int					fd;
	int					len_x;
	int					len_y;
	char unsigned		me;
	char unsigned		number;
	char unsigned		enemy;
	char				**map;
}						t_filler;

typedef struct			s_token
{
	int					counts;
	int					struct_len;
	int					size_y;
	int					size_x;
	char				**token;
	int					shapes;
	int					*coord_x;
	int					*coord_y;
}						t_token;

typedef struct			s_position
{
	int					summ;
	int					x;
	int					y;
	int					*value;
}						t_position;

int						kostil_final_check_2(t_filler **filler,
						t_position *set, t_token *token, int i);
int						kostil_final_check(t_filler **filler,
						t_position *set, t_token *token, int i);
void					set_null(void);
void					c_3(t_filler **filler, int x, int y, char who);
void					c_2(t_filler **filler, int x, int y, char who);
void					c_1(t_filler **filler, int x, int y, char who);
void					c_0(t_filler **filler, int x, int y, char who);
int						kostil_for_map_creator(t_filler **filler,
						char *buff, t_token *token, int *i);
void					all_null(t_filler **filler);
void					write_in(t_filler **filler,
						char *line, int start, int index);
void					free_map(t_filler **filler);
int						trim_1(t_position *set, t_token *token);
void					free_token(t_token *token);
int						count_variants(t_filler **filler, t_token *token);
void					edit_struct_arr(t_token *token, t_position *set);
void					free_set(t_position *set, t_token *token);
void					output_coords(t_filler **filler);
void					summ_for_set(t_token *token, t_position *set);
void					final_sets(t_filler **filler,
						t_token *token, t_position *set);
void					sort_struct(t_filler **filler,
						t_token *token, t_position *set);
int						trim(const int *arr, t_token *token);
void					sort_arr_struct(int *tab, t_token *token);
void					remove_me_from_and_sort(t_filler **filler, t_token
						*token, t_position set);
int						final_check(t_filler **filler, t_token *token);
int						compare(t_filler **filler, t_token *token);
void					coord_x(t_token *token);
void					coord_y(t_token *token);
void					set_token(t_filler **filler, t_token *token);
int						search_emptyness(t_filler **filler);
int						writing_the_number_fields(t_filler **filler,
						char who);
void					filling_fields_1(t_filler **filler,
						int x, int y, char who);
void					filler_core(t_filler **filler, t_token *token);
int						read_validator(char *str,
						t_filler **filler);
void					map_creator(t_filler **filler,
						t_token *token, char *line);
int						parser_line(char *line,
						unsigned int *i, t_filler **filler);
void					read_token(char *line,
						t_filler **filler, t_token *token);
void					read_token_1(t_token *token, t_filler **filler);
int						read_token_size(char *line, t_token *token);
void					choose_player(t_filler **filler, char *line);
int						quantity_of_shapes(t_token *token);
void					set_for(t_filler **filler,
						t_token *token, t_position set);

#endif
