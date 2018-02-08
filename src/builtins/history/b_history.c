/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   b_history.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aviscogl <aviscogl@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/05 18:56:46 by aviscogl     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/06 19:19:33 by aviscogl    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "shell.h"

int		b_history(char **args, t_shell *shell)
{
	t_heap *h;
	size_t i;
	size_t j;

	(void)args;
	(void)shell;
	if (!shell->line_edit->history_data || !shell->line_edit->history_data->heap
	|| shell->line_edit->history_data->heap->elements == 0)
	{
		err_builtins(ERR_NO_HISTORY);
		return (0);
	}
	h = shell->line_edit->history_data->heap;
	i = 0;
	j = 0;
	while (i < h->size)
	{
		if (h->list[i])
		{
			ft_printf(" * %i %s\n", j + 1, (char *)h->list[i]);
			j++;
		}
		i++;
	}
	return (1);
}