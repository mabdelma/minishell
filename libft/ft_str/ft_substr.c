/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabdelma <mabdelma@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 10:23:06 by mabdelma          #+#    #+#             */
/*   Updated: 2023/09/21 09:11:25 by mabdelma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*new;
	int		i;

	if (s == NULL)
		return (NULL);
	new = malloc(sizeof(char) * (len + 1));
	if (!(new))
		return (NULL);
	i = 0;
	while (s[i] != '\0')
		i++;
	if (start + 1 > (unsigned int)i)
	{
		new[0] = '\0';
		return (new);
	}
	i = 0;
	while (i < (int)len && s[start + i] != '\0')
	{
		new[i] = s[start + i];
		i++;
	}
	new[i] = '\0';
	return (new);
}
