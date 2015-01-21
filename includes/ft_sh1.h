/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sh1.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcohere <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/06 22:36:35 by vcohere           #+#    #+#             */
/*   Updated: 2015/01/06 22:44:27 by vcohere          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SH1
# define FT_SH1

# include <unistd.h>
# include <stdlib.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <signal.h>
# include "../libft/includes/libft.h"
# include "get_next_line.h"
# define RED    		"\x1b[31m"
# define GREEN   		"\x1b[32m"
# define YELLOW  		"\x1b[33m"
# define BLUE    		"\x1b[34m"
# define MAGENTA 		"\x1b[35m"
# define CYAN    		"\x1b[36m"
# define COLOR_RESET	"\x1b[0m"

char				**what_to_do(char **split, char **av, char **env);
void				cmd_cd(char **input, char **env);
char				**cmd_setenv(char **env, char *input);
char				**cmd_unsetenv(char **env, char **input);
void				cmd_env(char **env);
void				cmd_div(char **input, char **env);
char				*slash(char *str);
void				cmd_pwd(void);
char				*get_home(char **env);
char				*get_env_var(char **env, char *var);
void				ft_prompt(char **env, int e);
char				**set_env(void);
char				*get_envar(char *env);
int					ft_dbtablen(char **tab);
char				**ft_addrow(char **tab, char *str);
char				**ft_delrow(char **tab, char *str);
int					check_entry(char *input);
void				ft_puterror(char *s1, char *s2);
void				cmd_exec(char **input, char **env);
char				*ft_strtoup(char *str);

#endif
