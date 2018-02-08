/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   shell.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ggranjon <ggranjon@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/30 14:44:16 by ggranjon     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/08 15:40:05 by ggranjon    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "shell.h"

t_shell	g_shell;

int	main(void)
{
	char	*str;

	init_shell();
	if (!ht_get(g_shell.env, "TERM"))
	{
		message_err(TERM_ENV_NOT_SET, NULL);
		exit_shell();
		exit(EXIT_FAILURE);
	}
	while ((str = readline("shell> ", g_shell.line_edit)))
	{
		signal(SIGINT, sig_handler);
		shell_process(str);
		free(str);
	}
}
