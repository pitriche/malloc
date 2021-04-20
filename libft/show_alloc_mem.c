/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_alloc_mem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunomartin <brunomartin@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 14:40:28 by pitriche          #+#    #+#             */
/*   Updated: 2021/04/20 19:25:01 by brunomartin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"
#include "libft.h"

static size_t	pr_tiny(t_malloc_tiny *tmp)
{
	size_t	total;
	void	*addr;

	total = 0U;
	ft_putstr("TINY : 0x");
	ft_putnbr_base_fd((long)tmp, "0123456789ABCDEF", 1);
	ft_putstr("\n");
	while (tmp)
	{
		for (unsigned i = 0; i < tmp->number_bloc; ++i)
		{
			addr = tmp->memory + tmp->bloc[i].off;
			ft_putstr("0x");
			ft_putnbr_base_fd((long)addr, "0123456789ABCDEF", 1);
			ft_putstr(" - 0x");
			ft_putnbr_base_fd((long)addr + tmp->bloc[i].len - 1,
				"0123456789ABCDEF", 1);
			ft_putstr(" : ");
			ft_putnbr(tmp->bloc[i].len);
			ft_putstr(" octets\n");
			total += tmp->bloc[i].len;
		}
		tmp = tmp->next;
	}
	return (total);
}

static size_t	pr_small(t_malloc_medium *tmp)
{
	size_t	total;
	void	*addr;

	total = 0U;
	ft_putstr("SMALL : 0x");
	ft_putnbr_base_fd((long)tmp, "0123456789ABCDEF", 1);
	ft_putstr("\n");
	while (tmp)
	{
		for (unsigned i = 0; i < tmp->number_bloc; ++i)
		{
			addr = tmp->memory + tmp->bloc[i].off;
			ft_putstr("0x");
			ft_putnbr_base_fd((long)addr, "0123456789ABCDEF", 1);
			ft_putstr(" - 0x");
			ft_putnbr_base_fd((long)addr + tmp->bloc[i].len - 1,
				"0123456789ABCDEF", 1);
			ft_putstr(" : ");
			ft_putnbr(tmp->bloc[i].len);
			ft_putstr(" octets\n");
			total += tmp->bloc[i].len;
		}
		tmp = tmp->next;
	}
	return (total);
}

static size_t	pr_large(t_malloc_large *tmp)
{
	size_t	total;
	void	*addr;

	total = 0U;
	ft_putstr("LARGE : 0x");
	ft_putnbr_base_fd((long)tmp, "0123456789ABCDEF", 1);
	ft_putstr("\n");
	while (tmp)
	{
		for (unsigned i = 0; i < tmp->number_bloc; ++i)
		{
			addr = tmp->memory[i];
			ft_putstr("0x");
			ft_putnbr_base_fd((long)addr, "0123456789ABCDEF", 1);
			ft_putstr(" - 0x");
			ft_putnbr_base_fd((long)addr + tmp->original_size[i] - 1,
				"0123456789ABCDEF", 1);
			ft_putstr(" : ");
			ft_putnbr(tmp->original_size[i]);
			ft_putstr(" octets\n");
			total += tmp->original_size[i];
		}
		tmp = tmp->next;
	}
	return (total);
}

void			show_alloc_mem(void)
{
	size_t		total;
	t_malloc	*data;

	// check for mmap error
	data = _malloc_singleton();
	if (data->tiny == 0 || data->medium == 0 || data->large == 0)
		return ;

	total = 0UL;
	total += pr_tiny(data->tiny);
	total += pr_small(data->medium);
	total += pr_large(data->large);
	ft_putstr("Total : ");
	ft_putnbr(total);
	ft_putstr(" octets\n");
}
