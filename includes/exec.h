/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   exec.h                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ggranjon <ggranjon@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/29 17:26:58 by ggranjon     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/07 14:46:31 by ggranjon    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef EXEC_H
# define EXEC_H

# include <unistd.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>

# define EXEC_FINISH	18
# define READ_END		0
# define WRITE_END		1

int			analyze_next_and_or(char *s);

char		**next_cmd(t_token **tokens, int index[2]);

int			is_executable(char *path);
int			call_right_redir(char **cmds);
int			call_left_redir(char **cmds);

int			there_is_pipe(char **argv);
int			exec_all_pipe(char ***argv);
char		***extract_all_pipes(char **argv);

int			go_next_index(t_token **tokens, t_block *blocks,
			int num[2], int ret);
int			go_to_next(t_token **tokens, t_block *block, int num, int index);
int			exec_or_and(t_token **tokens, t_block *blocks, int num[2], int ret);

int			replace_argv0_by_exec(char ***cmds);

int			fork_result(char *node, char **argv);

void		sig_handler(int signo);

#endif