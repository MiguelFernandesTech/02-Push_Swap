/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migmarti <migmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 14:07:48 by migmarti          #+#    #+#             */
/*   Updated: 2023/04/11 14:31:32 by migmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//Function to start my values at 0;
void	init_stacks(t_stack *s)
{
	s->stack_a = 0;
	s->stack_b = 0;
	s->size_a = 0;
	s->size_b = 0;
	s->i = 0;
	s->j = 0;
}

//Function to print both of my stacks;
void	print_stacks(t_stack *s)
{
	int	i;

	i = 0;
	ft_printf("%s", "stack A :");
	while (i < s->size_a)
	{
		ft_printf("%d ", s->stack_a[i]);
		i++;
	}
	i = 0;
	ft_printf("%s", "stack B :");
	while (i < s->size_b)
	{
		ft_printf("%d ", s->stack_b[i]);
		i++;
	}
}

//Function to get space for my stack and fill it with the numbers i want;
void	fill_stacks(int ac, char **av, t_stack *s)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	s->stack_a = malloc(sizeof(int) * s->size_a);
	s->size_a = ac - 1;
	while (i < s->size_a + 1)
	{
		s->stack_a[j] = ft_atoi(av[i]);
		i++;
		j++;
	}
}

// Sort_2 aqui por falta de espaco
void	sort_2(t_stack *s)
{
	if (s->stack_a[0] > s->stack_a[1])
		sa(s);
}
