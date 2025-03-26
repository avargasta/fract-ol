/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvargas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 15:01:56 by anvargas          #+#    #+#             */
/*   Updated: 2023/10/24 22:38:00 by anvargas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_words(char const *s, char c)
{
	size_t	i;
	size_t	count;

	i = 1;
	count = 0;
	if (s[0])
	{
		while (s[i])
		{
			if (s[i] == c && s[i - 1] != c)
			{
				count++;
			}
			i++;
		}
		if (s[i - 1] != c)
			count++;
	}
	return (count);
}

static size_t	get_word_len(char const *s, char c)
{
	size_t	len;

	len = 0;
	while (s[len] && s[len] != c)
		len++;
	return (len);
}

static void	free_array(size_t i, char **array)
{
	while (i > 0)
	{
		i--;
		free(array[i]);
	}
	free(array);
}

static char	**split(char const *s, char c, char **array, size_t n_words)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (i < n_words)
	{
		while (s[j] && s[j] == c)
			j++;
		array[i] = ft_substr(s, j, get_word_len(&s[j], c));
		if (!array[i])
		{
			free_array(i, array);
			return (NULL);
		}
		while (s[j] && s[j] != c)
			j++;
		i++;
	}
	array[i] = NULL;
	return (array);
}

char	**ft_split(char const *s, char c)
{
	size_t	n_words;
	char	**array;

	if (!s)
		return (NULL);
	n_words = count_words(s, c);
	array = (char **)malloc(sizeof(char *) * (n_words + 1));
	if (!array)
		return (NULL);
	array = split(s, c, array, n_words);
	return (array);
}
