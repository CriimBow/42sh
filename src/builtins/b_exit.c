/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   b_exit.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ggranjon <ggranjon@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/05 18:56:46 by aviscogl     #+#   ##    ##    #+#       */
/*   Updated: 2018/04/14 13:45:45 by ggranjon    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "shell.h"

/*
** Exit the shell after free all requirements
** Take no arguments
*/

int		b_exit(char **args, t_shell *shell)
{
	int exit_status;

	(void)shell;
	disable_terminal(STDIN_FILENO);
	exit_shell();
	exit_status = (args && size_tab(args) >= 2) ? ft_atoi(args[1]) % 256 : 0;
	message(SHELL_EXIT, exit_status);
	free_3d_tab(g_shell.cmds);
	exit(exit_status);
}
