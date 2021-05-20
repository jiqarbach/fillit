/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiqarbac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 20:06:08 by jiqarbac          #+#    #+#             */
/*   Updated: 2019/10/15 23:06:09 by yataji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "libft/libft.h"
# include <fcntl.h>

typedef struct		s_tetrim
{
	int				line[4];
	int				clmn[4];
	char			alpha;
	struct s_tetrim *next;
}					t_tetrim;

int					ft_sqrt(int nb);
int					put_bloc(char **map, int y, int x, int size);
int					attempt(char **map, t_tetrim *trs, int size);
int					ft_check_form(char *tetrim);
int					ft_check_tetrim(char *tetrim);
void				print(char **map);
int					ft_checknstore(int fd, t_tetrim **tetris);
t_tetrim			*ft_store_tetrim(char *buff, int order);
void				ft_store_blocs(char *tetrim, t_tetrim *new);
char				**ft_gen_map(int size);
void				slove_tetris(t_tetrim *tetris, int elem);
void				erease(char **map, t_tetrim *trs, int y, int x);
void				clear_map(char **map);
void				clear_tetris(t_tetrim **tetris);
#endif
