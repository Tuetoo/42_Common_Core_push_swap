/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiezhang <jiezhang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 09:14:44 by jiezhang          #+#    #+#             */
/*   Updated: 2025/12/01 07:35:10 by jiezhang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <stdio.h>

typedef struct s_node
{
	int				value;
	int				index;
	int				lis;
	int				pos;
	int				target_pos;
	int				cost_a;
	int				cost_b;
	struct s_node	*next;
}					t_node;

typedef struct s_stack
{
	t_node	*top;
	t_node	*bottom;
	int		size;
}			t_stack;

// process
void	index_stack(t_stack *a);
void	find_lis_and_push_non_lis(t_stack *a, t_stack *b);
void	calculate_costs(t_stack *a, t_stack *b);
t_node	*get_cheapest_node(t_stack *b);
void	push_back_and_sort(t_stack *a, t_stack *b);
void	sort_small(t_stack *a, t_stack *b);

// call from bonus
void	parse_args(t_stack *a, int argc, char **argv);
void	init_stack(t_stack *stack);
int		is_sorted(t_stack *a);
void	free_stack(t_stack *stack);
void	handle_error(void);
char	**ft_split(char const *s, char c);
void	free_array(char **array);

// stack
t_node	*create_node(int value);
void	push_front(t_stack *stack, t_node *node);
void	push_back(t_stack *stack, t_node *node);
t_node	*pop_front(t_stack *stack);
t_node	*pop_back(t_stack *stack);

// operation
void	sa(t_stack *a, int mode);
void	sb(t_stack *b, int mode);
void	ss(t_stack *a, t_stack *b, int mode);
void	pa(t_stack *a, t_stack *b, int mode);
void	pb(t_stack *a, t_stack *b, int mode);
void	ra(t_stack *a, int mode);
void	rb(t_stack *b, int mode);
void	rr(t_stack *a, t_stack *b, int mode);
void	rra(t_stack *a, int mode);
void	rrb(t_stack *b, int mode);
void	rrr(t_stack *a, t_stack *b, int mode);

// utils
int		ft_abs(int value);
int		max(int a, int b);
int		find_min_pos(t_stack *a);
void	update_positions(t_stack *stack);

#endif