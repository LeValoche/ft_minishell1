/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcohere <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/06 22:32:52 by vcohere           #+#    #+#             */
/*   Updated: 2015/01/06 22:32:55 by vcohere          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh1.h"

int			main(int ac, char **av)
{
	char	*input;

	(void)ac;
	input = NULL;
	while (1)
	{
		ft_putstr(" $>");
		get_next_line(1, &input);
		what_to_do(ft_strsplit(input, ' '), av);
	}
}

void		what_to_do(char **split, char **av)
{
	(void)av;
	if (!ft_strcmp(split[0], "cd"))
		cmd_cd(split);
	else if (!ft_strcmp(split[0], "setenv"))
		cmd_setenv(split);
	else if (!ft_strcmp(split[0], "unsetenv"))
		cmd_unsetenv(split);
	else if (!ft_strcmp(split[0], "env"))
		cmd_env(split);
	else if (!ft_strcmp(split[0], "pwd"))
		cmd_pwd();
	else if (!ft_strcmp(split[0], "exit"))
		exit(0);
	else
		cmd_div(split);
}

char		*slash(char *str)
{
	int		i;

	i = -1;
	while (str[++i])
		;
	if (str[i - 1] != '/')
		str = ft_strjoin(str, "/");
	return (str);
}
