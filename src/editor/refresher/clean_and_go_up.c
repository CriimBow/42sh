/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   clean_and_go_up.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aviscogl <aviscogl@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/25 12:56:58 by aviscogl     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/25 14:01:09 by aviscogl    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "editor.h"

/*
** For every row clear it, go up
*/

void	clear_and_go_up(t_editor *e, t_refresher *r, t_buf *b)
{
	int			i;
	const char	*cmd = "\r\x1b[0K\x1b[1A";
	const int	len = 10;

	(void)e;
	i = 0;
	while (i < r->old_rows - 1)
	{
		buf_append(b, cmd, len);
		i++;
	}
}
