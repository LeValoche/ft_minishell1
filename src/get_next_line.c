/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcohere <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/29 00:56:15 by vcohere           #+#    #+#             */
/*   Updated: 2015/01/27 11:48:17 by vcohere          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh1.h"
#define FUCK {ft_putchar(c); dest[i] = c; i++;}
#define BUFF_SIZE 1024
#define PROMPT {ft_putstr("\033[2J\033[1;1H"); ft_prompt(env, 0);}

char			ft_getc(int fd)
{
	char		b[1];
	int			ret;

	ret = read(fd, b, 1);
	if (ret == 0)
		return (0);
	if (ret < 0)
		return (-1);
	else
		return (*b);
}

int				backspace(char **env, int ret, int i, char **dest)
{
	ft_putstr("\033[2K\r");
	ft_prompt(env, ret);
	if (ft_strlen(*dest) > 0)
	{
		(*dest)[i - 1] = '\0';
		i -= 1;
		ft_putstr(*dest);
	}
	return (i);
}

char			*get_next_line(int fd, char **env, int ret)
{
	char		*dest;
	int			c;
	int			i;

	i = 0;
	dest = malloc(sizeof(char) * BUFF_SIZE);
	while ((c = ft_getc(fd)) != 0 && c != '\n' && i < BUFF_SIZE - 1)
	{
		if (c == 4)
			exit(0);
		else if (c == 127)
			i = backspace(env, ret, i, &dest);
		else if (c == 12)
		{
			PROMPT;
		}
		else
			FUCK;
	}
	ft_putendl("");
	dest[i] = '\0';
	return (ft_strdup(dest));
}
