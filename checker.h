/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohachami <ohachami@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 23:12:08 by ohachami          #+#    #+#             */
/*   Updated: 2023/04/12 23:12:22 by ohachami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H
# include "libft/libft.h"
# include "libft/print/ft_printf.h"

typedef struct s_stack
{
	int		top;
	int		min_index;
	int		maj_index;
	int		max;
	int		*list;
}t_stack;

void	instraction(char *opr, t_stack *stack_a, t_stack *stack_b);
void	stack_sorting(t_stack *stack_a, t_stack *stack_b);
void	error_detct(int argc, char **argv);
int		stack_is_sorted(t_stack *stack);
void	stack_min_maj(t_stack *stack);
int		pop(t_stack *stack);
int		push(t_stack *stack, int element);
t_stack	*insert(t_stack *stack, char **list, int len);
t_stack	*create_stack(t_stack *stack, int max);
int		ft_number_count(int argc, char **argv);
void	ft_duplicate(int *list, int max, t_stack *stack_a, t_stack *stack_b);
void	char_to_intlist(int argc, char **argv, t_stack *stack);
void	free_stack(t_stack *stack);
void	push_to(t_stack *stack_1, t_stack *stack_2);
void	swap(t_stack *stack_1, t_stack *stack_2);
void	rotate(t_stack *stack_1, t_stack *stack_2);
void	reverse_rotate(t_stack *stack_1, t_stack *stack_2);
void	sort_3(t_stack *stack_a, t_stack *stack_b);
void	sort_under_5(t_stack *stack_a, t_stack *stack_b);
void	push_b_t_a(t_stack *stack_b, t_stack *stack_a, int min_i, int min_j);
void	push_place(t_stack *stack_a, t_stack *stack_b, int min_i, int min_j);
int		min_oper_element(t_stack *stack_a, t_stack *stack_b, int *j);
char	*get_next_line(int fd);
int		find_place(t_stack *stack, int number, int i, int j);

#endif
