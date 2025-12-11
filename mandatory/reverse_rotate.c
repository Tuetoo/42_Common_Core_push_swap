/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiezhang <jiezhang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 12:36:07 by jiezhang          #+#    #+#             */
/*   Updated: 2025/12/01 07:33:35 by jiezhang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_stack *a, int mode)
{
	t_node	*node;

	node = pop_back(a);
	if (node)
		push_front(a, node);
	if (mode == 1)
		write(1, "rra\n", 4);
}

void	rrb(t_stack *b, int mode)
{
	t_node	*node;

	node = pop_back(b);
	if (node)
		push_front(b, node);
	if (mode)
		write(1, "rrb\n", 4);
}

void	rrr(t_stack *a, t_stack *b, int mode)
{
	t_node	*node_a;
	t_node	*node_b;

	node_a = pop_back(a);
	node_b = pop_back(b);
	if (node_a)
		push_front(a, node_a);
	if (node_b)
		push_front(b, node_b);
	if (mode == 1)
		write(1, "rrr\n", 4);
}
