/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migmarti <migmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 08:58:12 by migmarti          #+#    #+#             */
/*   Updated: 2023/04/13 11:45:18 by migmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//Function to reallocate memory;
int	*ft_memalloc(int size)
{
	int	*alloc;

	alloc = (int *) malloc(sizeof(int) * size);
	if (!alloc)
		exit(1);
	return (alloc);
}

//Function to verify the if the strings is only numbers;
int	is_number(char c)
{
	if (c < '0' || c > '9')
		return (0);
	return (1);
}

//Verification if we have doubles;
int	dups_verification(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = i + 1;
		while (j < argc)
		{
			if (atoi(argv[i]) == atoi(argv[j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

//Function to be only numbers;
int	verify_nums(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
		{
			if(j == 0)
				if(argv[i][j] == '-')
					j++;
			if (!is_number(argv[i][j]))
				return (0);
			j++;
		}
		if (ft_atol(argv[i]) > INT_MAX || ft_atol(argv[i]) < INT_MIN)
			return (0);
		j = 0;
		i++;
	}
	/* i = 1;
	while (i < argc)
	{
		if (ft_atol(argv[i]) > INT_MAX || ft_atol(argv[i]) < INT_MIN)
			return (0);
		i++;
	} */
	return (1);
}

// Basically atoi for longs;
long	ft_atol(const char *str)
{
	int		i;
	int		sign;
	long	res;

	sign = 1;
	i = 0;
	res = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-')
		sign = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] != '\0')
	{
		if (ft_isdigit(str[i]))
		{
			res *= 10;
			res += str[i] - '0';
		}
		i++;
	}
	return (sign * res);
}
