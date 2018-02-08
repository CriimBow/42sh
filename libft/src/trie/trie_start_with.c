/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   trie_start_with.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aviscogl <aviscogl@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/29 18:52:07 by aviscogl     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/07 14:46:31 by ggranjon    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

static void	trie_start_with_a(t_trie_node *root, char *prefix, t_heap *heap)
{
	char	*tmp_ch;
	char	*tmp;
	char	*tmpx;
	int		i;

	tmp = ft_strdup(prefix);
	if (root->is_word_end)
		heap_add(heap, ft_strdup(prefix));
	if (trie_is_last_node(root))
	{
		free(tmp);
		return ;
	}
	i = -1;
	while (++i < ALPHABET_SIZE)
	{
		if (root->children[i])
		{
			tmp_ch = malloc(sizeof(char) * 2);
			tmp_ch[0] = (char) i;
			tmp_ch[1] = 0;
			tmpx = ft_strjoin(tmp, tmp_ch);
			free(tmp_ch);
			trie_start_with_a(root->children[i], tmpx, heap);
			free(tmpx);
		}
	}
	free(tmp);
}

void		trie_start_with(t_trie_node *root, char *prefix, t_heap *heap)
{
	t_trie_node *cr;
	size_t		level;
	size_t		length;
	int			index;

	length = ft_strlen(prefix);
	level = 0;
	cr = root;
	while (level < length)
	{
		index = trie_char_to_index(prefix[level]);
		if (!cr->children[index])
			return ;
		cr = cr->children[index];
		level++;
	}
	if (cr->is_word_end && !cr->has_child)
	{
		heap_add(heap, ft_strdup(prefix));
		return ;
	}
	if (!trie_is_last_node(cr))
		trie_start_with_a(cr, prefix, heap);
}