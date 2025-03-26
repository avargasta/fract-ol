/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvargas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 16:20:34 by anvargas          #+#    #+#             */
/*   Updated: 2023/10/24 22:39:13 by anvargas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1_l;
	size_t	s2_l;
	char	*str;
	size_t	i;

	s1_l = ft_strlen(s1);
	s2_l = ft_strlen(s2);
	str = (char *)malloc(sizeof(char) * (s1_l + s2_l + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (i < s1_l)
	{
		str[i] = s1[i];
		i++;
	}
	while (i < (s1_l + s2_l))
	{
		str[i] = s2[i - s1_l];
		i++;
	}
	str[i] = '\0';
	return (str);
}
