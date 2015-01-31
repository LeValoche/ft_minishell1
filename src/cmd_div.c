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
	char			oldpwd[1024];

	getcwd(oldpwd, sizeof(oldpwd));
	if (!input[1])
	{
		if (chdir(get_env_var(env, "HOME")) == -1)
			ft_puterror("cd: Don't find home directory.", "");
		cmd_setenv(env, ft_strjoin("OLDPWD=", oldpwd));
		return ;
	}
	if (input[1][0] == '~')
	{
		input[1]++;
		input[1] = ft_strjoin(get_env_var(env, "HOME"), input[1]);
		cmd_setenv(env, ft_strjoin("OLDPWD=", oldpwd));
	}
	if (ft_strequ(input[1], "-"))
		chdir(get_env_var(env, "OLDPWD"));
	else if (access(input[1], F_OK) == -1)
		ft_puterror("cd: No such file or directory: ", input[1]);
	else if (access(input[1], X_OK) == -1)
		ft_puterror("cd: Permission denied: ", input[1]);
	else if (chdir(input[1]) == -1)
		ft_puterror("cd: Don't work: ", input[1]);
}

char				**cmd_setenv(char **env, char *input)
{
	int				i;

	i = 0;
	if (ft_strrchr(input, '=') == NULL)
	{
		ft_puterror("ft_minishell1: The variable need a value: ", input);
		return (env);
	}
	while (env[i])
	{
		if (!ft_strcmp(get_envar(env[i]), get_envar(input)))
		{
			env[i] = ft_strdup(input);
			return (env);
		}
		i++;
	}
	return (ft_addrow(env, input));
}

char				**cmd_unsetenv(char **env, char **input)
{
	if (!get_env_var(env, ft_strtoup(input[1])))
	{
		ft_puterror("ft_minishell1: Variable not found: ", input[1]);
		return (env);
	}
	return (ft_delrow(env, ft_strtoup(input[1])));
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

	if (!get_env_var(env, "PATH"))
		return ;
	paths = ft_strsplit(get_env_var(env, "PATH"), ':');
	i = -1;
	save = ft_strdup(input[0]);
	input[0] = ft_strjoin(slash(paths[0]), input[0]);
	pid = fork();
	if (pid == 0)
	{
		while (paths[++i] && execve(ft_strjoin(slash(paths[i]), save),
			input, env) == -1)
			input[0] = ft_strjoin(slash(paths[i]), save);
		if (!paths[i])
			ft_puterror("ft_minishell1: Command not found: ", save);
	}
	else
	{
		waitpid(pid, NULL, 0);
		kill(pid, SIGUSR1);
	}
}
