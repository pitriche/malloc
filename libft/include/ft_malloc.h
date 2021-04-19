/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 19:05:26 by pitriche          #+#    #+#             */
/*   Updated: 2021/04/18 16:06:13 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MALLOC_H
# define FT_MALLOC_H

# include <unistd.h>
# include <stdlib.h>

# include <sys/resource.h>
# include <sys/mman.h>


/*
** for 4096B pages
** tiny malloc have 1 page of meta for 1 page of data
** small malloc have 4 page of meta for 64 page of data
** large malloc have 2 pages of meta for 511 to inf pages of data
** (and it really doesn't matter)
*/
# define TINY_SIZE			64
# define MEMORY_TINY_SIZE	4096	// size of memory in each page
# define MAX_TINY_BLOC		510		// number of max size elements in each page

# define MEDIUM_SIZE		4096
# define MEMORY_MEDIUM_SIZE	262144
# define MAX_MEDIUM_BLOC	2046

# define MAX_LARGE_BLOC	511

typedef struct	s_malloc_bloc
{
	unsigned	off;
	unsigned	len;
}				t_malloc_bloc;

typedef struct	s_malloc_tiny
{
	unsigned char			memory[MEMORY_TINY_SIZE];

	t_malloc_bloc			bloc[MAX_TINY_BLOC];
	unsigned				number_bloc;
	// unsigned				memory_free;
	struct s_malloc_tiny	*next;
}				t_malloc_tiny;

typedef struct	s_malloc_medium
{
	char					memory[MEMORY_MEDIUM_SIZE];

	t_malloc_bloc			bloc[MAX_MEDIUM_BLOC];
	unsigned				number_bloc;
	struct	s_malloc_medium	*next;
}				t_malloc_medium;

typedef struct	s_malloc_large
{
	void					*mem[MAX_LARGE_BLOC];
	
	size_t					len[MAX_LARGE_BLOC];
	unsigned				number_bloc;
	struct	s_malloc_large	*next;
}				t_malloc_large;

typedef struct	s_malloc
{
	size_t				page_size;
	t_malloc_tiny		*tiny;
	t_malloc_medium		*medium;
	t_malloc_large		*large;
}				t_malloc;

void			ft_free(void *ptr);
void			*ft_malloc(size_t size);
void			*ft_realloc(void *ptr, size_t size);
void			show_alloc_mem(void);

/*
** malloc subfunctions
*/

t_malloc	*malloc_singleton(void)

#endif
