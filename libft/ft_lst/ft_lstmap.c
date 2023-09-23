/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabdelma <mabdelma@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 15:49:42 by cclaude           #+#    #+#             */
/*   Updated: 2023/09/17 11:12:46 by mabdelma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list	*map_ft_memdel(t_list *start, void (*del)(void *))
{
	t_list	*temp;
	t_list	*next;

	temp = start;
	while (temp != NULL)
	{
		next = temp->next;
		del(temp->content);
		ft_memdel(temp);
		temp = next;
	}
	return (NULL);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void*), void (*del)(void *))
{
	t_list	*lstnew;
	t_list	*temp;
	t_list	*prev;
	t_list	*start;

	temp = lst;
	start = NULL;
	prev = NULL;
	while (temp != NULL && f != NULL && del != NULL)
	{
		lstnew = malloc(sizeof(t_list));
		if (!lstnew)
			return (map_ft_memdel(start, del));
		lstnew->content = f(temp->content);
		if (prev != NULL)
			prev->next = lstnew;
		prev = lstnew;
		temp = temp->next;
		if (start == NULL)
			start = lstnew;
	}
	if (lst != NULL && f != NULL && del != NULL)
		lstnew->next = NULL;
	return (start);
}
