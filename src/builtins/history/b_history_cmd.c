/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   b_history_cmd.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aviscogl <aviscogl@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/07 10:43:11 by aviscogl     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/08 12:22:56 by ggranjon    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "shell.h"

t_builtins_fun	*b_history_handler(char *cmd)
{
	if (ft_strequ(cmd, "!!"))
		return (b_set_last_history);
	if (ft_isalpha(cmd[1]))
		return (b_set_history_start);
	if (ft_isdigit(cmd[1]))
		return (b_set_history_from_n);
	if (cmd[1] == '-')
		return (b_set_history_from_n_last);
	if (ft_strstarts_with_str(cmd, "!?"))
		return (b_set_history_contain);
	return (NULL);
}
