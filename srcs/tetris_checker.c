/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetris_checker.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiqarbac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 16:46:18 by jiqarbac          #+#    #+#             */
/*   Updated: 2019/10/15 22:58:23 by yataji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fillit.h"

void		print(char **map)
{
	int		i;

	i = 0;
	while (map[i])
		ft_putendl(map[i++]);
}

int			ft_check_form(char *tetrim)
{
	int		i;
	int		link;
	int		point;
	int		hash;

	i = 0;
	link = 0;
	point = 0;
	hash = 0;
	while (tetrim[i])
	{
		if (tetrim[i] == '.')
			point++;
		else if (tetrim[i] == '#')
		{
			hash++;
			link += (i < 19 && tetrim[i + 1] == '#' ? 1 : 0);
			link += (i < 14 && tetrim[i + 5] == '#' ? 1 : 0);
			link += (i >= 1 && tetrim[i - 1] == '#' ? 1 : 0);
			link += (i >= 5 && tetrim[i - 5] == '#' ? 1 : 0);
		}
		i++;
	}
	return ((point == 12 && hash == 4 && (link == 6 || link == 8)));
}

int			ft_check_tetrim(char *tetrim)
{
	if (!(tetrim[4] == '\n' && tetrim[9] == '\n' && tetrim[14] == '\n' &&\
				tetrim[19] == '\n' && (tetrim[20] == '\n' || !tetrim[20])))
		return (-1);
	if (!(ft_check_form(tetrim)))
		return (-1);
	return (0);
}

int			ft_checknstore(int fd, t_tetrim **tetris)
{
	char		buff[22];
	int			ret;
	int			order;
	t_tetrim	*tmp;

	order = -1;
	while ((ret = read(fd, buff, 21)) > 0 && order < 25)
	{
		buff[ret] = '\0';
		if ((ft_check_tetrim(buff)) < 0)
			return (-1);
		if (order++ == -1)
		{
			*tetris = ft_store_tetrim(buff, order);
			tmp = *tetris;
		}
		else
		{
			tmp->next = ft_store_tetrim(buff, order);
			tmp = tmp->next;
		}
	}
	return (((ret == 0 && buff[20] != '\0') || ret != 0) ? -1 : order);
}
