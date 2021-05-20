/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiqarbac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 16:49:24 by jiqarbac          #+#    #+#             */
/*   Updated: 2019/10/09 20:23:13 by yataji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fillit.h"

void	clear_map(char **map)
{
	int		i;
	char	**tmp;

	i = 0;
	tmp = map;
	while (tmp[i])
		ft_strdel(&tmp[i++]);
}

void	clear_tetris(t_tetrim **tetris)
{
	t_tetrim	*tmp;

	while (*tetris)
	{
		tmp = (*tetris)->next;
		free(*tetris);
		*tetris = NULL;
		*tetris = tmp;
	}
}
