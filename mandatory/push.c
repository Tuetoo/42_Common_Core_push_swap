/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiezhang <jiezhang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 12:17:41 by jiezhang          #+#    #+#             */
/*   Updated: 2025/12/01 07:34:05 by jiezhang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_stack *a, t_stack *b, int mode)
{
	t_node	*node;

	node = pop_front(b);
	if (node)
		push_front(a, node);
	if (mode == 1)
		write(1, "pa\n", 3);
}

void	pb(t_stack *a, t_stack *b, int mode)
{
	t_node	*node;

	node = pop_front(a);
	if (node)
		push_front(b, node);
	if (mode == 1)
		write(1, "pb\n", 3);
}
