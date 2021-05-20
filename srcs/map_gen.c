/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_gen.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiqarbac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 16:50:58 by jiqarbac          #+#    #+#             */
/*   Updated: 2019/10/09 20:20:24 by yataji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fillit.h"

char	**ft_gen_map(int size)
{
	char	**map;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (size < 1 || !(map = (char **)malloc((size + 1)\
					* sizeof(char *))))
		return (NULL);
	while (i < size)
	{
		if (!(map[i] = (char *)malloc(size + 1)))
			return (NULL);
		ft_memset(map[i], '.', size);
		map[i++][size] = '\0';
	}
	map[i] = 0;
	return (map);
}
