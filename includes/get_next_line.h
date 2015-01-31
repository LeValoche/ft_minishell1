/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcohere <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/29 00:52:51 by vcohere           #+#    #+#             */
/*   Updated: 2014/12/17 03:21:23 by vcohere          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFF_SIZE 32
# include "../libft/includes/libft.h"
# include <unistd.h>
# include <fcntl.h>
# include <string.h>
# include <stdlib.h>

int					get_next_line(int const fd, char **line);

#endif
