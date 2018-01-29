/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   shell.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aviscogl <aviscogl@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/19 13:02:54 by aviscogl     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/29 13:29:11 by aviscogl    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "shell.h"

t_shell	g_shell;

int main2(char *s)
{
	t_token **tokens;
	t_block *test;

	tokens = NULL;
	test = NULL;

	if (parse_tokens(&tokens, s) == -1)
		printf("\nErreur parse tokens\n");

	int i = 0;
	while (tokens[i])
	{
		ft_printf("tokens %-2i : %-25s  valeur =  %i \n", i, tokens[i]->value, tokens[i]->type);
		i++;
	}
	ft_printf("value = %d => COMMAND\n", COMMAND);
	ft_printf("value = %d => ARG\n", ARG);
	ft_printf("value = 2 => IO_REDIR\n");
	ft_printf("value = 3 => SEP_OP\n");
	ft_printf("value = 4 => FD_FILE\n\n\n");

	int parse;

	if ((parse = parse_block(tokens, &test)) == -1)
		printf("\nErreur parse block\n");
	if (parse == -2)
		printf("\nQue des commentaires\n");
	i = 0;
	while (test[i].start_tok != -1)
	{
		ft_printf("BLOCK begin : %i\tBLOCK end : %i\n", test[i].start_tok, test[i].end_tok);
		ft_printf("IS RED : %i\n", test[i].isredir[0]);
		ft_printf("Type RED : %i\n", test[i].isredir[1]);
		ft_printf("Nombre de pipe : %i\n", test[i].nb_pipe);
		i++;
	}
	i = 0;
	while (tokens[i])
	{
		free(tokens[i]->value);
		free(tokens[i]);
		i++;
	}
	free(tokens);
	free(test);
}

int	main(void)
{
	char *str;
	
	set_env();
	set_bin();
	ht_print_debug(g_shell.bin, ht_print_str);
	while ((str = readline("get path for a binary ? ")))
	{
		if (ft_strequ("exit", str))
		{
			free(str);
			exit(0);
		}
		ft_printf("You want the path for: %s = ", str);
		// main2(str);
		t_node *node = ht_has(g_shell.bin, str);
		if (node)
			ft_printf("%s\n", (char *)node->value);
		else
			ft_printf("not found\n");
		free(str);
	}
}
