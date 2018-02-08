/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   b_cd.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aviscogl <aviscogl@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/05 18:56:46 by aviscogl     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/08 10:19:45 by aviscogl    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <shell.h>

static int	b_cd_old(char *const *args, const t_shell *shell)
{
	char cwd[2048];

	getcwd(cwd, sizeof(cwd));
	if (args[1][0] == '-' && ht_get(shell->env, "OLDPWD"))
	{
		if (chdir(ht_get(shell->env, "OLDPWD")) == -1)
		{
			err_builtins(ERR_CD_DIR, ht_get(shell->env, "OLDPWD"));
			return (0);
		}
		else
		{
			ht_set(shell->env, "OLDPWD", ft_strdup(cwd));
			ht_set(shell->env, "PWD", ft_strdup(getcwd(cwd, sizeof(cwd))));
			msg_builtins(MSG_CD, getcwd(cwd, sizeof(cwd)));
		}
	}
	else
	{
		err_builtins(ERR_NO_OLD_PWD);
		return (0);
	}
	return (1);
}

int			b_cd(char **args, t_shell *shell)
{
	char *dir;
	char cwd[2048];

	dir = args[1] == NULL ? ht_get(shell->env, "HOME") : args[1];
	if (args[1][0] == '-')
		return (b_cd_old(args, shell));
	if (getcwd(cwd, sizeof(cwd)) == NULL || access(dir, R_OK) == -1)
	{
		err_builtins(access(dir, R_OK) == -1 ? ERR_CD : ERR_CD_ACCESS,
		access(dir, R_OK) == -1 ? NULL : dir);
		return (0);
	}
	if (chdir(dir) == -1)
	{
		err_builtins(ERR_CD_DIR, args[1]);
		return (0);
	}
	ht_set(shell->env, "OLDPWD", ft_strdup(cwd));
	ht_set(shell->env, "PWD", ft_strdup(getcwd(cwd, sizeof(cwd))));
	msg_builtins(MSG_CD, getcwd(cwd, sizeof(cwd)));
	return (1);
}