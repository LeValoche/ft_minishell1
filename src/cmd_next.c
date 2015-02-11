/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_next.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcohere <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/11 13:23:43 by vcohere           #+#    #+#             */
/*   Updated: 2015/02/11 13:23:44 by vcohere          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh1.h"

void				cmd_exec(char **input, char **env)
{
	if (ft_strnequ(input[0], "./", 2))
		*input += 2;
	if (access(input[0], F_OK) == -1)
		ft_puterror("ft_minishell1: No such file or directory: ", input[0]);
	else if (access(input[0], X_OK) == -1)
		ft_puterror("ft_minishell1: Permission denied: ", input[0]);
	else
		g_pid = fork();
	if (g_pid == 0)
	{
		if ((execve(input[0], input, env)) == -1 &&
			access(input[0], F_OK) == 0)
			ft_puterror("ft_minishell1: Not executable: ", input[0]);
	}
	else
	{
		waitpid(g_pid, NULL, 0);
		kill(g_pid, SIGUSR1);
	}
}

void				cmd_exit(char **input)
{
	int				i;

	i = 0;
	while (input[i])
		i++;
	if (i <= 1)
		exit(0);
	if (i == 2)
		exit(ft_atoi(input[1]));
	ft_puterror("exit: Too many arguments.", "");
}

void				cmd_env_div(char **input, char **env)
{
	char			**paths;
	char			*save;
	int				i;

	if (!get_env_var(env, "PATH"))
	{
		ft_puterror("ft_minishell1: Command not found: ", input[0]);
		return ;
	}
	paths = ft_strsplit(get_env_var(env, "PATH"), ':');
	i = -1;
	save = ft_strdup(input[0]);
	g_pid = fork();
	if (g_pid == 0)
	{
		while (paths[++i] && execve(ft_strjoin(slash(paths[i]), save),
			input, NULL) == -1)
			;
		if (!paths[i])
			ft_puterror("ft_minishell1: Command not found: ", save);
		exit(0);
	}
	else
		waitpid(g_pid, NULL, 0);
	kill(g_pid, SIGUSR1);
}
