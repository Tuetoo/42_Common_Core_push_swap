/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiezhang <jiezhang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 11:41:53 by jiezhang          #+#    #+#             */
/*   Updated: 2025/12/01 07:43:28 by jiezhang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_two(t_stack *a)
{
	if (a->top->value > a->bottom->value)
		sa(a, 1);
}

static void	sort_three(t_stack *a)
{
	if (a->top->value > a->top->next->value)
		sa(a, 1);
	if (a->top->next->value > a->bottom->value)
	{
		rra(a, 1);
		if (a->top->value > a->top->next->value)
			sa(a, 1);
	}
}

static void	sort_five(t_stack *a, t_stack *b)
{
	int	pos;
	int	i;

	while (a->size > 3)
	{
		update_positions(a);
		pos = find_min_pos(a);
		if (pos <= a->size / 2)
		{
			while (pos-- > 0)
				ra(a, 1);
		}
		else
		{
			i = a->size - pos;
			while (i-- > 0)
				rra(a, 1);
		}
		pb(a, b, 1);
	}
	sort_three(a);
	while (b->size > 0)
		pa(a, b, 1);
}

void	sort_small(t_stack *a, t_stack *b)
{
	if (a->size == 2)
		sort_two(a);
	else if (a->size == 3)
		sort_three(a);
	else if (a->size <= 5)
		sort_five(a, b);
}
