/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iscount.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabdelma <mabdelma@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 18:35:08 by cclaude           #+#    #+#             */
/*   Updated: 2023/09/17 10:33:42 by mabdelma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_iscount(int c, char *base)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (base[i] != '\0')
	{
		if (base[i] == c)
			count++;
		i++;
	}
	return (count);
}
