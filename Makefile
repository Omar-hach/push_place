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

NAME = push_swap.a

CFLAGS = -Wall -Werror -Wextra

CC = gcc

SRC = libft/ft_atoi.c\
	libft/ft_bzero.c\
	libft/ft_calloc.c\
	libft/ft_isalnum.c\
	libft/ft_isalpha.c\
	libft/ft_isascii.c\
	libft/ft_isdigit.c\
	libft/ft_isprint.c\
	libft/ft_itoa.c\
	libft/ft_memchr.c\
	libft/ft_memcmp.c\
	libft/ft_memcpy.c\
	libft/ft_memset.c\
	libft/ft_putchar_fd.c\
	libft/ft_putendl_fd.c\
	libft/ft_putnbr_fd.c\
	libft/ft_putstr_fd.c\
	libft/ft_strchr.c\
	libft/ft_strdup.c\
	libft/ft_striteri.c\
	libft/ft_strlcat.c\
	libft/ft_strjoin.c\
	libft/ft_strlcpy.c\
	libft/ft_strlen.c\
	libft/ft_strncmp.c\
	libft/ft_strrchr.c\
	libft/ft_substr.c\
	libft/ft_split.c\
	libft/ft_memmove.c\
	libft/ft_strnstr.c\
	libft/ft_tolower.c\
	libft/ft_toupper.c\
	libft/ft_strtrim.c\
	libft/ft_strmapi.c\
	print/ft_strlen.c\
	print/ft_putnbr.c\
	print/ft_putnbr_abs.c\
	print/ft_putstr.c\
	print/ft_putchar.c\
	print/ft_printf.c\
	print/ft_address.c\
	instraction.c\
	stack_sorting.c\
	error_detct.c\
	ft_stack.c\
	push_swap_utils.c\
	sorting_utils.c\
	min_oper_element.c\
	push_place.c

OBJ = $(SRC:.c=.o)

SRC_Bonus = get_next_line/get_next_line_bonus.c\
			get_next_line/get_next_line_utils_bonus.c

OBJ_Bonus = $(SRC_Bonus:.c=.o)

all: $(OBJ)
	ar rc $(NAME) $(OBJ)
	gcc $(CFLAGS) -o push_swap push_swap.c $(NAME)

bonus: $(OBJ) $(OBJ_Bonus)
	ar rc $(NAME) $(OBJ) $(OBJ_Bonus)
	gcc $(CFLAGS) -o checker checker.c $(NAME) 

clean:
	rm -f libft/*.o *.o print/*.o get_next_line/*.o

fclean: clean
	rm -f $(NAME)

re : fclean all

.PONY: clean fclean re
