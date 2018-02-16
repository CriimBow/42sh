/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   heap_new.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ggranjon <ggranjon@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/23 10:31:49 by aviscogl     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/16 11:13:56 by ggranjon    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

t_heap	*heap_new(size_t default_size)
{
	t_heap *heap;

	heap = malloc(sizeof(t_heap));
	heap->size = default_size;
	heap->next_insert = 0;
	heap->elements = 0;
	heap->last_remove = -1;
	heap->list = ft_memalloc(default_size);
	heap->free_func = free;
	return (heap);
}
