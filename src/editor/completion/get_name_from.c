/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_name_from.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aviscogl <aviscogl@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/01 10:23:39 by aviscogl     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/03 09:18:16 by aviscogl    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "editor.h"

char	*get_name_from(char *str)
{
	const size_t	len = ft_strlen(str);
	size_t			i;
	size_t			prev;

	i = 0;
	prev = 0;
	while (i < len)
	{
		if (str[i] == '/')
			prev = i;
		i++;
	}
	return (ft_strsub(str, (unsigned int)prev + 1, len - (prev + 1)));
}
