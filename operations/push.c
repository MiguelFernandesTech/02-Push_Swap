/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migmarti <migmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 10:09:52 by migmarti          #+#    #+#             */
/*   Updated: 2023/04/14 10:30:03 by migmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

//Take the first element at the top of b and put it as the top of a;
//loop to copy the remaining elements of "temp_a" into the new stack A;
void	pa(t_stack *s)
{
	int	*temp_a;
	int	*temp_b;

	if (s->size_b < 1)
		return ;
	temp_a = ft_memalloc(s->size_a);
	temp_b = ft_memalloc(s->size_b);
	temp_a = ft_memcpy(temp_a, s->stack_a, sizeof(int) * s->size_a);
	temp_b = ft_memcpy(temp_b, s->stack_b, sizeof(int) * s->size_b);
	free(s->stack_a);
	free(s->stack_b);
	s->size_b -= 1;
	s->size_a += 1;
	s->stack_a = ft_memalloc(s->size_a);
	s->stack_b = ft_memalloc(s->size_b);
	s->stack_b = ft_memcpy(s->stack_b, temp_b + 1, sizeof(int) * s->size_b);
	s->i = 1;
	s->j = 0;
	s->stack_a[0] = temp_b[0];
	while (s->i < s->size_a)
		s->stack_a[s->i++] = temp_a[s->j++];
	free(temp_a);
	free(temp_b);
	printf("pa\n");
}

//Take the first element at the top of a and put it at the top of b;
//loop to copy the elements of t"temp_b" into the new stack B;
void	pb(t_stack *s)
{
	int	*temp_a;
	int	*temp_b;

	if (s->size_a < 1)
		return ;
	temp_a = ft_memalloc(s->size_a);
	temp_b = ft_memalloc(s->size_b);
	temp_a = ft_memcpy(temp_a, s->stack_a, sizeof(int) * s->size_a);
	temp_b = ft_memcpy(temp_b, s->stack_b, sizeof(int) * s->size_b);
	free(s->stack_a);
	free(s->stack_b);
	s->size_a -= 1;
	s->size_b += 1;
	s->stack_a = ft_memalloc(s->size_a);
	s->stack_b = ft_memalloc(s->size_b);
	s->stack_a = ft_memcpy(s->stack_a, temp_a + 1, sizeof(int) * s->size_a);
	s->i = 1;
	s->j = 0;
	s->stack_b[0] = temp_a[0];
	while (s->i < s->size_b)
		s->stack_b[s->i++] = temp_b[s->j++];
	free(temp_a);
	free(temp_b);
	printf("pb\n");
}
