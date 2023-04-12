/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohachami <ohachami@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 20:25:31 by ohachami          #+#    #+#             */
/*   Updated: 2022/12/04 20:25:34 by ohachami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack_b;
	t_stack	*stack_a;

	stack_b = NULL;
	stack_a = NULL;
	if (argc < 2)
		return (0);
	error_detct(argc, argv);
	stack_a = create_stack(stack_a, ft_number_count(argc - 1, argv + 1));
	stack_b = create_stack(stack_b, ft_number_count(argc - 1, argv + 1));
	if (stack_a->max > 0)
	{
		char_to_intlist(argc - 1, argv, stack_a);
		ft_duplicate(stack_a->list, ft_number_count(argc - 1, argv + 1),
			stack_a, stack_b);
	}
	stack_sorting(stack_a, stack_b);
	free_stack(stack_a);
	free_stack(stack_b);
}
