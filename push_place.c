/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_place.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohachami <ohachami@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 14:34:57 by ohachami          #+#    #+#             */
/*   Updated: 2023/02/20 14:35:41 by ohachami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"push_swap.h"

void	suite_b_t_a(t_stack *stack_b, t_stack *stack_a, int min_i, int min_j)
{
	if (min_i <= (stack_b->top - 1) / 2 && min_j <= (stack_a->top + 1) / 2)
	{
		while (min_i > -1 || min_j > 0)
		{
			if (min_i > -1 && min_j > 0)
				instraction("rrr", stack_a, stack_b);
			else if (min_j > 0)
				instraction("rra", stack_a, stack_b);
			else if (min_i > -1)
				instraction("rrb", stack_a, stack_b);
			min_i--;
			min_j--;
		}
	}
	else
	{
		while (min_i++ < stack_b->top)
			instraction("rb", stack_a, stack_b);
		while (min_j-- > 0)
			instraction("rra", stack_a, stack_b);
	}
}

void	push_b_t_a(t_stack *stack_b, t_stack *stack_a, int min_i, int min_j)
{
	if (min_i > (stack_b->top - 1) / 2 && min_j > (stack_a->top + 1) / 2)
	{
		while (min_i < stack_b->top || min_j < stack_a->top + 1)
		{
			if (min_i < stack_b->top && min_j < stack_a->top + 1)
				instraction("rr", stack_a, stack_b);
			else if (min_j < stack_a->top + 1)
				instraction("ra", stack_a, stack_b);
			else if (min_i < stack_b->top)
				instraction("rb", stack_a, stack_b);
			min_i++;
			min_j++;
		}
	}
	else if (min_i <= (stack_b->top - 1) / 2 && min_j > (stack_a->top + 1) / 2)
	{
		while (min_j++ < stack_a->top + 1)
			instraction("ra", stack_a, stack_b);
		while (min_i-- > 0)
			instraction("rrb", stack_a, stack_b);
	}
	else
		suite_b_t_a(stack_b, stack_a, min_i, min_j);
	instraction("pa", stack_a, stack_b);
}

void	suite_cond(t_stack *stack_b, t_stack *stack_a, int min_i, int min_j)
{
	if (min_i <= (stack_a->top - 1) / 2 && min_j <= (stack_b->top + 1) / 2)
	{
		while (min_i > -1 || min_j > 0)
		{
			if (min_i > -1 && min_j > 0)
				instraction("rrr", stack_a, stack_b);
			else if (min_j > 0)
				instraction("rrb", stack_a, stack_b);
			else if (min_i > -1)
				instraction("rra", stack_a, stack_b);
			min_i--;
			min_j--;
		}
	}
	else
	{
		while (min_i++ < stack_a->top)
			instraction("ra", stack_a, stack_b);
		while (min_j-- > 0)
			instraction("rrb", stack_a, stack_b);
	}
}

void	push_place(t_stack *stack_a, t_stack *stack_b, int min_i, int min_j)
{
	if (min_i > (stack_a->top - 1) / 2 && min_j > (stack_b->top + 1) / 2)
	{
		while (min_i < stack_a->top || min_j < stack_b->top + 1)
		{
			if (min_i < stack_a->top && min_j < stack_b->top + 1)
				instraction("rr", stack_a, stack_b);
			else if (min_j < stack_b->top + 1)
				instraction("rb", stack_a, stack_b);
			else if (min_i < stack_a->top)
				instraction("ra", stack_a, stack_b);
			min_i++;
			min_j++;
		}
	}
	else if (min_i <= (stack_a->top - 1) / 2 && min_j > (stack_b->top + 1) / 2)
	{
		while (min_j++ < stack_b->top + 1)
			instraction("rb", stack_a, stack_b);
		while (min_i-- > -1)
			instraction("rra", stack_a, stack_b);
	}
	else
		suite_cond(stack_b, stack_a, min_i, min_j);
	instraction("pb", stack_a, stack_b);
}
