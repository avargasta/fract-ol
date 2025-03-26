/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvargas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 18:24:58 by anvargas          #+#    #+#             */
/*   Updated: 2023/11/14 15:09:30 by anvargas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*current;
	t_list	*next;

	if (!lst || !del || !(*lst))
		return ;
	current = *lst;
	while (current)
	{
		next = current -> next;
		(del)(current -> content);
		free(current);
		current = next;
	}
	*lst = NULL;
}
