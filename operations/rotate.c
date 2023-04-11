/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migmarti <migmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 08:54:05 by migmarti          #+#    #+#             */
/*   Updated: 2023/04/11 15:29:05 by migmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

//Shift up all elements of stack a by 1, the first element becomes the last one;
void	ra(t_stack *s)
{
	int	last;
	int	i;

	last = s->stack_a[0];
	i = 0;
	while (i < s->size_a - 1)
	{
		s->stack_a[i] = s->stack_a[i + 1];
		i++;
	}
	s->stack_a[i] = last;
	printf("ra\n");
}

//Shift up all elements of stack b by 1; the first element becomes the last one;
void	rb(t_stack *s)
{
	int	last;
	int	i;

	last = s->stack_b[0];
	i = 0;
	while (i <= s->size_b - 1)
	{
		s->stack_b[i] = s->stack_b[i + 1];
		i++;
	}
	s->stack_b[i] = last;
	printf("rb\n");
}

//rr: ra and rb at the same time;
void	rr(t_stack *s)
{
	ra(s);
	rb(s);
}
