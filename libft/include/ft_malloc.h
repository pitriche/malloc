/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunomartin <brunomartin@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 19:05:26 by pitriche          #+#    #+#             */
/*   Updated: 2021/04/21 12:50:50 by brunomartin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MALLOC_H
# define FT_MALLOC_H

#include <sys/_types/_size_t.h>	// size_t

/*
** for 4096B pages
** tiny malloc have 2 page of meta for 1 page of data
** medium malloc have 6 page of meta for 64 page of data
** large malloc have 4 pages of meta for 511 to inf pages of data
** (and it really doesn't matter)
*/
# define TINY_SIZE			64U		// max size of element (strictly inferior to)
# define MEMORY_TINY_SIZE	4096U	// size of memory in each malloc page
# define MAX_TINY_BLOC		5		// number of max size elements in each malloc page

# define MEDIUM_SIZE		4096U
# define MEMORY_MEDIUM_SIZE	262144U
# define MAX_MEDIUM_BLOC	2046

# define MAX_LARGE_BLOC	511

typedef struct	s_malloc_bloc
{
	size_t		off;	// bloc offset from page memory start
	size_t		len;	// bloc length
}				t_malloc_bloc;

typedef struct	s_malloc_tiny
{
	t_malloc_bloc			bloc[MAX_TINY_BLOC];
	unsigned				number_bloc;
	size_t					memory_free;
	size_t					mmap_alloc_size;
	struct s_malloc_tiny	*next;
	
	char					memory[MEMORY_TINY_SIZE];
}				t_malloc_tiny;

typedef struct	s_malloc_medium
{
	t_malloc_bloc			bloc[MAX_MEDIUM_BLOC];
	unsigned				number_bloc;
	size_t					memory_free;
	size_t					mmap_alloc_size;
	struct	s_malloc_medium	*next;

	char					memory[MEMORY_MEDIUM_SIZE];
}				t_malloc_medium;

typedef struct	s_malloc_large
{
	void					*memory[MAX_LARGE_BLOC];
	
	size_t					original_size[MAX_LARGE_BLOC];
	size_t					mmap_size[MAX_LARGE_BLOC];
	unsigned				number_bloc;
	size_t					mmap_alloc_size;
	struct	s_malloc_large	*next;
}				t_malloc_large;

typedef struct	s_malloc
{
	size_t				page_size;
	t_malloc_tiny		*tiny;
	t_malloc_medium		*medium;
	t_malloc_large		*large;
}				t_malloc;

void			free(void *ptr);
void			*malloc(size_t size);
void			*realloc(void *ptr, size_t size);
void			show_alloc_mem(void);

/*
** malloc subfunctions
*/
t_malloc_tiny	*_new_tiny_page(void);
t_malloc_medium	*_new_medium_page(void);
t_malloc_large	*_new_large_page(void);
size_t			_to_page_size_multiple(size_t size);
t_malloc		*_malloc_singleton(void);

#endif
