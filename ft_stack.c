/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohachami <ohachami@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 00:34:32 by ohachami          #+#    #+#             */
/*   Updated: 2023/01/19 00:35:42 by ohachami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"push_swap.h"

t_stack	*create_stack(t_stack *stack, int max)
{
	stack = (t_stack *)ft_calloc(1, sizeof(t_stack));
	if (!stack)
		exit(1);
	stack->top = -1;
	stack->min_index = 0;
	stack->maj_index = 0;
	stack->max = max;
	stack->list = (int *)ft_calloc(max, sizeof(int));
	if (!stack->list)
		exit(1);
	return (stack);
}

int	push(t_stack *stack, int element)
{
	if (stack->top == stack->max)
		return (stack->list[stack->top]);
	stack->top++;
	stack->list[stack->top] = element;
	return (stack->list[stack->top]);
}

int	pop(t_stack *stack)
{
	int	elem;

	if (stack->top == -1)
		return (0);
	elem = stack->list[stack->top];
	stack->top--;
	return (elem);
}
