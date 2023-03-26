/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instraction.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohachami <ohachami@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 15:45:37 by ohachami          #+#    #+#             */
/*   Updated: 2023/01/10 15:46:29 by ohachami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"push_swap.h"

void	push_to(t_stack *stack_1, t_stack *stack_2)
{
	if (stack_1->top < 0)
		return ;
	push(stack_2, pop(stack_1));
}

void	swap(t_stack *stack_1, t_stack *stack_2)
{
	int		holder;

	if (stack_1->top < 1)
		return ;
	holder = pop(stack_1);
	push_to(stack_1, stack_2);
	push(stack_1, holder);
	push_to(stack_2, stack_1);
}

void	rotate(t_stack *stack_1, t_stack *stack_2)
{
	int		holder;
	int		i;

	if (stack_1->top < 1)
		return ;
	i = stack_1->top;
	holder = pop(stack_1);
	while (stack_1->top > -1)
		push_to(stack_1, stack_2);
	push(stack_1, holder);
	while (i--)
		push_to(stack_2, stack_1);
}

void	reverse_rotate(t_stack *stack_1, t_stack *stack_2)
{
	int		holder;
	int		i;

	if (stack_1->top < 1)
		return ;
	i = stack_1->top;
	while (stack_1->top > 0)
		push_to(stack_1, stack_2);
	holder = pop(stack_1);
	while (i--)
		push_to(stack_2, stack_1);
	push(stack_1, holder);
}

void	instraction(char *opr, t_stack *stack_a, t_stack *stack_b)
{
	if (!ft_strncmp(opr, "sa", 3) || !ft_strncmp(opr, "ss", 3))
		swap(stack_a, stack_b);
	if (!ft_strncmp(opr, "sb", 3) || !ft_strncmp(opr, "ss", 3))
		swap(stack_b, stack_a);
	if (!ft_strncmp(opr, "pb", 3))
		push_to(stack_a, stack_b);
	if (!ft_strncmp(opr, "pa", 3))
		push_to(stack_b, stack_a);
	if (!ft_strncmp(opr, "ra", 3) || !ft_strncmp(opr, "rr", 3))
		rotate(stack_a, stack_b);
	if (!ft_strncmp(opr, "rb", 3) || !ft_strncmp(opr, "rr", 3))
		rotate(stack_b, stack_a);
	if (!ft_strncmp(opr, "rra", 3) || !ft_strncmp(opr, "rrr", 3))
		reverse_rotate(stack_a, stack_b);
	if (!ft_strncmp(opr, "rrb", 3) || !ft_strncmp(opr, "rrr", 3))
		reverse_rotate(stack_b, stack_a);
	ft_printf("%s\n", opr);
}
