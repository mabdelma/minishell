/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabdelma <mabdelma@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 09:58:25 by mabdelma          #+#    #+#             */
/*   Updated: 2023/09/21 19:54:39 by mabdelma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	export_support1(int *error_ret,
	int *new_env, char **args, t_env *env)
{
	if (*error_ret == 2)
		*new_env = 1;
	else
		*new_env = is_in_env(env, args[1]);
}

int	ft_export(char **args, t_env *env, t_env *secret)
{
	int		new_env;
	int		error_ret;

	new_env = 0;
	if (!args[1])
	{
		print_sorted_env(secret);
		return (SUCCESS);
	}
	else
	{
		error_ret = is_valid_env(args[1]);
		if (args[1][0] == '=')
			error_ret = -3;
		if (error_ret <= 0)
			return (print_error_export(error_ret, args[1]));
		export_support1(&error_ret, &new_env, args, env);
		if (new_env == 0)
		{
			if (error_ret == 1)
				env_add(args[1], env);
			env_add(args[1], secret);
		}
	}
	return (SUCCESS);
}
