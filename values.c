/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   values.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migmarti <migmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 10:41:47 by migmarti          #+#    #+#             */
/*   Updated: 2023/04/12 17:27:23 by migmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//Function to check asceding order;
int	check_order_asc(t_stack *s)
{
	int	check;
	int	i;

	i = s->size_a - 1;
	check = 0;
	while (i > 0)
	{
		// printf("%d\n", stack[i]);
		if (s->stack_a[i] > s->stack_a[i - 1])
			i--;
		else
			return (check);
	}
	check += 1;
	return (check);
}

//Function to check desceding order;
int	check_order_des(int *stack, int size)
{
	int	check;
	int	i;

	i = size - 1;
	check = 0;
	while (i > 0)
	{
		if (stack[i] < stack[i - 1])
			i--;
		else
			return (check);
	}
	check += 1;
	return (check);
}

//Function to convert into index to deal with negative;
void	converter(t_stack *s, int *temp)
{
	int	i;
	int	j;

	//temp = malloc(sizeof(int) * s->size_a);
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

void	indexing(t_stack *stack)
{
	int	*temp;
	int	i;
	int	tempo;

	i = 0;
	temp = ft_calloc(stack->size_a, sizeof(int));
	if (!temp)
		return ;
	temp = ft_memcpy(temp, stack->stack_a, sizeof(int) * stack->size_a);
	while (i < (stack->size_a - 1))
	{
		if (temp[i] > temp[i + 1])
		{
			tempo = temp[i];
			temp[i] = temp [i + 1];
			temp [i + 1] = tempo;
			i = 0;
		}
		else
			i++;
	}
	indexing(stack, temp);
	free (temp);
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
		if (s->min > s->stack_a[s->i])
			s->min = s->stack_a[s->i];
		s->i++;
	}
}
