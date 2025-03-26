/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvargas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 13:42:20 by anvargas          #+#    #+#             */
/*   Updated: 2023/11/04 18:31:57 by anvargas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	char_count(int n)
{
	size_t	count;

	count = 0;
	if (n == 0)
		count = 1;
	if (n < 0)
		count++;
	while (n != 0)
	{
		n = n / 10;
		count++;
	}
	return (count);
}

static char	*m_alloc(size_t mem)
{
	char		*array;

	array = (char *)malloc(sizeof(char) * (mem + 1));
	if (!array)
		return (NULL);
	return (array);
}

static char	*my_itoa(char *array, int n, size_t index, size_t n_chars)
{
	array[n_chars] = '\0';
	while (n_chars > index)
	{
		array[n_chars - 1] = n % 10 + '0';
		n = n / 10;
		n_chars--;
	}
	return (array);
}

char	*ft_itoa(int n)
{
	char		*array;
	size_t		n_chars;

	n_chars = char_count(n);
	array = m_alloc(n_chars);
	if (!array)
		return (NULL);
	if (n == -2147483648)
	{
		array[0] = '-';
		array[1] = '2';
		my_itoa(array, 147483648, 2, n_chars);
	}
	else if (n < 0)
	{
		array[0] = '-';
		my_itoa(array, -n, 1, n_chars);
	}
	else if (n >= 0)
		my_itoa(array, n, 0, n_chars);
	return (array);
}
