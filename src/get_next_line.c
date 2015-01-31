/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcohere <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/29 00:56:15 by vcohere           #+#    #+#             */
/*   Updated: 2014/12/02 18:50:20 by vcohere          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/get_next_line.h"

static int			ft_find_nl(char *str)
{
	int				i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

static char			*ft_split_nl(char *acc)
{
	char			*str;
	int				i;
	int				size;

	i = ft_find_nl(acc);
	str = malloc(i + 1);
	ft_strncpy(str, acc, i);
	str[i] = 0;
	size = ft_strlen(acc) - i;
	ft_memmove(acc, acc + i + 1, size);
	acc[size] = 0;
	return (str);
}

static int			get_next_line2(char **acc, char *tmp, int fd, char **line)
{
	ssize_t			size;
	char			buffer[BUFF_SIZE + 1];

	while (ft_find_nl(*acc) == -1)
	{
		size = read(fd, buffer, BUFF_SIZE);
		if (size == 0)
		{
			if (**acc == 0)
			{
				free(*acc);
				*acc = NULL;
				return (0);
			}
			*line = ft_strdup(*acc);
			**acc = 0;
			return (1);
		}
		tmp = (char*)malloc(sizeof(char) * (ft_strlen(*acc) + size + 1));
		buffer[size] = '\0';
		ft_strcat(ft_strcpy(tmp, *acc), buffer);
		free(*acc);
		*acc = tmp;
	}
	return (-1);
}

int					get_next_line(int const fd, char **line)
{
	static char		*acc;
	int				ret;
	char			*tmp;

	tmp = 0;
	if (fd < 0)
		return (-1);
	if (acc == NULL)
	{
		acc = malloc(1);
		*acc = 0;
	}
	ret = get_next_line2(&acc, tmp, fd, line);
	if (ret == -1)
	{
		*line = ft_split_nl(acc);
		return (1);
	}
	return (ret);
}