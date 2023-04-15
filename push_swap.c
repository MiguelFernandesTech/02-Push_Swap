/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migmarti <migmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 08:54:46 by migmarti          #+#    #+#             */
/*   Updated: 2023/04/15 15:31:32 by migmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stack	*s;
	int		i;

	i = 0;
	s = malloc(sizeof(t_stack));
	init_stacks(s);
	s->size_a = ac - 1;
	if (optimal_verify(ac, av, s))
		fill_stacks(ac, av, s);
	if (check_order_asc(s))
		specialfree(s);
	if (s->size_a == 2)
		sort_2(s);
	else if (s->size_a == 3)
		sort_3(s);
	else if (s->size_a == 5)
		sort_5(s);
	else if (!check_order_asc(s))
		sorting_bits(s, i);
	free(s->stack_a);
	free(s->stack_b);
	free(s);
}
