/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunomartin <brunomartin@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 14:40:28 by pitriche          #+#    #+#             */
/*   Updated: 2021/04/21 12:53:24 by brunomartin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"
#include "libft.h"		// ft_memmove
#include <sys/mman.h>	// munmap


static size_t	_min(size_t t1, size_t t2) { return (t1 > t2 ? t2 : t1); }

static void	*_realloc_tiny(t_malloc_tiny *last, void *old_ptr, size_t size)
{
	size_t	tmp;
	void	*new_ptr;

	while (last != 0)
	{
		tmp = (size_t)(old_ptr - (void *)last->memory);
		for (unsigned i = 0; i < last->number_bloc; ++i)
			if (last->bloc[i].off == tmp)
			{
				new_ptr = malloc(size);
				ft_memmove(new_ptr, old_ptr, _min(size, last->bloc[i].len));
				if (i == last->number_bloc - 1)
					last->memory_free += last->bloc[i].len;
				ft_memmove(last->bloc + i, last->bloc + i + 1,
					(last->number_bloc - i - 1) * sizeof(t_malloc_bloc));
				last->number_bloc--;
				return (new_ptr);
			}
		last = last->next;
	}
	return (0);
}

static void	*_realloc_medium(t_malloc_medium *last, void *old_ptr, size_t size)
{
	size_t	tmp;
	void	*new_ptr;

	while (last != 0)
	{
		tmp = (size_t)(old_ptr - (void *)last->memory);
		for (unsigned i = 0; i < last->number_bloc; ++i)
			if (last->bloc[i].off == tmp)
			{
				new_ptr = malloc(size);
				ft_memmove(new_ptr, old_ptr, _min(size, last->bloc[i].len));
				if (i == last->number_bloc - 1)
					last->memory_free += last->bloc[i].len;
				ft_memmove(last->bloc + i, last->bloc + i + 1,
					(last->number_bloc - i - 1) * sizeof(t_malloc_bloc));
				last->number_bloc--;
				return (new_ptr);
			}
		last = last->next;
	}
	return (0);
}

static void	*_realloc_large(t_malloc_large *last, void *old_ptr, size_t size)
{
	void	*new_ptr;

	while (last != 0)
	{
		for (unsigned i = 0; i < last->number_bloc; ++i)
			if (last->memory[i] == old_ptr)
			{
				new_ptr = malloc(size);
				ft_memmove(new_ptr, old_ptr, _min(size,
					last->original_size[i]));
				munmap(last->memory[i], last->mmap_size[i]);
				ft_memmove(last->memory + i, last->memory + i + 1,
					(last->number_bloc - i - 1) * sizeof(void *));
				ft_memmove(last->original_size + i, last->original_size + i + 1,
					(last->number_bloc - i - 1) * sizeof(size_t));
				ft_memmove(last->mmap_size + i, last->mmap_size + i + 1,
					(last->number_bloc - i - 1) * sizeof(size_t));
				last->number_bloc--;
				return (new_ptr);
			}
		last = last->next;
	}
	return (0);
}

void		*realloc(void *ptr, size_t size)
{
	t_malloc	*data;
	void		*new;

	// check for mmap error
	data = _malloc_singleton();
	if (data->tiny == 0 || data->medium == 0 || data->large == 0)
		return (0);
	if (ptr == 0)
		return (malloc(size));
	if (size == 0)
	{
		free(ptr);
		return (malloc(1)); // to comply malloc(3) macos man
	}
	new = _realloc_tiny(data->tiny, ptr, size);
	if (new != 0)
		return (new);
	new = _realloc_medium(data->medium, ptr, size);
	if (new != 0)
		return (new);
	return (_realloc_large(data->large, ptr, size));
}
