/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migmarti <migmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 08:54:00 by migmarti          #+#    #+#             */
/*   Updated: 2023/04/11 15:16:45 by migmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

//the last element becomes the first one;
void	rra(t_stack *s)
{
	int	begin;

	begin = s->stack_a[s->size_a - 1];
	s->i = s->size_a - 1;
	while (s->i > 0)
	{
		s->stack_a[s->i] = s->stack_a[s->i - 1];
		s->i--;
	}
	s->stack_a[0] = begin;
	printf("rra\n");
}

//the last element becomes the first one;
void	rrb(t_stack *s)
{
	int	begin;

	begin = s->stack_b[s->size_b - 1];
	s->i = s->size_b - 1;
	while (s->i > 0)
	{
		s->stack_b[s->i] = s->stack_b[s->i - 1];
		s->i--;
	}
	s->stack_a[0] = begin;
	printf("rrb\n");
}

//rra and rrb at the same time;
void	rrr(t_stack *s)
{
	rra(s);
	rrb(s);
}
