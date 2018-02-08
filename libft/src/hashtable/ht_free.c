/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ht_free.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aviscogl <aviscogl@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/23 15:09:30 by aviscogl     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/07 14:46:31 by ggranjon    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	ht_default_free(t_hashtable *t, void *a)
{
	t_node *n;

	(void)t;
	if (a)
	{
		n = (t_node *)a;
		free(n->key);
		if (n->value && t->free_func)
			t->free_func(n->value);
		free(a);
	}
}

void	ht_free(t_hashtable *t)
{
	size_t i;
	size_t j;
	t_heap *h;

	i = 0;
	while (i < t->size)
	{
		h = t->heaps[i];
		if (h)
		{
			j = 0;
			while (j < h->size)
			{
				if (h->list[j])
					ht_default_free(t, h->list[j]);
				j++;
			}
			free(h->list);
			free(h);
		}
		i++;
	}
	free(t->heaps);
	free(t);
}