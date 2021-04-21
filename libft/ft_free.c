/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunomartin <brunomartin@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 14:40:28 by pitriche          #+#    #+#             */
/*   Updated: 2021/04/21 10:04:45 by brunomartin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"
#include "libft.h"		// ft_memmove
#include <sys/mman.h>	// munmap

static void	_free_tiny(t_malloc_tiny *last, void *ptr)
{
	size_t	tmp;

	if (ptr == 0)
		return ;
	while (last != 0)
	{
		tmp = (size_t)(ptr - (void *)last->memory);
		for (unsigned i = 0; i < last->number_bloc; ++i)
			if (last->bloc[i].off == tmp)
			{
				if (i == last->number_bloc - 1)
					last->memory_free += last->bloc[i].len;
				ft_memmove(last->bloc + i, last->bloc + i + 1,
					(last->number_bloc - i - 1) * sizeof(t_malloc_bloc));
				last->number_bloc--;
				return ;
			}
		last = last->next;
	}
}

static void	_free_medium(t_malloc_medium *last, void *ptr)
{
	size_t	tmp;

	if (ptr == 0)
		return ;
	while (last != 0)
	{
		tmp = (size_t)(ptr - (void *)last->memory);
		for (unsigned i = 0; i < last->number_bloc; ++i)
			if (last->bloc[i].off == tmp)
			{
				if (i == last->number_bloc - 1)
					last->memory_free += last->bloc[i].len;
				ft_memmove(last->bloc + i, last->bloc + i + 1,
					(last->number_bloc - i - 1) * sizeof(t_malloc_bloc));
				last->number_bloc--;
				return ;
			}
		last = last->next;
	}
}

static void	_free_large(t_malloc_large *last, void *ptr)
{
	if (ptr == 0)
		return ;
	while (last != 0)
	{
		for (unsigned i = 0; i < last->number_bloc; ++i)
			if (last->memory[i] == ptr)
			{
				munmap(last->memory[i], last->mmap_size[i]);
				ft_memmove(last->original_size + i, last->original_size + i + 1,
					(last->number_bloc - i - 1) * sizeof(size_t));
				ft_memmove(last->mmap_size + i, last->mmap_size + i + 1,
					(last->number_bloc - i - 1) * sizeof(size_t));
				last->number_bloc--;
				return ;
			}
		last = last->next;
	}
}

// page sniffers, free empty pages on tiny medium and large
static void	_pages_sniffer_tiny(t_malloc *data)
{
	void			*tmp;
	t_malloc_tiny	*prev;

	prev = data->tiny;
	while (prev != 0)
	{
		if (prev->next != 0 && prev->next->number_bloc == 0)
		{
			tmp = prev->next->next;
			munmap(prev->next, prev->next->mmap_alloc_size);
			prev->next = tmp;
		}
		prev = prev->next;
	}
}

static void	_pages_sniffer_medium(t_malloc *data)
{
	void			*tmp;
	t_malloc_medium	*prev;

	prev = data->medium;
	while (prev != 0)
	{
		if (prev->next != 0 && prev->next->number_bloc == 0)
		{
			tmp = prev->next->next;
			munmap(prev->next, prev->next->mmap_alloc_size);
			prev->next = tmp;
		}
		prev = prev->next;
	}
}

static void	_pages_sniffer_large(t_malloc *data)
{
	void			*tmp;
	t_malloc_large	*prev;

	prev = data->large;
	while (prev != 0)
	{
		if (prev->next != 0 && prev->next->number_bloc == 0)
		{
			tmp = prev->next->next;
			munmap(prev->next, prev->next->mmap_alloc_size);
			prev->next = tmp;
		}
		prev = prev->next;
	}
}

void		ft_free(void *ptr)
{
	t_malloc	*data;

	// check for mmap error
	data = _malloc_singleton();
	if (data->tiny == 0 || data->medium == 0 || data->large == 0)
		return ;

	_free_tiny(data->tiny, ptr);
	_free_medium(data->medium, ptr);
	_free_large(data->large, ptr);
	_pages_sniffer_tiny(data);
	_pages_sniffer_medium(data);
	_pages_sniffer_large(data);
}
