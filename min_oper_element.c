/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   min_oper_element.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohachami <ohachami@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 13:29:53 by ohachami          #+#    #+#             */
/*   Updated: 2023/02/20 13:30:11 by ohachami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"push_swap.h"

int	place_in_b(t_stack *stack, int number, int i)
{
	while (number > stack->list[i] && i <= stack->top)
			i++;
	if (i > stack->top)
		i = i * (number < stack->list[0]);
	while (i <= stack->maj_index && number > stack->list[i])
		i++;
	i = i + (i == stack->maj_index && number > stack->list[i]);
	return (i);
}

int	find_place(t_stack *stack, int number, int i, int j)
{
	j = stack->maj_index - stack->min_index;
	i = stack->min_index;
	if ((stack->maj_index > stack->min_index && j * j < 2)
		|| (j * j > 1 && stack->min_index))
	{
		while (i >= 0 && number > stack->list[i])
			i--;
		if (i < 0)
			i = stack->top + (number < stack->list[stack->top]);
		else
			i++;
		while (i > stack->maj_index
			&& number > stack->list[i - 1] && i <= stack->top)
			i--;
	}
	else
		i = place_in_b(stack, number, i);
	if (!i)
		return (stack->top + 1);
	return (i);
}

int	opr_calcul(int i, int k, t_stack *stack_a, t_stack *stack_b)
{
	int	opr;

	if (i > (stack_a->top - 1) / 2 && k > (stack_b->top + 1) / 2)
	{
		if ((stack_a->top - i) > (stack_b->top + 1 - k))
			opr = stack_a->top - i;
		else
			opr = stack_b->top + 1 - k;
	}
	else if (i <= (stack_a->top - 1) / 2 && k <= (stack_b->top + 1) / 2)
	{
		if ((1 + i) > k)
			opr = i + 1;
		else
			opr = k;
	}
	else if (i <= (stack_a->top - 1) / 2 && k > (stack_b->top + 1) / 2)
		opr = stack_b->top + 1 - k + i + 1;
	else
		opr = k + stack_a->top - i;
	return (opr);
}

int	min_oper_element(t_stack *stack_a, t_stack *stack_b, int *j)
{
	int	i;
	int	k;
	int	opr;
	int	min;
	int	elem_min;

	i = stack_a->top + 1;
	min = stack_a->top + stack_b->top;
	stack_min_maj(stack_b);
	while (i--)
	{
		k = find_place(stack_b, stack_a->list[i], i, k);
		opr = opr_calcul(i, k, stack_a, stack_b);
		if (min > opr)
		{
			min = opr;
			elem_min = i;
			*j = k;
		}
	}
	return (elem_min);
}
