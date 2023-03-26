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

int	off_limit(char *number)
{
	int	i;

	i = 0;
	if (*number == '-' && ft_strncmp(number, "-2147483648", 11))
		number++;
	while (number[i] && number[i] != ' ')
		i++;
	if (i < 10 || !ft_strncmp(number, "-2147483648", 11))
		return (0);
	else if (i == 10)
	{
		i = 0;
		while (number[i] == "2147483648"[i] && i < 11)
			i++;
		if (number[i] < "2147483648"[i])
			return (0);
	}
	return (1);
}

int	int_chek(char *word)
{
	int	digit;

	digit = 0;
	if (!*word)
		return (1);
	while (*word)
	{
		if (ft_strlen(word) > 9 && off_limit(word))
			return (1);
		if ((*word == '-' || *word == '+'))
			word++;
		if ((*word < '0' || *word > '9') && *word != ' ')
			return (1);
		if (*word != ' ' && (*(word + 1) == '+' || *(word + 1) == '-'))
			return (1);
		if (*word != ' ')
			digit++;
		word++;
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
