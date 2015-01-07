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
	(void)env;
	(void)input;
}

void				cmd_unsetenv(char **env)
{
	(void)env;
}


void				cmd_env(char **env)
{
	while (*env)
		ft_putendl(*env++);
}

void				cmd_div(char **input, char **env)
{
	char			**paths;
	char			*save;
	int				i;
	pid_t			pid;

	paths = ft_strsplit(get_env_var(env, "PATH"), ':');
	i = 0;
	save = ft_strdup(input[0]);
	input[0] = ft_strjoin(slash(paths[i]), input[0]);
	pid = fork();
	if (pid == 0)
	{
		while (paths[i] && execve(ft_strjoin(slash(paths[i]), save), input, env) == -1)
		{
			input[0] = ft_strjoin(slash(paths[i]), save);
			i++;
		}
	}
	else
		wait(NULL);
}
