/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   buf_append.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aviscogl <aviscogl@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/22 15:56:56 by aviscogl     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/23 10:19:36 by aviscogl    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "editor.h"

/*
** Append buffer with char *s of len len.
*/

void buf_append(t_buf *ab, const char *s, int len)
{
    char *new;
	
	new = ft_realloc(ab->b, ab->len + len);
    if (new == NULL)
		return;
    ft_memcpy(new + ab->len, s,len);
    ab->b = new;
    ab->len += len;
}