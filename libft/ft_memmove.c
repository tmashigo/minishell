/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmashigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/24 09:44:46 by tmashigo          #+#    #+#             */
/*   Updated: 2018/09/24 09:45:31 by tmashigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*dest;
	const char	*src2;

	dest = (char*)dst;
	src2 = (const char*)src;
	if (src2 < dest)
	{
		while (len)
		{
			len--;
			dest[len] = src2[len];
		}
	}
	else
		ft_memcpy(dest, src2, len);
	return (dest);
}
