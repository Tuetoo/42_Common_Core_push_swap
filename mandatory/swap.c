/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiezhang <jiezhang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 11:13:11 by jiezhang          #+#    #+#             */
/*   Updated: 2025/12/01 07:31:32 by jiezhang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(t_stack *stack)
{
	t_node	*first;
	t_node	*second;

	if (stack->size < 2)
		return ;
	first = stack->top;
	second = first->next;
	if (!second)
		return ;
	first->next = second->next;
	second->next = first;
	stack->top = second;
	if (stack->size == 2)
		stack->bottom = first;
}

void	sa(t_stack *a, int mode)
{
	swap(a);
	if (mode == 1)
		write(1, "sa\n", 3);
}

void	sb(t_stack *b, int mode)
{
	swap(b);
	if (mode == 1)
		write(1, "sb\n", 3);
}

void	ss(t_stack *a, t_stack *b, int mode)
{
	swap(a);
	swap(b);
	if (mode == 1)
		write(1, "ss\n", 3);
}
