/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmashigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/24 09:43:33 by tmashigo          #+#    #+#             */
/*   Updated: 2018/09/24 09:43:37 by tmashigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	char			*dest;
	const char		*src2;
	size_t			i;

	dest = (char*)dst;
	src2 = (const char*)src;
	i = 0;
	while (i < n)
	{
		if (*src2 == c)
		{
			*dest++ = *src2++;
			return (dest);
		}
		*dest++ = *src2++;
		i++;
	}
	return (NULL);
}
