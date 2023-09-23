/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_support_f.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabdelma <mabdelma@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 07:39:31 by mabdelma          #+#    #+#             */
/*   Updated: 2023/09/21 08:34:25 by mabdelma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	support_func_du(struct s_flgs *flags, int *count, int *padding, long *c)
{
	*count = flags->precision - (int)c[1];
	if (c[0] < 0)
		*count += 1;
	if (!(*count > 0))
		*count = 0;
	*padding = flags->width - (int)c[1] - *count;
	if (!(*padding > 0))
		*padding = 0;
}

void	support_func_s(struct s_flgs *flags, int *ssize, int *padsize, int *x)
{
	if (*x < flags->precision)
		*ssize = *x;
	else
		*ssize = flags->precision;
	if (flags->width > *ssize)
		*padsize = flags->width - *ssize;
	else
		*padsize = 0;
}
