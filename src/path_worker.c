/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_worker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcohere <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/07 01:35:24 by vcohere           #+#    #+#             */
/*   Updated: 2015/01/07 01:35:25 by vcohere          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh1.h"

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

char		*get_home(char **env)
{
	(void)env;
	return (NULL);
}

char		*get_env_var(char **env, char *var)
{
	while (*env)
	{
		if (!ft_strncmp(*env, var, ft_strlen(var) - 1))
			return (*env + ft_strlen(var) + 1);
		env++;
	}
	return (NULL);
}

char		*get_envar(char *env)
{
	int		i;

	i = -1;
	if (!env)
		return (NULL);
	while (env[++i] && env[i] != '=')
		;
	return (ft_strsub(env, 0, i));
}
