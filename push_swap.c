/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migmarti <migmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 08:54:46 by migmarti          #+#    #+#             */
/*   Updated: 2023/04/12 17:23:48 by migmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stack	*s;

	s = malloc(sizeof(t_stack));
	init_stacks(s);
	s->size_a = ac - 1;
	if (verify_args(ac, av))
		fill_stacks(ac, av, s);
	if (s->size_a == 2)
		sort_2(s);
	else if (s->size_a == 3)
		sort_3(s);
	else if (s->size_a == 5)
		sort_5(s);
	else if (!check_order_asc(s))
		sorting_bits(s);
	return (0);
}
