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

int			main(int ac, char **av, char **env)
{
	char	*input;

	(void)ac;
	if (!*env)
		env = set_env();
	input = NULL;
	while (1)
	{
		ft_prompt(env);
		get_next_line(1, &input);
		env = what_to_do(ft_strsplit(input, ' '), av, env);
	}
}

char		**what_to_do(char **split, char **av, char **env)
{
	(void)av;
	if (!*split)
		return (NULL);
	if (!ft_strcmp(split[0], "cd"))
		cmd_cd(split, env);
	else if (!ft_strcmp(split[0], "setenv"))
		env = cmd_setenv(env, split);
	else if (!ft_strcmp(split[0], "unsetenv"))
		cmd_unsetenv(split);
	else if (!ft_strcmp(split[0], "env"))
		cmd_env(env);
	else if (!ft_strcmp(split[0], "pwd"))
		cmd_pwd();
	else if (!ft_strcmp(split[0], "exit"))
		exit(0);
	else
		cmd_div(split);
	return (env);
}

void		ft_prompt(char **env)
{
	char	buf[1024];

	getcwd(buf, sizeof(buf));
	ft_putstr(GREEN);
	ft_putstr("➜  ");
	ft_putstr(BLUE);
	if (!ft_strcmp(buf + 13, get_env_var(env, "HOME")))
		ft_putstr("~");
	else
		ft_putstr(ft_strrchr(buf, '/') + 1);
	ft_putstr(" ");
	ft_putstr(COLOR_RESET);
}

char		**set_env()
{
	char	*ret;
	char	*result;
	int		fd;

	fd = open("misc/env", O_RDONLY);
	result = "";
	while (get_next_line(fd, &ret) > 0)
		result = ft_strjoin(result, ft_strjoin(ret, " "));
	return (ft_strsplit(result, ' '));
}
