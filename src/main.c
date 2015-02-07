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
	ft_putendl(input);
	FAIRE MARCHER LE ./
	if (!ft_isalpha(input[0]) && !ft_strchr(input, '/'))
		return (0);
	else if (ft_strlen(input) > 1024)
		ft_puterror("ft_minishell1: Input so fat.", "");
	else if (ft_strlen(input) == 0)
		ft_puterror("ft_minishell1: You must write something.", "");
	else
		return (1);
	return (0);
}

char			**what_to_do(char **split, char **env)
{
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
		cmd_exit(split);
	else if (ft_strchr(split[0], '/'))
		cmd_exec(split, env);
	else
		cmd_div(split, env);
	return (env);
}

void			ft_prompt(int e)
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
	ft_putstr(ft_strrchr(buf, '/') + 1);
	ft_putstr(COLOR_RESET);
	ft_putstr("] ");
	error = 0;
}

char			**set_env(void)
{
	char		*ret;
	char		*result;
	int			fd;

	fd = open("misc/env", O_RDONLY);
	result = "";
	while (get_next_line(fd, &ret))
	{
		ft_putendl(ret);
		result = ft_strjoin(result, ft_strjoin(ret, " "));
	}
	return (ft_strsplit(result, ' '));
}

int				main(int ac, char **av, char **env)
{
	char		*input;

	(void)ac;
	(void)av;
	if (!*env)
		env = set_env();
	input = NULL;
	while (1)
	{
		ft_prompt(0);
		get_next_line(0, &input);
		if (unvalid_entry(input))
			ft_putstr("");
		else if (check_entry(ft_strtrim(input)))
			env = what_to_do(cut_str(input), env);
	}
}
