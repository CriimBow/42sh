/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   analyze.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ggranjon <ggranjon@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/23 17:56:38 by ggranjon     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/30 09:21:56 by ggranjon    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "shell.h"

static int	bad_red(char *s, t_token **tokens, int j)
{
	if (s[1])
	{
		if (s[0] == '<')
			if (s[1] == '>')
				return (-2);
		if (s[0] == '>')
			if (s[1] == '<')
				return (-2);
	}
	if ((ft_strlen(s) > 2 && (tokens[j + 1]) && tokens[j + 1]->type != SEP_OP))
		return (-2);
	return (0);
}

static int	analyze_red(t_block **block, t_token **tokens)
{
	int		i;
	int		j;

	i = 0;
	while ((*block)[i].start_tok != -1)
	{
		j = (*block)[i].start_tok;
		while (j <= (*block)[i].end_tok)
		{
			if (tokens[j]->type == IO_REDIR)
			{
				(*block)[i].isredir[0] = 1;
				if (ft_strlen(tokens[j]->value) <= 2 && (!(tokens[j + 1])
				|| tokens[j + 1]->type != FD_FILE || (tokens[j]->value[1] &&
				!ft_strchr(FT_REDIR, tokens[j]->value[1]))))
					return (-2);
				if (bad_red(tokens[j]->value, tokens, j) == -2)
					return (-2);
			}
			j++;
		}
		i++;
	}
	return (0);
}

static int	analyze_after_fd(t_block **block, t_token **tokens)
{
	int		i;
	int		j;

	i = 0;
	while ((*block)[i].start_tok != -1)
	{
		j = (*block)[i].start_tok;
		while (j <= (*block)[i].end_tok)
		{
			if (tokens[j]->type == FD_FILE)
			{
				if (tokens[j + 1] && tokens[j + 1]->type != SEP_OP)
					return (-2);
			}
			j++;
		}
		i++;
	}
	return (0);
}

static int	analyze_pipe(t_block **block, t_token **tokens)
{
	int		i;
	int		j;

	i = 0;
	while ((*block)[i].start_tok != -1)
	{
		j = (*block)[i].start_tok;
		while (j <= (*block)[i].end_tok)
		{
			if (tokens[j]->value[0] == '|')
			{
				(*block)[i].nb_pipe++;
				if (!(tokens[j + 1]) || tokens[j + 1]->type != COMMAND ||
				(tokens[j]->value[1] && tokens[j]->value[1] != '|'))
					return (-2);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int			analyze_block(t_block **blocks, t_token **tokens)
{
	if (analyze_red(blocks, tokens) == -2)
	{
		e_parse(ERR_REDIR, NULL);
		return (-2);
	}
	if (analyze_pipe(blocks, tokens) == -2)
	{
		e_parse(ERR_PIPE, NULL);
		return (-2);
	}
	if (analyze_after_fd(blocks, tokens) == -2)
	{
		e_parse(ERR_AFTER_FD, NULL);
		return (-2);
	}
	return (0);
}
