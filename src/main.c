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

int				check_entry(char *input)
{
	if (!ft_isalpha(input[0]) && !ft_strnequ(input, "./", 2))
		ft_puterror("ft_minishell1: Please enter a command.", "");
	else if (ft_strlen(input) > 1024)
		ft_puterror("ft_minishell1: Input so fat.", "");
	else if (ft_strlen(input) == 0)
		ft_puterror("ft_minishell1: You must write something.", "");
	else
		return (1);
	return (0);
}

char			**what_to_do(char **split, char **av, char **env)
{
	(void)av;
	if (!*split)
		return (NULL);
	if (ft_strequ(split[0], "cd"))
		cmd_cd(split, env);
	else if (ft_strequ(split[0], "setenv"))
		env = cmd_setenv(env, split[1]);
	else if (ft_strequ(split[0], "unsetenv"))
		env = cmd_unsetenv(env, split);
	else if (ft_strequ(split[0], "env"))
		cmd_env(env);
	else if (ft_strequ(split[0], "exit"))
		kill(0, SIGTERM);
	else if (ft_strnequ(split[0], "./", 2))
		cmd_exec(split, env);
	else
		cmd_div(split, env);
	return (env);
}

void			ft_prompt(char **env, int e)
{
	char		buf[1024];
	static int	error;

	if (e)
	{
		error = 1;
		return ;
	}
	getcwd(buf, sizeof(buf));
	if (error)
		ft_putstr(ft_strjoin(RED, "X_X "));
	else
		ft_putstr(ft_strjoin(GREEN, "^_^ "));
	ft_putstr(COLOR_RESET);
	ft_putchar('[');
	ft_putstr(BLUE);
	if (!ft_strcmp(buf + 13, get_env_var(env, "HOME")))
		ft_putstr("~");
	else
		ft_putstr(ft_strrchr(buf, '/') + 1);
	ft_putstr(COLOR_RESET);
	ft_putstr("] ");
	error = 0;
}

char			**set_env(void)
{
	//char		*ret;
	char		*result;
	//int			fd;

			//NORME FUCKER

	//fd = open("misc/env", O_RDONLY);
	result = "";
	//while (ret = get_next_line(0, &ret))
	//	result = ft_strjoin(result, ft_strjoin(ret, " "));
	return (ft_strsplit(result, ' '));
}

int				main(int ac, char **av, char **env)
{
	char		*input;

	(void)ac;
	start_termios();
	if (!*env)
		env = set_env();
	signal(SIGINT, signal_handler);
	while (1)
	{
		ft_prompt(env, 0);
		input = get_next_line(1, env, 0);
		input = ft_strtrim(input);
		if (check_entry(input))
			env = what_to_do(ft_strsplit(input, ' '), av, env);
	}
}
