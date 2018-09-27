/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmashigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/24 09:43:46 by tmashigo          #+#    #+#             */
/*   Updated: 2018/09/24 09:43:51 by tmashigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*s2;
	unsigned char	c2;
	size_t			i;

	i = 0;
	s2 = (unsigned char*)s;
	c2 = (unsigned char)c;
	while (n > 0)
	{
		if (*s2 != c2)
		{
			s2++;
		}
		else
			return (s2);
		n--;
	}
	return (NULL);
}
