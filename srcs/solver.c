/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiqarbac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 20:14:01 by jiqarbac          #+#    #+#             */
/*   Updated: 2019/10/15 23:17:02 by yataji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fillit.h"

int			put_bloc(char **map, int y, int x, int size)
{
	if (x < size && y < size && map[y][x] == '.')
		return (1);
	return (0);
}

int			attempt(char **map, t_tetrim *trs, int size)
{
	int		i;
	int		x;
	int		y;

	y = -1;
	while (++y < size)
	{
		x = -1;
		while (++x < size)
		{
			i = 0;
			while (i < 4 &&\
					(put_bloc(map, y + trs->line[i], x + trs->clmn[i], size)))
				i++;
			if (i == 4)
			{
				while (i-- > 0)
					map[y + trs->line[i]][x + trs->clmn[i]] = trs->alpha;
				if (!trs->next || (attempt(map, trs->next, size)) == 1)
					return (1);
				erease(map, trs, y, x);
			}
		}
	}
	return (0);
}

void		slove_tetris(t_tetrim *tetris, int elem)
{
	t_tetrim	*tmp;
	int			res;
	char		**map;

	tmp = tetris;
	if (!(map = ft_gen_map(elem)))
		return ;
	if (!(res = attempt(map, tetris, elem)) && tetris == tmp)
	{
		clear_map(map);
		slove_tetris(tmp, ++elem);
	}
	print(map);
	clear_map(map);
	free(map);
	map = NULL;
}

void		erease(char **map, t_tetrim *trs, int y, int x)
{
	int		i;

	i = -1;
	while (++i < 4)
		map[y + trs->line[i]][x + trs->clmn[i]] = '.';
}
