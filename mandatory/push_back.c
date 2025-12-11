/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_back.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiezhang <jiezhang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 10:25:35 by jiezhang          #+#    #+#             */
/*   Updated: 2025/12/01 07:45:53 by jiezhang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	exec_n_times(void (*operate)(t_stack *, int), t_stack *stack, int n)
{
	while (n > 0)
	{
		operate(stack, 1);
		n--;
	}
}

static void	execute_move(t_stack *a, t_stack *b, t_node *node)
{
	while (node->cost_a > 0 && node->cost_b > 0)
	{
		rr(a, b, 1);
		node->cost_a--;
		node->cost_b--;
	}
	while (node->cost_a < 0 && node->cost_b < 0)
	{
		rrr(a, b, 1);
		node->cost_a++;
		node->cost_b++;
	}
	if (node->cost_b > 0)
		exec_n_times(rb, b, node->cost_b);
	if (node->cost_b < 0)
		exec_n_times(rrb, b, -node->cost_b);
	if (node->cost_a > 0)
		exec_n_times(ra, a, node->cost_a);
	if (node->cost_a < 0)
		exec_n_times(rra, a, -node->cost_a);
	pa(a, b, 1);
}

void	push_back_and_sort(t_stack *a, t_stack *b)
{
	t_node	*cheapest;
	int		min_pos;

	while (b->size > 0)
	{
		calculate_costs(a, b);
		cheapest = get_cheapest_node(b);
		execute_move(a, b, cheapest);
	}
	update_positions(a);
	min_pos = find_min_pos(a);
	if (min_pos <= a->size / 2)
		exec_n_times(ra, a, min_pos);
	else
		exec_n_times(rra, a, a->size - min_pos);
}
