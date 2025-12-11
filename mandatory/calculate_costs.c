/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_costs.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiezhang <jiezhang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 07:46:47 by jiezhang          #+#    #+#             */
/*   Updated: 2025/11/28 16:10:48 by jiezhang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_insert_pos(t_stack *a, int b_index)
{
	t_node	*node;
	int		pos;
	int		min_index;

	node = a->top;
	pos = -1;
	min_index = -1;
	while (node)
	{
		if (node->index > b_index)
		{
			if (min_index == -1 || node->index < min_index)
			{
				min_index = node->index;
				pos = node->pos;
			}
		}
		node = node->next;
	}
	if (pos == -1)
		pos = find_min_pos(a);
	return (pos);
}

void	calculate_costs(t_stack *a, t_stack *b)
{
	t_node		*node;

	update_positions(a);
	update_positions(b);
	node = b->top;
	while (node)
	{
		node->target_pos = find_insert_pos(a, node->index);
		if (node->pos <= b->size / 2)
			node->cost_b = node->pos;
		else
			node->cost_b = node->pos - b->size;
		if (node->target_pos <= a->size / 2)
			node->cost_a = node->target_pos;
		else
			node->cost_a = node->target_pos - a->size;
		node = node->next;
	}
}

t_node	*get_cheapest_node(t_stack *b)
{
	t_node	*node;
	t_node	*cheapest;
	int		min_cost;
	int		total_cost;

	node = b->top;
	min_cost = INT_MAX;
	cheapest = NULL;
	while (node)
	{
		if (node->cost_a * node->cost_b > 0)
			total_cost = max(ft_abs(node->cost_a), ft_abs(node->cost_b));
		else
			total_cost = ft_abs(node->cost_a) + ft_abs(node->cost_b);
		if (total_cost < min_cost)
		{
			min_cost = total_cost;
			cheapest = node;
		}
		node = node->next;
	}
	return (cheapest);
}
