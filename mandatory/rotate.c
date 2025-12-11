/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiezhang <jiezhang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 12:26:28 by jiezhang          #+#    #+#             */
/*   Updated: 2025/12/01 07:32:41 by jiezhang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack *a, int mode)
{
	t_node	*node;

	node = pop_front(a);
	if (node)
		push_back(a, node);
	if (mode == 1)
		write(1, "ra\n", 3);
}

void	rb(t_stack *b, int mode)
{
	t_node	*node;

	node = pop_front(b);
	if (node)
		push_back(b, node);
	if (mode == 1)
		write(1, "rb\n", 3);
}

void	rr(t_stack *a, t_stack *b, int mode)
{
	t_node	*node_a;
	t_node	*node_b;

	node_a = pop_front(a);
	node_b = pop_front(b);
	if (node_a)
		push_back(a, node_a);
	if (node_b)
		push_back(b, node_b);
	if (mode == 1)
		write(1, "rr\n", 3);
}
