/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiqarbac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 20:10:00 by jiqarbac          #+#    #+#             */
/*   Updated: 2019/10/15 22:59:30 by yataji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fillit.h"

int			ft_sqrt(int nb)
{
	int		i;

	i = 1;
	while (i * i < nb)
		i++;
	return (i);
}

int			main(int ac, char **av)
{
	t_tetrim	*tetris;
	int			elem;
	int			fd;

	if (ac != 2)
	{
		ft_putendl("usage: ./fillit [file_name]");
		return (0);
	}
	if ((fd = open(av[1], O_RDONLY)) < 0)
	{
		ft_putendl("error");
		exit(0);
	}
	if ((elem = ft_checknstore(fd, &tetris)) < 0)
	{
		clear_tetris(&tetris);
		ft_putendl("error");
		exit(0);
	}
	elem = ft_sqrt((elem + 1) * 4);
	slove_tetris(tetris, elem);
	clear_tetris(&tetris);
	exit(0);
}
