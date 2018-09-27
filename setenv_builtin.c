/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setenv_builtin.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmashigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 09:07:40 by tmashigo          #+#    #+#             */
/*   Updated: 2018/09/24 12:29:25 by tmashigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char			*find_envv(char *var)
{
	int		i;
	char	*temp;

	i = 0;
	while (g_envv[i])
	{
		temp = ft_strjoin(var, "=");
		if (ft_startwith(g_envv[i], temp))
		{
			free(temp);
			return (ft_strchr(g_envv[i], '=') + 1);
		}
		free(temp);
		i++;
	}
	return (NULL);
}

int				find_position(char *var)
{
	int		i;
	char	*temp;

	i = 0;
	while (g_envv[i])
	{
		temp = ft_strjoin(var, "=");
		if (ft_startwith(g_envv[i], temp))
		{
			free(temp);
			return (i);
		}
		free(temp);
		i++;
	}
	return (i);
}

static char		**realloc_envv(int new_size)
{
	char	**new_envv;
	int		i;

	i = -1;
	new_envv = (char**)malloc(sizeof(char*) * (new_size + 1));
	while (g_envv[++i] && i < new_size)
	{
		new_envv[i] = ft_strdup(g_envv[i]);
		free(g_envv[i]);
	}
	free(g_envv);
	return (new_envv);
}

void			set_env(char *name, char *value)
{
	int		pos;
	char	*temp;

	pos = find_position(name);
	temp = ft_strjoin("=", value);
	if (g_envv[pos])
	{
		free(g_envv[pos]);
		if (value)
			g_envv[pos] = ft_strjoin(name, temp);
	}
	else
	{
		g_envv = realloc_envv(pos + 1);
		if (value)
			g_envv[pos] = ft_strjoin(name, temp);
		g_envv[pos + 1] = NULL;
	}
	free(temp);
}

int				my_setenv(char **args)
{
	if (!args[0] || (args[0] && !args[1]))
	{
		ft_putendl("setenv: \033[31mToo few arguments.\033[0m");
		return (1);
	}
	if (args[0] && args[1])
	{
		if (args[2])
		{
			ft_putendl("setenv: \033[31mToo many arguments.\033[0m");
			return (1);
		}
		set_env(args[0], args[1]);
	}
	return (1);
}
