/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohachami <ohachami@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 13:25:34 by ohachami          #+#    #+#             */
/*   Updated: 2023/02/20 13:27:53 by ohachami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"push_swap.h"

void	stack_min_maj(t_stack *stack)
{
	int	i;

	i = 0;
	stack->min_index = 0;
	stack->maj_index = 0;
	while (i < stack->top + 1)
	{
		if (stack->list[stack->maj_index] < stack->list[i])
			stack->maj_index = i;
		if (stack->list[stack->min_index] > stack->list[i])
			stack->min_index = i;
		i++;
	}
}

int	stack_is_sorted(t_stack *stack)
{
	int	i;

	i = 0;
	while (i < stack->top && stack->list[i] >= stack->list[i + 1])
		i++;
	return (i == stack->top);
}

void	sort_3(t_stack *stack_a, t_stack *stack_b)
{
	stack_min_maj(stack_a);
	if (stack_a->maj_index == 2)
		instraction("ra", stack_a, stack_b);
	if (stack_a->maj_index == 1)
		instraction("rra", stack_a, stack_b);
	if (!stack_is_sorted(stack_a))
		instraction("sa", stack_a, stack_b);
}

void	sort_4(t_stack *stack_a, t_stack *stack_b)
{
	stack_min_maj(stack_a);
	while (stack_a->min_index > 1 && stack_a->min_index++ < 4)
		instraction("ra", stack_a, stack_b);
	stack_min_maj(stack_a);
	while (stack_a->min_index < 2 && stack_a->min_index-- > -1)
		instraction("rra", stack_a, stack_b);
	instraction("pb", stack_a, stack_b);
	sort_3(stack_a, stack_b);
	instraction("pa", stack_a, stack_b);
}

void	sort_under_5(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->top < 2)
		instraction("sa", stack_a, stack_b);
	else if (stack_a->top < 3)
		sort_3(stack_a, stack_b);
	else if (stack_a->top < 4)
		sort_4(stack_a, stack_b);
	else
	{
		stack_min_maj(stack_a);
		while (stack_a->min_index > 1 && stack_a->min_index++ < 4)
			instraction("ra", stack_a, stack_b);
		stack_min_maj(stack_a);
		while (stack_a->min_index < 2 && stack_a->min_index-- > -1)
			instraction("rra", stack_a, stack_b);
		instraction("pb", stack_a, stack_b);
		sort_4(stack_a, stack_b);
		instraction("pa", stack_a, stack_b);
	}
}
