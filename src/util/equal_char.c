/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   equal_char.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ggranjon <ggranjon@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/08 13:35:18 by ggranjon     #+#   ##    ##    #+#       */
/*   Updated: 2018/04/14 13:45:45 by ggranjon    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "shell.h"

int				nb_equal_char(char *s1, char *s2)
{
	int		ret;

	ret = 0;
	while (*s1 && *s1 == *s2)
	{
		s1++;
		s2++;
		ret++;
	}
	return (ret);
}
