/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   find_in_tab.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aviscogl <aviscogl@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/14 09:55:59 by aviscogl     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/13 09:43:51 by aviscogl    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

int		find_in_tab(char **t, char *arg)
{
	while (*t)
	{
		if (ft_strequ(arg, *t))
			return (1);
		t++;
	}
	return (0);
}
