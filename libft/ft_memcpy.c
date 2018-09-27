/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmashigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/24 09:44:16 by tmashigo          #+#    #+#             */
/*   Updated: 2018/09/24 09:44:21 by tmashigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t		i;
	char		*dest;
	const char	*src2;

	i = 0;
	src2 = (const char*)src;
	dest = (char*)dst;
	while (i < n)
	{
		dest[i] = src2[i];
		i++;
	}
	return (dest);
}
