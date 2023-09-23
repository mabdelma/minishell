/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabdelma <mabdelma@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 19:44:09 by cclaude           #+#    #+#             */
/*   Updated: 2023/09/17 11:22:11 by mabdelma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t			i;
	unsigned char	*p;
	unsigned char	*q;
	unsigned char	*temp;

	i = 0;
	temp = malloc(sizeof(unsigned char));
	if (!temp)
	{
		return (NULL);
	}
	p = (unsigned char *)dst;
	q = (unsigned char *)src;
	while (i < len)
	{
		*(temp + i) = *(q + i);
		i++;
	}
	i = 0;
	while (i < len)
	{
		p[i] = temp[i];
		i++;
	}
	return (dst);
}
