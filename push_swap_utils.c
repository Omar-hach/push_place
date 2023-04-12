/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohachami <ohachami@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 23:18:52 by ohachami          #+#    #+#             */
/*   Updated: 2023/02/16 23:19:15 by ohachami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"push_swap.h"

void	free_stack(t_stack *stack)
{
	free(stack->list);
	free(stack);
}

int	ft_number_count(int argc, char **argv)
{
	int	i;
	int	j;
	int	count;

	i = -1;
	j = 0;
	count = 0;
	while (++i < argc)
	{
		j = 0;
		while (argv[i][j])
		{
			if ((argv[i][j] >= '0' && argv[i][j] <= '9')
				|| argv[i][j] == '-' || argv[i][j] == '+')
			{
				count++;
				j++;
				while (argv[i][j] >= '0' && argv[i][j] <= '9')
					j++;
			}
			else
				j++;
		}
	}
	return (count);
}

void	ft_duplicate(int *list, int max, t_stack *stack_a, t_stack *stack_b)
{
	int	i;
	int	j;
	int	number;

	i = 1;
	j = 0;
	while (j <= max)
	{
		number = list[j];
		i = j + 1;
		while (i < max)
		{
			if (number == list[i])
			{
				write(2, "Error\n", 6);
				free_stack(stack_a);
				free_stack(stack_b);
				exit(1);
			}
			i++;
		}
		j++;
	}
}

void	char_to_intlist(int argc, char **argv, t_stack *stack)
{
	int	i;
	int	j;

	j = 0;
	i = argc + 1;
	while (--i)
	{
		j = ft_strlen(argv[i]);
		while (j)
		{
			if ((argv[i][j - 1] == ' '
				&& argv[i][j] >= '0' && argv[i][j] <= '9')
				|| argv[i][j] == '+' || argv[i][j] == '-')
				push(stack, ft_atoi(argv[i] + j));
			j--;
		}
		if ((argv[i][j] >= '0' && argv[i][j] <= '9')
			|| argv[i][j] == '+' || argv[i][j] == '-')
			push(stack, ft_atoi(argv[i]));
	}
}
