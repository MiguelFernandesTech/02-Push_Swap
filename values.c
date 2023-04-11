/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   values.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migmarti <migmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 10:41:47 by migmarti          #+#    #+#             */
/*   Updated: 2023/04/06 12:23:15 by migmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//Function to check order;
int	check_order(t_stack *s)
{
	int	check;
	int		i;

	i = s->size_a - 1;
	check = 0;
	while (i > 0)
	{
		if (s->stack_a[i] > s->stack_a[i - 1])
			i--;
		else
			return (check);
	}
	check += 1;
	return (check);
}
//Function to convert into index to deal with negative;
void	indexing(t_stack *s, int *temp)
{
	int	i;
	int	j;

	i = 0;
	
	while (i < s->size_a)
	{
		j = 0;
		while (j < s->size_a)
		{
			if (s->stack_a[i] == temp[j])
			{
				s->stack_a[i] = j;
				break ;
			}
			j++;
		}
		i++;
	}
}

//Function to check the highest and lowest number in stack A
void	max_min_val(t_stack *s)
{
	s->i = 0;
	s->max = s->stack_a[0];
	while (s->i < s->size_a)
	{
		if (s->max < s->stack_a[s->i])
			s->max = s->stack_a[s->i];
		s->i++;
	}
	s->i = 0;
	s->min = s->stack_a[0];
	while (s->i < s->size_a)
	{
		if(s->min < s->stack_a[s->i])
			s->min = s->stack_a[s->i];
		s->i++;
	}
}

