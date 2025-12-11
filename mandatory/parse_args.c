/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiezhang <jiezhang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 15:16:18 by jiezhang          #+#    #+#             */
/*   Updated: 2025/12/01 07:56:01 by jiezhang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_num(char *str)
{
	int	i;

	i = 0;
	if (!str || str[0] == '\0')
		return (0);
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '\0')
		return (0);
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

static long	ft_atoi(char *str, int *error)
{
	int		i;
	long	sign;
	long	num;

	i = 0;
	sign = 1;
	num = 0;
	*error = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = num * 10 + str[i] - '0';
		if (num * sign < INT_MIN || num * sign > INT_MAX)
			return (*error = 1, 0);
		i++;
	}
	return (num * sign);
}

static int	is_duplicated(t_stack *stack, int value)
{
	t_node	*tmp;

	tmp = stack->top;
	while (tmp)
	{
		if (tmp->value == value)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

void	parse_args(t_stack *a, int argc, char **argv)
{
	int		i;
	int		j;
	long	num;
	int		error;
	char	**array;

	i = 0;
	while (++i < argc)
	{
		array = ft_split(argv[i], ' ');
		if (!array || !array[0])
			handle_error();
		j = 0;
		while (array[j])
		{
			if (!is_num(array[j]))
				handle_error();
			num = ft_atoi(array[j], &error);
			if (error || is_duplicated(a, (int)num))
				handle_error();
			push_back(a, create_node((int)num));
			j++;
		}
		free_array(array);
	}
}
