/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_tab_contain.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ggranjon <ggranjon@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/11 16:59:30 by aviscogl     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/16 11:13:55 by ggranjon    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "shell.h"

int		ft_tab_contain(const char **tabi, char *src)
{
	while (*tabi && src)
	{
		if (ft_strequ(*tabi, src))
			return (1);
		tabi++;
	}
	return (0);
}
