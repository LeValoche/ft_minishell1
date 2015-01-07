/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_div.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcohere <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/07 00:00:36 by vcohere           #+#    #+#             */
/*   Updated: 2015/01/07 00:00:37 by vcohere          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh1.h"

void				cmd_cd(char **input, char **env)
{
	struct stat		st;

	if (!input[1])
	{
		chdir(get_env_var(env, "HOME"));
		return ;
	}
	if (input[1][0] == '~')
	{
		input[1]++;
		input[1] = ft_strjoin(get_env_var(env, "HOME"), input[1]);
	}
	if (stat(input[1], &st) == 0)
		chdir(input[1]);
	else
	{
		ft_putstr("cd: No such file or directory: ");
		ft_putendl(input[1]);
	}
}

void				cmd_pwd(void)
{
	char			buf[1024];

	if (getcwd(buf, sizeof(buf)))
		ft_putendl(buf);
}

char				**cmd_setenv(char **env, char **input)
{
	int				i;

	i = -1;
	while (env[++i] && ft_strcmp(get_envar(env[i]), get_envar(input[1])))
		;
	if (!ft_strcmp(get_envar(env[i - 1]), get_envar(input[1])))
		env[i + 1] = 0;
	env[i] = ft_strdup(input[1]);
	return (env);
}

void				cmd_unsetenv(char **env)
{
	
}


void				cmd_env(char **env)
{
	while (*env)
		ft_putendl(*env++);
}

void				cmd_div(char **input)
{
	(void)input;
}
