/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabdelma <mabdelma@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 15:49:04 by cclaude           #+#    #+#             */
/*   Updated: 2023/09/17 11:13:35 by mabdelma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*current;
	t_list	*prev;

	current = *lst;
	if (*lst == NULL || !(current) || !del)
		return ;
	while (current->next != NULL)
	{
		prev = current;
		del(current->content);
		ft_memdel(current);
		current = prev->next;
	}
	del(current->content);
	ft_memdel(current);
	*lst = NULL;
}
