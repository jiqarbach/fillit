# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jiqarbac <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/22 19:54:49 by jiqarbac          #+#    #+#              #
#    Updated: 2019/10/07 20:47:34 by jiqarbac         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit
SRC = srcs/main.c srcs/tetris_checker.c srcs/store_tetris.c srcs/map_gen.c srcs/solver.c srcs/clear.c
OBJS = tetris_checker.o store_tetris.o map_gen.o solver.o clear.o main.o
FLGS = -Wall -Wextra -Werror -c

all : $(NAME)

$(NAME) :
	make -C libft/
	gcc $(FLGS) $(SRC) 
	gcc -o $(NAME) $(OBJS) libft/libft.a

clean :
	rm -f $(OBJS) && make -C libft/ clean

fclean : clean
	rm -f $(NAME) && make -C libft/ fclean

re : fclean all
