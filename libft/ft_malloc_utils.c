/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunomartin <brunomartin@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 14:40:28 by pitriche          #+#    #+#             */
/*   Updated: 2021/04/20 22:14:05 by brunomartin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"
#include <sys/mman.h>	// mmap

size_t			_to_page_size_multiple(size_t size)
{
	size_t	page_size;

	if (size == 0U)
		return (0U);
	page_size = (size_t)getpagesize();
	size -= 1;
	return ((size / page_size + 1) * page_size);
}

t_malloc_tiny	*_new_tiny_page(void)
{
	size_t			size;
	t_malloc_tiny	*page;

	size = _to_page_size_multiple(sizeof(t_malloc_tiny));
	page = mmap(0, size, PROT_WRITE | PROT_READ | PROT_EXEC, MAP_SHARED |
		MAP_ANONYMOUS, -1, 0);
	if (page == MAP_FAILED)
		return (0);
	page->number_bloc = 0;
	page->memory_free = MEMORY_TINY_SIZE;
	page->mmap_alloc_size = size;
	page->next = 0;
	return (page);
}

t_malloc_medium	*_new_medium_page(void)
{
	size_t			size;
	t_malloc_medium	*page;

	size = _to_page_size_multiple(sizeof(t_malloc_medium));
	page = mmap(0, size, PROT_WRITE | PROT_READ | PROT_EXEC, MAP_SHARED |
		MAP_ANONYMOUS, -1, 0);
	if (page == MAP_FAILED)
		return (0);
	page->number_bloc = 0;
	page->memory_free = MEMORY_MEDIUM_SIZE;
	page->mmap_alloc_size = size;
	page->next = 0;
	return (page);
}

t_malloc_large	*_new_large_page(void)
{
	size_t			size;
	t_malloc_large	*page;

	size = _to_page_size_multiple(sizeof(t_malloc_large));
	page = mmap(0, size, PROT_WRITE | PROT_READ | PROT_EXEC, MAP_SHARED |
		MAP_ANONYMOUS, -1, 0);
	if (page == MAP_FAILED)
		return (0);
	page->number_bloc = 0;
	page->mmap_alloc_size = size;
	page->next = 0;
	return (page);
}

t_malloc		*_malloc_singleton(void)
{
	static t_malloc	malloc_data;

	if (malloc_data.page_size == 0U)
		malloc_data.page_size = (size_t)getpagesize();
	if (malloc_data.tiny == 0)
		malloc_data.tiny = _new_tiny_page();
	if (malloc_data.medium == 0)
		malloc_data.medium = _new_medium_page();
	if (malloc_data.large == 0)
		malloc_data.large = _new_large_page();
	return (&malloc_data);
}
