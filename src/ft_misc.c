/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_misc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcohere <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/21 14:06:04 by vcohere           #+#    #+#             */
/*   Updated: 2015/01/21 14:06:05 by vcohere          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh1.h"

void		cmd_exec(char **input, char **env)
{
	pid_t	pid;

	*input += 2;
	if (access(input[0], F_OK) == -1)
		ft_puterror("ft_minishell1: No such file or directory: ", input[0]);
	else if (access(input[0], X_OK) == -1)
		ft_puterror("ft_minishell1: Permission denied: ", input[0]);
	else
		pid = fork();
	if (pid == 0)
	{
		if ((execve(input[0], input + 1, env)) == -1)
			ft_puterror("ft_minishell1: Poney error: ", input[0]);
	}
	else
	{
		waitpid(pid, NULL, 0);
		kill(pid, SIGUSR1);
	}
}

char		*ft_strtoup(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= 'a' && str[i] <= 'z')
			str[i] -= 32;
		i++;
	}
	return (str);
}
