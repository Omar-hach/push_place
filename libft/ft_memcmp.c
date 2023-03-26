/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohachami <ohachami@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 19:25:08 by ohachami          #+#    #+#             */
/*   Updated: 2022/10/08 18:55:59 by ohachami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;

	i = 1;
	while (i < n)
	{
		if (*(char *)s1 != *(char *)s2)
			break ;
		s1++;
		s2++;
		i++;
	}
	if (n == 0)
		return (0);
	else
		return (*(unsigned char *)s1 - *(unsigned char *)s2);
}
/*
int main()
{
    char *word = "t\200";
    char *copy = "t\0";

    printf("memcmp :%d \n",memcmp(copy,word,2));
    printf("ft_memcmp :%d \n",ft_memcmp(copy,word,2));
    //form undiffined when you don't deffin copy using the original funcion
    //also problem in this case n > len(s1) && s1 == s2
	//error in this case
}*/
