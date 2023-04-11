/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migmarti <migmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 08:54:09 by migmarti          #+#    #+#             */
/*   Updated: 2023/04/06 12:17:27 by migmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

//Retorno por referencia, devido a ser tipo void.
//Swap the first 2 elements at the top of stack a
void	sa(t_stack *s)
{
	int	temp;

	if (s->size_a <= 1)
		return ;
	temp = s->stack_a[0];
	s->stack_a[0] = s->stack_a[1];
	s->stack_a[1] = temp;
}

//Swap the first 2 elements at the top of stack b,
void	sb(t_stack *s)
{
	int	temp;

	if (s->size_b <= 1)
		return ;
	temp = s->stack_b[0];
	s->stack_b[0] = s->stack_b[1];
	s->stack_b[1] = temp;
}

//sa and sb at the same time;
void	ss(t_stack *s)
{
	sa(s);
	sb(s);
}
