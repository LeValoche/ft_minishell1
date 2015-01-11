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
	if (access(input[1], F_OK) == -1)
	{
		ft_putstr_fd("cd: No such file or directory: ", 2);
		ft_putendl(input[1]);
	}
	else if (access(input[1], X_OK) == -1)
	{
		ft_putstr_fd("cd: Permission denied: ", 2);
		ft_putendl(input[1]);
	}
	else
		chdir(input[1]);
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

	i = 0;
	while (env[i])
	{
		if (!ft_strcmp(get_envar(env[i]), get_envar(input[1])))
		{
			env[i] = ft_strdup(input[1]);
			return (env);
		}
		i++;
	}
	return (ft_addrow(env, input[1]));
}

char				**cmd_unsetenv(char **env, char **input)
{
	return (ft_delrow(env, input[1]));
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
	i = -1;
	save = ft_strdup(input[0]);
	input[0] = ft_strjoin(slash(paths[0]), input[0]);
	pid = fork();
	if (pid == 0)
	{
		while (paths[++i] && execve(ft_strjoin(slash(paths[i]), save), input, env) == -1)
			input[0] = ft_strjoin(slash(paths[i]), save);
		if (!paths[i])
		{
			ft_putstr_fd("ft_minishell1: Command not found: ", 2);
			ft_putendl(save);
		}
	}
	else
	{
		waitpid(pid, NULL, 0);
		kill(pid, SIGUSR1);
	}
}
