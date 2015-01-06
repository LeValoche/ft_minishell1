/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sh1.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcohere <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/06 22:36:35 by vcohere           #+#    #+#             */
/*   Updated: 2015/01/06 22:44:27 by vcohere          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SH1
# define FT_SH1

# include <unistd.h>
# include <stdlib.h>
# include "../libft/includes/libft.h"
# include "get_next_line.h"

void				what_to_do(char **split, char **av);
void				cmd_cd(char **input);
void				cmd_setenv(char **input);
void				cmd_unsetenv(char **input);
void				cmd_env(char **input);
void				cmd_div(char **input);
char				*slash(char *str);
void				cmd_pwd(void);

#endif
