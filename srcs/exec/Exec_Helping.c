/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Exec_Helping.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabdelma <mabdelma@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 09:59:42 by mabdelma          #+#    #+#             */
/*   Updated: 2023/09/22 17:40:22 by mabdelma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	magic_box1(int *ret)
{
	if (*ret == 32256 || *ret == 32512)
		*ret = (*ret) / 256;
	else
		*ret = !!(*ret);
}

void	cmd_tab1(t_token *start, t_token *token, char **tab)
{
	int	i;

	token = start->next;
	tab[0] = start->str;
	i = 1;
	while (token && token->type < TRUNC)
	{
		tab[i++] = token->str;
		token = token->next;
	}
	tab[i] = NULL;
}
