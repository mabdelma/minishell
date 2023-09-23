/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabdelma <mabdelma@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 10:18:08 by mabdelma          #+#    #+#             */
/*   Updated: 2023/09/21 08:22:37 by mabdelma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	word_count(char const *s, char c)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (s[i] == c)
		i++;
	while (s[i] != '\0')
	{
		count++;
		while (s[i] != c && s[i] != '\0')
			i++;
		while (s[i] == c)
			i++;
	}
	return (count);
}

static int	letter_count(char const *s, char c, int index)
{
	int		count;

	count = 0;
	while (s[index] != c && s[index] != '\0')
	{
		count++;
		index++;
	}
	return (count);
}

static void	control_split(char const *s, char c, char **tab, int *i)
{
	while (s[i[0]] != c && s[i[2]] != '\0')
			tab[i[0]][(i[1])++] = s[(i[2])++];
	tab[i[0]][i[1]] = '\0';
	while (s[i[2]] == c)
		(i[2])++;
	(i[0])++;
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	int		i[3];

	i[0] = 0;
	i[2] = 0;
	tab = malloc(sizeof(char *) * (word_count(s, c) + 1));
	if (!s || !c || !(tab))
		return (NULL);
	while (s[i[2]] == c)
		i[2]++;
	while (s[i[2]] != '\0')
	{
		i[1] = 0;
		tab[i[0]] = malloc(sizeof(char) * letter_count(s, c, i[2]) + 1);
		if (!(tab))
			return (NULL);
		control_split(s, c, tab, i);
	}
	tab[i[0]] = NULL;
	return (tab);
}
