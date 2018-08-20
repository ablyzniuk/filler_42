/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler_core_0_1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablizniu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/06 20:53:50 by ablizniu          #+#    #+#             */
/*   Updated: 2018/08/06 20:53:52 by ablizniu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	c_0(t_filler **filler, int x, int y, char who)
{
	if (((*filler)->map[y][x - 1] != ENEMY || (*filler)->map[y][x - 1]
	!= SMALL_ENEMY) && ((*filler)->map[y][x - 1] != ME ||
	(*filler)->map[y][x - 1] != SMALL_ME) &&
	(*filler)->map[y][x - 1] == '.')
		(*filler)->map[y][x - 1] = who;
	if ((y - 1 >= 0) && ((*filler)->map[y - 1][x] != ENEMY ||
	(*filler)->map[y - 1][x] != SMALL_ENEMY) && ((*filler)->map[y - 1][x] != ME
	|| (*filler)->map[y - 1][x] != SMALL_ME) && (*filler)->map[y - 1][x] == '.')
		(*filler)->map[y - 1][x] = who;
}

void	c_1(t_filler **filler, int x, int y, char who)
{
	if (((*filler)->map[y][x + 1] != ENEMY || (*filler)->map[y][x + 1]
	!= SMALL_ENEMY) && ((*filler)->map[y][x + 1] != ME ||
	(*filler)->map[y][x + 1] != SMALL_ME) && (*filler)->map[y][x + 1] == '.')
		(*filler)->map[y][x + 1] = who;
	if ((y + 1 < (*filler)->len_y) && ((*filler)->map[y + 1][x] != ENEMY
	|| (*filler)->map[y + 1][x] != SMALL_ENEMY) &&
	((*filler)->map[y + 1][x] != ME || (*filler)->map[y + 1][x] != SMALL_ME)
	&& (*filler)->map[y + 1][x] == '.')
		(*filler)->map[y + 1][x] = who;
}

void	c_2(t_filler **filler, int x, int y, char who)
{
	if ((y - 1 >= 0) && ((*filler)->map[y - 1][x - 1] != ENEMY
	|| (*filler)->map[y - 1][x - 1] != SMALL_ENEMY) &&
	((*filler)->map[y - 1][x - 1] != ME
	|| (*filler)->map[y - 1][x - 1] != SMALL_ME) &&
	(*filler)->map[y - 1][x - 1] == '.')
		(*filler)->map[y - 1][x - 1] = who;
	if ((y - 1 >= 0) && ((*filler)->map[y - 1][x + 1] != ENEMY ||
	(*filler)->map[y - 1][x + 1] != SMALL_ENEMY) &&
	((*filler)->map[y - 1][x + 1] != ME ||
	(*filler)->map[y - 1][x + 1] != SMALL_ME) &&
	(*filler)->map[y - 1][x + 1] == '.')
		(*filler)->map[y - 1][x + 1] = who;
}

void	c_3(t_filler **filler, int x, int y, char who)
{
	if ((y + 1 < (*filler)->len_y) && ((*filler)->map[y + 1][x - 1] != ENEMY ||
	(*filler)->map[y + 1][x - 1] != SMALL_ENEMY) &&
	((*filler)->map[y + 1][x - 1] != ME ||
	(*filler)->map[y + 1][x - 1] != SMALL_ME)
	&& (*filler)->map[y + 1][x - 1] == '.')
		(*filler)->map[y + 1][x - 1] = who;
	if ((y + 1 < (*filler)->len_y) && ((*filler)->map[y + 1][x + 1] != ENEMY ||
	(*filler)->map[y + 1][x + 1] != SMALL_ENEMY) &&
	((*filler)->map[y + 1][x + 1] != ME ||
	(*filler)->map[y + 1][x + 1] != SMALL_ME)
	&& (*filler)->map[y + 1][x + 1] == '.')
		(*filler)->map[y + 1][x + 1] = who;
}
