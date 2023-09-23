/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Parse_Helping.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabdelma <mabdelma@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 10:02:04 by mabdelma          #+#    #+#             */
/*   Updated: 2023/09/22 17:18:04 by mabdelma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	check_line1(t_mini *mini, t_token *token)
{
	if (token->next)
		ft_putstr_fd(token->next->str, STDERR);
	if (!token->next)
		ft_putstr_fd("newline", STDERR);
	ft_putendl_fd("'", STDERR);
	mini->ret = 258;
}
