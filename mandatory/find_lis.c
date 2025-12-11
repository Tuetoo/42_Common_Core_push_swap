/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_lis.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiezhang <jiezhang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 17:41:31 by jiezhang          #+#    #+#             */
/*   Updated: 2025/12/04 11:09:37 by jiezhang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
/* 
static void	init_dp_prev(t_stack *a, int *dp, int *prev, t_node **array)
{
	int			i;
	t_node		*tmp;

	i = 0;
	tmp = a->top;
	while (tmp)
	{
		array[i] = tmp;
		array[i + a->size] = tmp;
		tmp->lis = 0;
		tmp = tmp->next;
		i++;
	}
	i = 0;
	while (i < a->size * 2)
	{
		dp[i] = 1;
		prev[i] = -1;
		i++;
	}
}

static int	get_dp_and_max_end(int *dp, int *prev, t_node **array, int size)
{
	int	i;
	int	j;
	int k;
	int	max_end;
	int	max_len;
	int start;

	i = 0;
	max_end = 0;
	max_len = 1;
	while (i < size * 2)
	{
		j = i - size + 1;
		start = j;
		if (j < 0)
			j = 0;
		while (j < i)
		{
			if (array[j]->index < array[i]->index && dp[j] + 1 > dp[i])
			{
				k = j;
				while (prev[k] != -1)
					k= prev[k];
				if (i - k < size)
				{
					dp[i] = dp[j] + 1;
					prev[i] = j;
				}
			}
			j++;
		}
		if (dp[i] > max_len)
		{
			max_len = dp[i];
			max_end = i;
		}
		i++;
	}
	return (max_end);
}

static void	mark_lis(t_stack *a, int *prev, int max_end, t_node **array)
{
	int		i;
	int		size;

	size = a->size;
	i = max_end;
	while (i != -1)
	{
		array[i % size]->lis = 1;
		i = prev[i];
	}
}

void	find_lis_and_push_non_lis(t_stack *a, t_stack *b)
{
	t_node	**array;
	int	*dp;
	int	*prev;
	int	size;
	int max_end;

	size = a->size;
	array = malloc(sizeof(t_node *) * (size * 2));
	dp = malloc(sizeof(int) * (size * 2));
	prev = malloc(sizeof(int) * (size * 2));
	if (!array || !dp || !prev)
		return (free(array), free(dp), free(prev));
	init_dp_prev(a, dp, prev, array);
	max_end = get_dp_and_max_end(dp, prev, array, size);
	mark_lis(a, prev, max_end, array);
	free(array);
	free(dp);
	free(prev);
	while (size--)
	{
		if (a->top->lis)
			ra(a, 1);
		else
			pb(a, b, 1);
	}
} */

static void	init_dp_prev(t_stack *a, int *dp, int *prev, int *array)
{
	int			i;
	t_node		*tmp;

	i = 0;
	tmp = a->top;
	while (tmp)
	{
		array[i] = tmp->index;
		dp[i] = 1;
		prev[i] = -1;
		tmp->lis = 0;
		tmp = tmp->next;
		i++;
	}
}

static void	get_dp(int *dp, int *prev, int *array, int size)
{
	int	i;
	int	j;

	i = 1;
	while (i < size)
	{
		j = 0;
		while (j < i)
		{
			if (array[j] < array[i] && dp[j] + 1 > dp[i])
			{
				dp[i] = dp[j] + 1;
				prev[i] = j;
			}
			j++;
		}
		i++;
	}
}

static int	get_max_end(int *dp, int size)
{
	int	i;
	int	max_end;
	int	max_len;

	i = 0;
	max_end = 0;
	max_len = dp[0];
	while (i < size)
	{
		if (dp[i] >= max_len)
		{
			max_len = dp[i];
			max_end = i;
		}
		i++;
	}
	return (max_end);
}

static void	mark_lis(t_stack *a, int *prev, int max_end)
{
	t_node	*node;
	int		pos;

	pos = max_end;
	update_positions(a);
	while (pos != -1)
	{
		node = a->top;
		while (node)
		{
			if (node->pos == pos)
			{
				node->lis = 1;
				break ;
			}
			node = node->next;
		}
		pos = prev[pos];
	}
}

void	find_lis_and_push_non_lis(t_stack *a, t_stack *b)
{
	int	*array;
	int	*dp;
	int	*prev;
	int	size;

	size = a->size;
	array = malloc(sizeof(int) * size);
	dp = malloc(sizeof(int) * size);
	prev = malloc(sizeof(int) * size);
	if (!array || !dp || !prev)
		return (free(array), free(dp), free(prev));
	update_positions(a);
	init_dp_prev(a, dp, prev, array);
	get_dp(dp, prev, array, size);
	mark_lis(a, prev, get_max_end(dp, size));
	free(array);
	free(dp);
	free(prev);
	while (size--)
	{
		if (a->top->lis)
			ra(a, 1);
		else
			pb(a, b, 1);
	}
}
