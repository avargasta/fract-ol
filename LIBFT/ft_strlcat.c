/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvargas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 21:24:57 by anvargas          #+#    #+#             */
/*   Updated: 2023/10/24 22:39:42 by anvargas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *restrict dst, const char *restrict src, size_t size)
{
	size_t	src_l;
	size_t	dst_l;
	size_t	i;

	src_l = ft_strlen(src);
	dst_l = 0;
	while (dst[dst_l] != '\0' && dst_l < size)
		dst_l += 1;
	i = 0;
	if (size > 0 && dst_l < size - 1)
	{
		while (i < (size - dst_l - 1) && src[i] != '\0')
		{
			dst[dst_l + i] = src[i];
			i += 1;
		}
		dst[dst_l + i] = '\0';
	}
	return (dst_l + src_l);
}
