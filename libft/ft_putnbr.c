/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunomartin <brunomartin@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 14:40:28 by pitriche          #+#    #+#             */
/*   Updated: 2021/04/20 22:05:14 by brunomartin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

inline static void	_putch(char c) { write(1, &c, 1); }

static void			_rec_putnbr(unsigned long absolute)
{
	if (absolute >= 10)
		_rec_putnbr(absolute / 10);
	_putch(absolute % 10 + '0');
}

void				ft_putnbr(long nb)
{
	unsigned long	absolute;

	if (nb < 0)
	{
		absolute = (unsigned long)-nb;
		_putch('-');
	}
	else
		absolute = (unsigned long)nb;
	_rec_putnbr(absolute);
}
