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

char				*replace(char *str)
{
	int				i;

	i = -1;
	while (str[++i])
	{
		if (str[i] == '\t')
			str[i] = ' ';
	}
	return (str);
}

char				**cut_str(char *input)
{
	int				i;
	char			**res;

	i = -1;
	res = ft_strsplit(replace(input), ' ');
	while (res[++i])
	{
		res[i] = ft_strtrim(res[i]);
	}
	return (res);
}

int					change_dir(char *path, char ***env)
{
	char			oldpwd[1024];

	getcwd(oldpwd, sizeof(oldpwd));
	if (chdir(path) == -1)
		return (-1);
	*env = cmd_setenv(*env, ft_strjoin("OLDPWD=", oldpwd));
	getcwd(oldpwd, sizeof(oldpwd));
	*env = cmd_setenv(*env, ft_strjoin("PWD=", oldpwd));
	return (1);
}
