/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_put_s.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabdelma <mabdelma@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 12:50:41 by cclaude           #+#    #+#             */
/*   Updated: 2023/09/21 08:34:30 by mabdelma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	pf_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

int	pf_putstr_prewid(char *s, struct s_flgs *flags)
{
	int		ssize;
	int		padsize;
	int		i;
	char	c;

	c = ' ';
	if (flags->zero == 1 && flags->minus == 0)
		c = '0';
	i = pf_strlen(s);
	support_func_s(flags, &ssize, &padsize, &i);
	i = 0;
	while (flags->minus == 1 && i < flags->precision && s[i] != '\0')
		buf_write(flags->buffer, s[i++], &flags->index);
	i = 0;
	while (i++ < padsize)
		buf_write(flags->buffer, c, &flags->index);
	i = 0;
	while (flags->minus == 0 && i < flags->precision && s[i] != '\0')
		buf_write(flags->buffer, s[i++], &flags->index);
	if (ssize > flags->width)
		return (ssize);
	else
		return (flags->width);
}

int	pf_putstr_wid(char *s, struct s_flgs *flags)
{
	int		padsize;
	int		i;
	char	c;

	c = ' ';
	if (flags->zero == 1 && flags->minus == 0)
		c = '0';
	if (flags->width > pf_strlen(s))
		padsize = flags->width - pf_strlen(s);
	else
		padsize = 0;
	i = 0;
	while (flags->minus == 1 && s[i] != '\0')
		buf_write(flags->buffer, s[i++], &flags->index);
	i = 0;
	while (i++ < padsize)
		buf_write(flags->buffer, c, &flags->index);
	i = 0;
	while (flags->minus == 0 && s[i] != '\0')
		buf_write(flags->buffer, s[i++], &flags->index);
	if (pf_strlen(s) > flags->width)
		return (pf_strlen(s));
	else
		return (flags->width);
}

int	pf_putstr_pre(struct s_flgs *flags, char *s, int prec)
{
	int	ssize;
	int	i;

	if (pf_strlen(s) < prec)
		ssize = pf_strlen(s);
	else
		ssize = prec;
	i = 0;
	while (i < ssize && s[i] != '\0')
		buf_write(flags->buffer, s[i++], &flags->index);
	return (ssize);
}

int	pf_putstr(struct s_flgs *flags, char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		buf_write(flags->buffer, s[i++], &flags->index);
	return (i);
}
