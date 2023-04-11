/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migmarti <migmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 11:25:04 by migmarti          #+#    #+#             */
/*   Updated: 2023/04/11 15:14:45 by migmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_3(t_stack *s)
{
	max_min_val(s);
	if (check_order(s) == 0)
	{
		if (s->stack_a[0] > s->stack_a[1] && s->stack_a[0] < s->stack_a[2])
			sa(s);
		else if (s->stack_a[0] > s->stack_a[1] && s->stack_a[0] > s->stack_a[2])
			ra(s);
		else if (s->stack_a[0] < s->stack_a[1] && s->stack_a[0] < s->stack_a[2])
			rra(s);
		return (sort_3(s));
	}
}

//final moves for sort_5
void	final_sort5(t_stack *s)
{
	if (s->stack_b[0] > s->stack_b[1])
	{
		pa(s);
		ra(s);
		pa(s);
	}
	else
	{
		pa(s);
		pa(s);
		ra(s);
	}
}

void	sort_5(t_stack *s)
{
	max_min_val(s);
	if (check_order(s) == 0)
	{
		while (s->size_a != 3)
		{
			if (s->stack_a[0] == s->max || s->stack_a[0] == s->min)
				pb(s);
			else
			{
				if ((s->stack_a[1] == s->max || s->stack_a[1] == s->min)
					|| s->stack_a[2] == s->max || s->stack_a[2] == s->min)
					ra(s);
				else
					rra(s);
			}
		}
	}
	sort_3(s);
	final_sort5(s);
}

//Function to sort by reading bits,
void	sorting_bits(t_stack *s)
{
	int	size;
	int	max_num;
	int	max_bits;
	int i;
	int j;

	size = s->size_a;
	max_num = size - 1;
	max_bits = 0;
	max_min_val(s);
	i = 0;
	while ((s->max >> max_bits) !=0)
		max_bits++;
	while (i < max_bits)
	{
		j = 0;
		while (j < size)
		{
			if (((s->stack_a[0] >> i) & 1) == 1)
				ra(s);
			else
				pb(s);
			j++;
		}
		sort_b(s, i);
		i++;
	}
}

void	sort_b(t_stack *s, int shift)
{
	int	i;
	int	size;


 	size =	s->size_b;
	i = 0;
	while (i < size && s->size_b)
	{
		if ((s->stack_b[0] & (1 << (shift + 1))) == 0)
			rb(s);
		else
			pa(s);
		i++;
	}
}
