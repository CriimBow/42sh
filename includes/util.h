/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   util.h                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aviscogl <aviscogl@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/21 15:53:14 by aviscogl     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/31 19:58:28 by aviscogl    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef UTIL_H
# define UTIL_H

# include <stdlib.h>

void	*ft_realloc(void *ptr, size_t size);
char	*ft_char_to_str(char c);
void	free_tab(char **table);
char	**env_to_array(void);
size_t	env_size(void);
void	ft_copy_str(char *dest, char *src);

#endif
