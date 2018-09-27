/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmashigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/24 09:59:33 by tmashigo          #+#    #+#             */
/*   Updated: 2018/09/24 09:59:42 by tmashigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*ans;
	int		i;

	i = ft_strlen(s);
	ans = 0;
	while (i >= 0)
	{
		if (*s == (char)c)
			ans = (char*)s;
		s++;
		i--;
	}
	return (ans);
}
