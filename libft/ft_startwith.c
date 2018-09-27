/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_startwith.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmashigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/24 09:50:02 by tmashigo          #+#    #+#             */
/*   Updated: 2018/09/24 09:50:07 by tmashigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_startwith(char *s1, char *s2)
{
	int i;

	i = -1;
	while (s2[++i])
		if (s1[i] != s2[i])
			return (0);
	return (1);
}
