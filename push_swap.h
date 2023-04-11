/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migmarti <migmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 08:54:42 by migmarti          #+#    #+#             */
/*   Updated: 2023/04/06 12:19:48 by migmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./libft/libft.h"
# include <stdio.h>
# include <limits.h>
# include <stdlib.h>
# include <stddef.h>

typedef struct t_stack
{
	int	*stack_a;
	int	*stack_b;
	int	size_a;
	int	size_b;
	int	i;
	int	j;
	int	max;
	int	min;
	int	med;
}		t_stack;

// ***** UTILS ***** //
int		*ft_memalloc(int size);
int		is_number(char c);
int		verification(int argc, char **argv);
long	ft_atol(const char *str);
int		verify_args(int argc, char **argv);
// ***** UTILS2 ***** //
void	init_stacks(t_stack *s);
void	fill_stacks(int ac, char **av, t_stack *s);
void	print_stacks(t_stack *s);
// ****** SWAP ******* //
void	sa(t_stack *s);
void	sb(t_stack *s);
void	ss(t_stack *s);
// ****** ROTATE ***** //
void	ra(t_stack *s);
void	rb(t_stack *s);
void	rr(t_stack *s);
// ***** REVERSE ***** //
void	rra(t_stack *s);
void	rrb(t_stack *s);
void	rrr(t_stack *s);
// ****** PUSH ******* //
void	pa(t_stack *s);
void	pb(t_stack *s);
// ****** SORT ****** //
void	sort_2(t_stack *s);
void	sort_3(t_stack *s);
void	final_sort5(t_stack *s);
void	sort_5(t_stack *s);
void	sorting_bits(t_stack *s);
void	sort_b(t_stack *s);
// ****** VALUES **** //
int		check_order(t_stack *s);
void	indexing(t_stack *s, int *temp);
void	max_min_val(t_stack *s);
#endif
