/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiezhang <jiezhang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 16:30:33 by jiezhang          #+#    #+#             */
/*   Updated: 2025/11/28 18:00:51 by jiezhang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	stack_to_array(t_stack *a, int *array)
{
	int		i;
	t_node	*tmp;

	tmp = a->top;
	i = 0;
	while (tmp)
	{
		array[i] = tmp->value;
		tmp = tmp->next;
		i++;
	}
}

static void	sort_array(int *array, int size)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while (i < size - 1)
	{
		j = i + 1;
		while (j < size)
		{
			if (array[i] > array[j])
			{
				tmp = array[i];
				array[i] = array[j];
				array[j] = tmp;
			}
			j++;
		}
		i++;
	}
}

static void	assign_index(t_stack *a, int *array, int size)
{
	t_node	*tmp;
	int		i;

	tmp = a->top;
	while (tmp)
	{
		i = 0;
		while (i < size)
		{
			if (tmp->value == array[i])
			{
				tmp->index = i;
				break ;
			}
			i++;
		}
		tmp = tmp->next;
	}
}

void	index_stack(t_stack *a)
{
	int	*array;

	array = malloc(sizeof(int) *(a->size));
	if (!array)
		return ;
	stack_to_array(a, array);
	sort_array(array, a->size);
	assign_index(a, array, a->size);
	free(array);
}
