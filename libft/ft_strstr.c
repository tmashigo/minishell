/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmashigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/24 10:00:57 by tmashigo          #+#    #+#             */
/*   Updated: 2018/09/24 10:01:02 by tmashigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(const char *big, const char *little)
{
	int		i;
	int		j;
	int		len;
	char	*big2;

	big2 = (char*)big;
	i = 0;
	len = 0;
	while (little[len] != '\0')
		len++;
	if (len == 0)
		return (big2);
	while (big2[i] != '\0')
	{
		j = 0;
		while (little[j] == big2[i + j])
		{
			if (little[j + 1] == '\0')
				return (big2 + i);
			j++;
		}
		i++;
	}
	return (0);
}
