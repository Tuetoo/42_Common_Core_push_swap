/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiezhang <jiezhang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 11:40:52 by jiezhang          #+#    #+#             */
/*   Updated: 2025/12/01 18:08:41 by jiezhang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void	execute_command(t_stack *a, t_stack *b, char *command)
{
	if (!ft_strcmp(command, "sa"))
		sa(a, 0);
	else if (!ft_strcmp(command, "sb"))
		sb(b, 0);
	else if (!ft_strcmp(command, "ss"))
		ss(a, b, 0);
	else if (!ft_strcmp(command, "ra"))
		ra(a, 0);
	else if (!ft_strcmp(command, "rb"))
		rb(b, 0);
	else if (!ft_strcmp(command, "rr"))
		rr(a, b, 0);
	else if (!ft_strcmp(command, "rra"))
		rra(a, 0);
	else if (!ft_strcmp(command, "rrb"))
		rrb(b, 0);
	else if (!ft_strcmp(command, "rrr"))
		rrr(a, b, 0);
	else if (!ft_strcmp(command, "pa"))
		pa(a, b, 0);
	else if (!ft_strcmp(command, "pb"))
		pb(a, b, 0);
	else
		handle_error();
}

static char	**read_command(void)
{
	char	buf[1025];
	char	*buffer;
	char	*tmp;
	int		bytes;
	char	**command;

	buffer = NULL;
	while (1)
	{
		bytes = read(0, buf, 1024);
		if (bytes <= 0)
			break ;
		buf[bytes] = '\0';
		tmp = ft_strjoin(buffer, buf);
		free(buffer);
		buffer = tmp;
	}
	command = ft_split(buffer, '\n');
	free(buffer);
	if (!command)
		return (NULL);
	return (command);
}

int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;
	char	**command;
	int		i;

	init_stack(&a);
	init_stack(&b);
	if (argc < 2)
		return (0);
	parse_args(&a, argc, argv);
	command = read_command();
	i = 0;
	while (command && command[i])
	{
		if (ft_strlen(command[i]))
			execute_command(&a, &b, command[i++]);
	}
	free_array(command);
	if (is_sorted(&a) && !b.size)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free_stack(&a);
	free_stack(&b);
	return (0);
}
