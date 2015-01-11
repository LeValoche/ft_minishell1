/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utiles.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcohere <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/07 21:33:04 by vcohere           #+#    #+#             */
/*   Updated: 2015/01/07 21:33:29 by vcohere          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh1.h"

int			ft_dbtablen(char **tab)
{
	int		i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}

char		**ft_delrow(char **tab, char *str)
{
	char	**db;
	int		i;

	db = (char **)malloc(sizeof(char *) * ft_dbtablen(tab));
	i = 0;
	while (i < ft_dbtablen(tab) - 1)
	{
		if (!ft_strcmp(get_envar(tab[i]), str))
		{
			while (i < ft_dbtablen(tab) - 1)
			{
				db[i] = ft_strdup(tab[i + 1]);
				i++;
			}
		}
		else
		{
			db[i] = ft_strdup(tab[i]);
			i++;
		}
	}
	db[i] = 0;
	return (db);
}

char		**ft_addrow(char **tab, char *str)
{
	char	**db;
	int		i;

	db = (char **)malloc(sizeof(char *) * ft_dbtablen(tab) + 2);
	i = 0;
	while (i < ft_dbtablen(tab))
	{
		db[i] = ft_strdup(tab[i]);
		i++;
	}
	db[i] = ft_strdup(str);
	db[i + 1] = 0;
	return (db);
}