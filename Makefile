#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ohachami <ohachami@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/04 20:23:13 by ohachami          #+#    #+#              #
#    Updated: 2022/12/04 20:23:17 by ohachami         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

NAME_bonus = checker

CFLAGS = -Wall -Werror -Wextra

CC = gcc

SRC = instraction.c\
	stack_sorting.c\
	error_detct.c\
	ft_stack.c\
	push_swap_utils.c\
	sorting_utils.c\
	min_oper_element.c\
	push_place.c

LIBFT = ./libft/libft.a

SRC_Bonus = checker.c

OBJ = $(SRC:.c=.o)

OBJ_bonus = $(SRC_Bonus:.c=.o)

all : $(NAME)

$(NAME):$(OBJ)
	make -C ./libft
	gcc $(CFLAGS) push_swap.c $(OBJ) $(LIBFT) -o $(NAME)

bonus : $(NAME_bonus)

$(NAME_bonus):$(OBJ) $(OBJ_bonus)
	make -C ./libft
	gcc $(CFLAGS) $(OBJ) $(OBJ_bonus) $(LIBFT) -o $(NAME_bonus)

clean:
	make -C libft clean
	rm -f *.o

fclean: clean
	make -C libft fclean
	rm -f $(NAME) $(NAME_bonus)

re : fclean all

.PONY: clean fclean re

