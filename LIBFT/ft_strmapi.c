/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvargas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 18:53:32 by anvargas          #+#    #+#             */
/*   Updated: 2023/11/04 18:39:12 by anvargas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*m_alloc(char const *s)
{
	size_t	len;
	char	*array;

	len = ft_strlen(s);
	array = (char *)malloc(sizeof(char) * (len + 1));
	if (!array)
		return (NULL);
	return (array);
}

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*array;
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	array = m_alloc(s);
	if (!array)
		return (NULL);
	while (s[i])
	{
		array[i] = f(i, s[i]);
		i++;
	}
	array[i] = '\0';
	return (array);
}
