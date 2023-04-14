/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migmarti <migmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 11:25:04 by migmarti          #+#    #+#             */
/*   Updated: 2023/04/14 15:10:40 by migmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* void	sort_3(t_stack *s)
{
	max_min_val(s);
	if (!check_order_asc(s))
	{
		if (s->stack_a[0] > s->stack_a[1] && s->stack_a[0] < s->stack_a[2])
			sa(s);
		else if (s->stack_a[0] > s->stack_a[1] && s->stack_a[0] > s->stack_a[2])
			ra(s);
		else if (s->stack_a[0] < s->stack_a[1] && s->stack_a[0] < s->stack_a[2])
			rra(s);
		sort_3(s);
		return ;
	}
} */

void	sort_3(t_stack *s)
{
	max_min_val(s);
	if (s->stack_a[1] == s->min && s->stack_a[2] == s->max)
		sa(s);
	else if (s->stack_a[0] == s->max && s->stack_a[2] == s->min)
	{
		sa(s);
		rra(s);
	}
	else if (s->stack_a[0] == s->max && s->stack_a[1] == s->min)
		ra(s);
	else if (s->stack_a[0] == s->min && s->stack_a[1] == s->max)
	{
		sa(s);
		ra(s);
	}
	else if (s->stack_a[1] == s->max && s->stack_a[2] == s->min)
		rra(s);
}

//final moves for sort_5
void	final_sort5(t_stack *s)
{
	if (!check_order_asc(s))
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
}

void	sort_5(t_stack *s)
{
	max_min_val(s);
	if (!check_order_asc(s))
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
	int	max_bits;
	int	i;
	int	j;

	size = s->size_a;
	max_bits = 0;
	indexing(s);
	max_min_val(s);
	i = 0;
	while ((s->max >> max_bits) != 0)
		max_bits++;
	while (i < max_bits && (!check_order_asc(s)) && s->size_a)
	{
		size = s->size_a;
		j = 0;
		while (j < size && (!check_order_asc(s)) && s->size_a)
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

	if (check_order_des(s->stack_b, s->size_b) && (check_order_asc(s)))
	{
		while (s->size_b > 0)
			pa(s);
		return ;
	}
	size = s->size_b;
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
