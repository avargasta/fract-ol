/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvargas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 14:25:43 by anvargas          #+#    #+#             */
/*   Updated: 2023/10/24 22:40:57 by anvargas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	k;

	i = 0;
	if (!*needle)
		return ((char *)haystack);
	while (haystack[i] != '\0' && i < len)
	{
		if (haystack[i] == needle[0])
		{
			j = i;
			k = 0;
			while (haystack[j] == needle[k] && haystack[j] != '\0'
				&& needle[k] != '\0' && j < len)
			{
				j++;
				k++;
			}
			if (needle[k] == '\0')
				return ((char *)(&haystack[i]));
		}
		i++;
	}
	return (NULL);
}
