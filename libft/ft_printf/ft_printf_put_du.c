/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_put_du.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabdelma <mabdelma@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 10:28:57 by mabdelma          #+#    #+#             */
/*   Updated: 2023/09/21 08:53:42 by mabdelma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	pf_nbrlen(long n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	else if (n < 0)
	{
		n = -n;
		len++;
	}
	while (n > 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

int	pf_putnbr_prewid(long n, struct s_flgs *flags)
{
	int		printed;
	int		count;
	int		padding;
	long	c[2];

	c[0] = n;
	c[1] = (long)pf_nbrlen(n);
	support_func_du(flags, &count, &padding, c);
	printed = padding + count + pf_nbrlen(n);
	while (flags->minus == 0 && padding-- > 0)
		buf_write(flags->buffer, ' ', &flags->index);
	if (n < 0)
	{
		buf_write(flags->buffer, '-', &flags->index);
		n = -n;
	}
	while (count-- > 0)
		buf_write(flags->buffer, '0', &flags->index);
	pf_putnbr(flags, n);
	while (flags->minus == 1 && padding-- > 0)
		buf_write(flags->buffer, ' ', &flags->index);
	return (printed);
}

int	pf_putnbr_wid(long n, struct s_flgs *flags)
{
	int		printed;
	int		padding;

	printed = 0;
	padding = flags->width - pf_nbrlen(n);
	while (flags->minus == 0 && padding-- > 0)
	{
		buf_write(flags->buffer, ' ', &flags->index);
		printed++;
	}
	printed += pf_putnbr(flags, n);
	while (flags->minus == 1 && padding-- > 0)
	{
		buf_write(flags->buffer, ' ', &flags->index);
		printed++;
	}
	return (printed);
}

int	pf_putnbr_pre(long n, struct s_flgs *flags)
{
	int		printed;
	int		count;

	printed = 0;
	if (flags->dot == 1)
		count = flags->precision;
	else
		count = flags->width;
	if (n < 0 && flags->dot == 1)
		count -= pf_nbrlen(n) - 1;
	else
		count -= pf_nbrlen(n);
	if (n < 0)
	{
		buf_write(flags->buffer, '-', &flags->index);
		n = -n;
		printed++;
	}
	while (count-- > 0)
	{
		buf_write(flags->buffer, '0', &flags->index);
		printed++;
	}
	printed += pf_putnbr(flags, n);
	return (printed);
}

int	pf_putnbr(struct s_flgs *flags, long n)
{
	char	c;
	int		printed;

	printed = 0;
	if (n < 0)
	{
		buf_write(flags->buffer, '-', &flags->index);
		printed++;
		n = -n;
	}
	if (n / 10 > 0)
		printed += pf_putnbr(flags, n / 10);
	c = n % 10 + '0';
	buf_write(flags->buffer, c, &flags->index);
	printed++;
	return (printed);
}
