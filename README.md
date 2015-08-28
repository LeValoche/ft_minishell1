# ft_minishell1

Un shell minimaliste en C. Il ne supporte que les commandes simples ( pas de pipe ou de redirections ) et ne fonctionne pas avec les termcaps ( pas d'auto-completion par exemple ).

# Fonctionnement

La plupart des commandes sont appelees grace a execve(), les seules commandes a recoder sont :
env, setenv, unsetenv, cd et exit
