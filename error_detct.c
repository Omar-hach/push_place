/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_detct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohachami <ohachami@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 17:38:18 by ohachami          #+#    #+#             */
/*   Updated: 2023/01/13 17:39:43 by ohachami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"push_swap.h"

int	off_limit(char *number, int j)
{
	int		i;
	char	sign;

	i = 0;
	sign = *number;
	if (!(!j && *number != ' ')
		&& !(j && (number[-1] == ' ' && *number != ' ')))
		return (0);
	number += (*number == '-' || *number == '+');
	j = 0;
	while (number[j] == '0')
		j++;
	while (number[i + j] && number[i + j] != ' ')
		i++;
	if (i < 10 || (!ft_strncmp(number + j, "2147483648", 10) && sign == '-'))
		return (0);
	else if (i == 10)
	{
		i = 0;
		while (number[i + j] == "2147483648"[i] && i < 11)
			i++;
		if (number[i + j] < "2147483648"[i])
			return (0);
	}
	return (1);
}

int	int_chek(char *word)
{
	int	digit;
	int	i;

	digit = 0;
	i = -1;
	if (!*word)
		return (1);
	while (word[++i])
	{
		if (ft_strlen(word + i) > 8 && off_limit(word + i, i))
			return (1);
		if ((word[i] == '-' || word[i] == '+'))
			i++;
		if ((word[i] < '0' || word[i] > '9') && word[i] != ' ')
			return (1);
		if (word[i] != ' ' && (word[i + 1] == '+' || word[i + 1] == '-'))
			return (1);
		if (word[i] != ' ')
			digit++;
	}
	return (!digit);
}

void	error_detct(int argc, char **argv)
{
	int	i;

	i = 0;
	while (++i < argc)
	{
		if (int_chek(argv[i]))
		{
			write(2, "Error\n", 6);
			exit(1);
		}
	}
}
// if zero is the first arg error
