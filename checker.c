/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohachami <ohachami@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 21:28:21 by ohachami          #+#    #+#             */
/*   Updated: 2023/02/13 21:29:41 by ohachami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"push_swap.h"

void	instraction_error(char *instract, t_stack *stack_a, t_stack *stack_b)
{
	if (ft_strncmp(instract, "sa", 2) && ft_strncmp(instract, "sb", 2)
		&& ft_strncmp(instract, "pb", 2) && ft_strncmp(instract, "pa", 2)
		&& ft_strncmp(instract, "ra", 2) && ft_strncmp(instract, "rb", 2)
		&& ft_strncmp(instract, "rra", 3) && ft_strncmp(instract, "rrb", 3)
		&& ft_strncmp(instract, "rr", 2) && ft_strncmp(instract, "rrr", 3)
		&& ft_strncmp(instract, "ss", 2))
	{
		write(2, "Error\n", 6);
		free(instract);
		free_stack(stack_a);
		free_stack(stack_b);
		exit(1);
	}
}

void	instraction_detect(char *instract, t_stack *stack_a, t_stack *stack_b)
{
	instraction_error(instract, stack_a, stack_b);
	if (!ft_strncmp(instract, "sa\n", 3) || !ft_strncmp(instract, "ss\n", 3))
		swap(stack_a, stack_b);
	if (!ft_strncmp(instract, "sb\n", 3) || !ft_strncmp(instract, "ss\n", 3))
		swap(stack_b, stack_a);
	if (!ft_strncmp(instract, "pb\n", 3))
		push_to(stack_a, stack_b);
	if (!ft_strncmp(instract, "pa\n", 3))
		push_to(stack_b, stack_a);
	if (!ft_strncmp(instract, "ra\n", 3) || !ft_strncmp(instract, "rr\n", 3))
		rotate(stack_a, stack_b);
	if (!ft_strncmp(instract, "rb\n", 3) || !ft_strncmp(instract, "rr\n", 3))
		rotate(stack_b, stack_a);
	if (!ft_strncmp(instract, "rra\n", 4) || !ft_strncmp(instract, "rrr\n", 4))
		reverse_rotate(stack_a, stack_b);
	if (!ft_strncmp(instract, "rrb\n", 4) || !ft_strncmp(instract, "rrr\n", 4))
		reverse_rotate(stack_b, stack_a);
}

void	read_instraction(t_stack *stack_a, t_stack *stack_b)
{
	char	*instract;

	instract = get_next_line(0);
	while (instract)
	{
		instraction_detect(instract, stack_a, stack_b);
		free(instract);
		instract = get_next_line(0);
	}
	if (stack_b->top == -1 && stack_is_sorted(stack_a))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}

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
	read_instraction(stack_a, stack_b);
	free_stack(stack_a);
	free_stack(stack_b);
}
