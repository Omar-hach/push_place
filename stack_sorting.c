/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_sorting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohachami <ohachami@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 16:09:29 by ohachami          #+#    #+#             */
/*   Updated: 2023/01/10 16:10:28 by ohachami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"push_swap.h"

void	push_2(t_stack *stack_a, t_stack *stack_b)
{
	instraction("pb", stack_a, stack_b);
	instraction("pb", stack_a, stack_b);
	instraction("pb", stack_a, stack_b);
	stack_min_maj(stack_b);
	if (stack_b->min_index == 2)
		instraction("rb", stack_a, stack_b);
	if (stack_b->min_index == 1)
		instraction("rrb", stack_a, stack_b);
	stack_min_maj(stack_b);
	if (stack_b->maj_index != 2)
		instraction("sb", stack_a, stack_b);
}

void	arrange_stack(t_stack *stack_a, t_stack *stack_b)
{
	stack_min_maj(stack_a);
	while (--stack_a->maj_index > -1
		&& stack_a->maj_index <= (stack_a->top - 1) / 2)
		instraction("rra", stack_a, stack_b);
	while (stack_a->maj_index++ < stack_a->top
		&& stack_a->maj_index > (stack_a->top - 1) / 2)
		instraction("ra", stack_a, stack_b);
}

void	stack_sorting(t_stack *stack_a, t_stack *stack_b)
{
	int	i;
	int	min;

	i = 0;
	min = 0;
	if (stack_a->top < 1 || stack_is_sorted(stack_a))
		return ;
	else if (stack_a->top < 5)
		sort_under_5(stack_a, stack_b);
	else
	{
		push_2(stack_a, stack_b);
		while (stack_a->top > 2)
		{
			min = min_oper_element(stack_a, stack_b, &i);
			push_place(stack_a, stack_b, min, i);
		}
		sort_3(stack_a, stack_b);
		while (stack_b->top > -1)
		{
			min = min_oper_element(stack_b, stack_a, &i);
			push_b_t_a(stack_b, stack_a, min, i);
		}
		arrange_stack(stack_a, stack_b);
	}
}
