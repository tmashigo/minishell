/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_environ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmashigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 09:07:15 by tmashigo          #+#    #+#             */
/*   Updated: 2018/09/17 09:07:22 by tmashigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void			print_env(void)
{
	int i;

	i = 0;
	while (g_envv[i])
	{
		ft_putendl(g_envv[i]);
		i++;
	}
}

int				envv_len(char **envv)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (envv[i])
	{
		count++;
		i++;
	}
	return (count);
}

static char		**reallocate_env(int new_size)
{
	char	**new_env;
	int		i;

	i = -1;
	new_env = (char**)malloc(sizeof(char*) * (new_size + 1));
	while (g_envv[++i] && i < new_size)
	{
		new_env[i] = ft_strdup(g_envv[i]);
		free(g_envv[i]);
	}
	free(g_envv);
	new_env[i] = NULL;
	return (new_env);
}

static void		remove_envv(int var_pos)
{
	int i;
	int var_count;

	free(g_envv[var_pos]);
	g_envv[var_pos] = NULL;
	i = var_pos;
	var_count = var_pos + 1;
	while (g_envv[i + 1])
	{
		g_envv[i] = ft_strdup(g_envv[i + 1]);
		free(g_envv[i + 1]);
		i++;
		var_count++;
	}
	g_envv = reallocate_env(var_count - 1);
}

int				my_unsetenv(char **args)
{
	int i;
	int var_pos;

	i = 0;
	if (!args[0])
	{
		ft_putendl("unsetenv: \033[31mToo few argument.\033[0m");
		return (1);
	}
	while (args[i])
	{
		var_pos = find_position(args[i]);
		if (g_envv[var_pos])
			remove_envv(var_pos);
		i++;
	}
	return (1);
}
