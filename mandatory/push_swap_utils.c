/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiezhang <jiezhang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 10:09:38 by jiezhang          #+#    #+#             */
/*   Updated: 2025/12/01 07:54:08 by jiezhang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_abs(int value)
{
	if (value < 0)
		return (-value);
	return (value);
}

int	max(int a, int b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

int	find_min_pos(t_stack *a)
{
	t_node	*node;
	int		min_pos;
	int		min_value;

	node = a->top;
	min_pos = node->pos;
	min_value = INT_MAX;
	while (node)
	{
		if (node->value < min_value)
		{
			min_value = node->value;
			min_pos = node->pos;
		}
		node = node->next;
	}
	return (min_pos);
}

void	update_positions(t_stack *stack)
{
	t_node	*node;
	int		i;

	i = 0;
	node = stack->top;
	while (node)
	{
		node->pos = i;
		node = node->next;
		i++;
	}
}
