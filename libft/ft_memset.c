/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmashigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/24 09:45:00 by tmashigo          #+#    #+#             */
/*   Updated: 2018/09/24 09:45:44 by tmashigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memset(void *b, int c, size_t len)
{
	char	*b2;
	char	c2;
	size_t	i;

	b2 = (char*)b;
	c2 = (unsigned char)c;
	i = 0;
	while (i < len)
	{
		b2[i] = c2;
		i++;
	}
	return (b2);
}
