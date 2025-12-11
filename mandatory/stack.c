/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiezhang <jiezhang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 10:39:11 by jiezhang          #+#    #+#             */
/*   Updated: 2025/11/28 16:56:54 by jiezhang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*create_node(int value)
{
	t_node	*node;

	node = malloc(sizeof (t_node));
	if (!node)
		handle_error();
	node->value = value;
	node->index = -1;
	node->lis = 0;
	node->pos = -1;
	node->target_pos = -1;
	node->cost_a = 0;
	node->cost_b = 0;
	node->next = NULL;
	return (node);
}

void	push_front(t_stack *stack, t_node *node)
{
	if (stack->size == 0)
	{
		stack->top = node;
		stack->bottom = node;
	}
	else
	{
		node->next = stack->top;
		stack->top = node;
	}
	stack->size++;
}

void	push_back(t_stack *stack, t_node *node)
{
	if (stack->size == 0)
	{
		stack->top = node;
		stack->bottom = node;
	}
	else
	{
		stack->bottom->next = node;
		stack->bottom = node;
	}
	stack->size++;
}

t_node	*pop_front(t_stack *stack)
{
	t_node	*node;

	if (stack->size == 0)
		return (NULL);
	node = stack->top;
	stack->top = node->next;
	if (stack->top == NULL)
		stack->bottom = NULL;
	node->next = NULL;
	stack->size--;
	return (node);
}

t_node	*pop_back(t_stack *stack)
{
	t_node	*node;
	t_node	*prev_node;

	if (stack->size == 0)
		return (NULL);
	node = stack->bottom;
	if (stack->size == 1)
	{
		stack->top = NULL;
		stack->bottom = NULL;
	}
	else
	{
		prev_node = stack->top;
		while (prev_node->next != stack->bottom)
			prev_node = prev_node->next;
		stack->bottom = prev_node;
		stack->bottom->next = NULL;
	}
	node->next = NULL;
	stack->size--;
	return (node);
}
