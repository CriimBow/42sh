/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   free_toks.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ggranjon <ggranjon@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/12 14:16:18 by ggranjon     #+#   ##    ##    #+#       */
/*   Updated: 2018/04/14 13:45:45 by ggranjon    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "shell.h"

void		free_toks(t_token **tokens)
{
	int i;

	i = 0;
	while (tokens && tokens[i])
	{
		ft_memdel((void **)&(tokens[i]->value));
		ft_memdel((void **)&(tokens[i]));
		i++;
	}
	ft_memdel((void **)&tokens);
}
