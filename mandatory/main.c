/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiezhang <jiezhang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 17:32:48 by jiezhang          #+#    #+#             */
/*   Updated: 2025/12/03 19:55:05 by jiezhang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;

	if (argc < 2)
		return (0);
	init_stack(&a);
	init_stack(&b);
	parse_args(&a, argc, argv);
	if (a.size == 1 || is_sorted(&a))
		return (0);
	if (a.size <= 5)
	{
		sort_small(&a, &b);
		free_stack(&a);
		free_stack(&b);
		return (0);
	}
	index_stack(&a);
	find_lis_and_push_non_lis(&a, &b);
	push_back_and_sort(&a, &b);
	free_stack(&a);
	free_stack(&b);
	return (0);
}
