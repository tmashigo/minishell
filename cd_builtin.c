/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_builtin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmashigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 09:03:57 by tmashigo          #+#    #+#             */
/*   Updated: 2018/09/24 12:28:51 by tmashigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char		*shift(char *str)
{
	str++;
	str++;
	return (str);
}

static void		change_dir(char *path)
{
	char *cwd;
	char buff[4097];

	cwd = getcwd(buff, 4096);
	if (chdir(path) == 0)
		set_env("OLDPWD", cwd);
	else
	{
		ft_putstr("cd: ");
		ft_putstr(path);
		if (access(path, F_OK) == -1)
			ft_putendl(": no such file or directory");
		else if (access(path, R_OK) == -1)
			ft_putendl(": permission denied");
		else
			ft_putendl(": not a directory");
	}
}

static void		look_home(char *home_path, char *path)
{
	char *temp;
	char *temp2;

	temp = ft_strjoin(home_path, "/");
	temp2 = ft_strjoin(temp, shift(path));
	change_dir(temp2);
	free(temp);
	free(temp2);
}

int				my_cd(char **args)
{
	char *home_path;

	home_path = find_envv("HOME");
	if (!args[0] || (args[0][0] == '~' && !args[0][1]))
	{
		change_dir(home_path);
		return (1);
	}
	else
	{
		if (args[0][0] == '~' && args[0][1] == '/')
		{
			look_home(home_path, args[0]);
			return (1);
		}
		else if (args[0][0] == '-' && !args[0][1])
		{
			change_dir(find_envv("OLDPWD"));
			return (1);
		}
		change_dir(args[0]);
	}
	return (1);
}
