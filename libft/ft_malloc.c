/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunomartin <brunomartin@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 14:40:28 by pitriche          #+#    #+#             */
/*   Updated: 2021/04/21 10:09:13 by brunomartin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"
#include <sys/mman.h>	// mmap


static void	*_malloc_tiny(size_t size)
{
	t_malloc_tiny	*last;
	void			*ret;

	last = _malloc_singleton()->tiny;
	while (last->next != 0)
		last = last->next;
	if (last->number_bloc >= MAX_TINY_BLOC || last->memory_free < size)
	{
		if (!(last->next = _new_tiny_page()))
			return (0);
		last = last->next;
	}
	last->bloc[last->number_bloc].len = size;
	last->bloc[last->number_bloc].off = MEMORY_TINY_SIZE -
	last->memory_free;
	ret = last->memory + last->bloc[last->number_bloc].off;
	last->memory_free -= size;
	++(last->number_bloc);
	return (ret);
}

static void	*_malloc_medium(size_t size)
{
	t_malloc_medium	*last;
	void			*ret;

	last = _malloc_singleton()->medium;
	while (last->next != 0)
		last = last->next;
	if (last->number_bloc >= MAX_MEDIUM_BLOC || last->memory_free < size)
	{
		if (!(last->next = _new_medium_page()))
			return (0);
		last = last->next;
	}
	last->bloc[last->number_bloc].len = size;
	last->bloc[last->number_bloc].off = MEMORY_MEDIUM_SIZE -
	last->memory_free;
	ret = last->memory + last->bloc[last->number_bloc].off;
	last->memory_free -= size;
	++(last->number_bloc);
	return (ret);
}

static void	*_malloc_large(size_t size)
{
	t_malloc_large	*last;
	void			*ret;

	last = _malloc_singleton()->large;
	while (last->next != 0)
		last = last->next;
	if (last->number_bloc >= MAX_LARGE_BLOC)
	{
		if (!(last->next = _new_large_page()))
			return (0);
		last = last->next;
	}
	last->original_size[last->number_bloc] = size;
	last->mmap_size[last->number_bloc] = _to_page_size_multiple(size);
	last->memory[last->number_bloc] = mmap(0,
		last->mmap_size[last->number_bloc], PROT_WRITE | PROT_READ | PROT_EXEC,
		MAP_SHARED | MAP_ANONYMOUS, -1, 0);
	ret = last->memory[last->number_bloc];
	if (ret == MAP_FAILED)
		return (0);
	++(last->number_bloc);
	return (ret);
}

void		*ft_malloc(size_t size)
{
	t_malloc	*data;

	// check for mmap error
	data = _malloc_singleton();
	if (data->tiny == 0 || data->medium == 0 || data->large == 0)
		return (0);
	if (size < TINY_SIZE)
		return (_malloc_tiny(size));
	if (size < MEDIUM_SIZE)
		return (_malloc_medium(size));
	return (_malloc_large(size));
}
