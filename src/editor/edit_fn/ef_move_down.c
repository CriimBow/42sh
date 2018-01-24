/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ef_move_down.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aviscogl <aviscogl@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/24 18:44:46 by aviscogl     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/24 19:14:17 by aviscogl    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "editor.h"

void	ef_move_down(t_editor *l)
{
	if ((l->pos + l->cols) < l->len)
		l->pos += l->cols;
	else
		l->pos = l->len;
	refresh_line(l);
}