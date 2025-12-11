/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiezhang <jiezhang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 10:17:37 by jiezhang          #+#    #+#             */
/*   Updated: 2025/12/01 07:53:51 by jiezhang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static size_t	wordcount(char const *s, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] != c && (i == 0 || s[i - 1] == c))
			count++;
		i++;
	}
	return (count);
}

void	free_array(char **array)
{
	int	i;

	i = 0;
	if (!array)
		return ;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}

static char	*newword(char const *s, char c, size_t *i)
{
	size_t	start;
	size_t	len;
	char	*array;
	size_t	j;

	len = 0;
	while (s[*i] && s[*i] == c)
		(*i)++;
	start = *i;
	while (s[*i] && s[*i] != c)
	{
		(*i)++;
		len++;
	}
	array = malloc((len + 1) * sizeof(char));
	if (!array)
		return (NULL);
	j = 0;
	while (j < len)
	{
		array[j] = s[start + j];
		j++;
	}
	array[j] = '\0';
	return (array);
}

char	**ft_split(char const *s, char c)
{
	char	**array;
	size_t	i;
	size_t	j;
	size_t	count;

	if (!s)
		return (NULL);
	count = wordcount(s, c);
	array = malloc(sizeof(char *) * (count + 1));
	if (!array)
		return (NULL);
	i = 0;
	j = 0;
	while (j < count)
	{
		array[j] = newword(s, c, &i);
		if (!array[j])
		{
			free_array(array);
			return (NULL);
		}
		j++;
	}
	array[j] = NULL;
	return (array);
}
