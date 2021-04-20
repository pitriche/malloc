/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base_fd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunomartin <brunomartin@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 14:40:28 by pitriche          #+#    #+#             */
/*   Updated: 2021/04/20 12:49:15 by brunomartin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

inline static void	_putch_fd(char c, int fd) { write(fd, &c, 1); }

static void			_rec_putnbr_base(unsigned long absolute, const char *base_char,
	unsigned base, int fd)
{
	if (absolute >= base)
		_rec_putnbr_base(absolute / base, base_char, base, fd);
	_putch_fd(base_char[absolute % base], fd);
}

void				ft_putnbr_base_fd(long nb, const char *base_char, int fd)
{
	unsigned long	absolute;
	unsigned		base;

	base = 0;
	while (base_char[base])
		base++;
	if (base < 2)
		return ;
	if (nb < 0)
	{
		absolute = -nb;
		_putch_fd('-', fd);
	}
	else
		absolute = nb;
	_rec_putnbr_base(absolute, base_char, base, fd);
}
