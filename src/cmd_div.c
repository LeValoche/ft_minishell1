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

void				cmd_cd(char **input)
{
	chdir(input[1]);
}

void				cmd_pwd(void)
{
	char			buf[1024];

	if (getcwd(buf, sizeof(buf)))
		ft_putendl(buf);
}

void				cmd_setenv(char **input)
{
	(void)input;
}

void				cmd_unsetenv(char **input)
{
	(void)input;
}


void				cmd_env(char **input)
{
	(void)input;
}

void				cmd_div(char **input)
{
	(void)input;
}
