/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_tetris.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiqarbac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 16:53:26 by jiqarbac          #+#    #+#             */
/*   Updated: 2019/10/07 20:49:59 by jiqarbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fillit.h"

void		tetrim_sheft(t_tetrim *tetrim)
{
	while (tetrim->line[0] && tetrim->line[1] && tetrim->line[2] &&\
			tetrim->line[3])
	{
		tetrim->line[0] -= 1;
		tetrim->line[1] -= 1;
		tetrim->line[2] -= 1;
		tetrim->line[3] -= 1;
	}
	while (tetrim->clmn[0] && tetrim->clmn[1] && tetrim->clmn[2] &&\
			tetrim->clmn[3])
	{
		tetrim->clmn[0] -= 1;
		tetrim->clmn[1] -= 1;
		tetrim->clmn[2] -= 1;
		tetrim->clmn[3] -= 1;
	}
}

void		ft_store_blocs(char *tetrim, t_tetrim *new)
{
	int		i;
	int		line;
	int		column;
	int		hash;

	i = 0;
	line = 0;
	column = 0;
	hash = 0;
	while (tetrim[i] && hash < 4)
	{
		if (i == 5 || i == 10 || i == 15)
		{
			line++;
			column = 0;
		}
		if (tetrim[i] == '#')
		{
			new->line[hash] = line;
			new->clmn[hash] = column;
			hash++;
		}
		column++;
		i++;
	}
}

t_tetrim	*ft_store_tetrim(char *buff, int order)
{
	t_tetrim	*new;

	if (!(new = (t_tetrim *)malloc(sizeof(t_tetrim))))
		return (NULL);
	ft_store_blocs(buff, new);
	tetrim_sheft(new);
	new->alpha = 'A' + order;
	new->next = NULL;
	return (new);
}
