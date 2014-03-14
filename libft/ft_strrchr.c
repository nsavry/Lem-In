/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsavry <nsavry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 12:43:37 by nsavry            #+#    #+#             */
/*   Updated: 2013/11/28 16:31:25 by nsavry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
size_t	ft_strlen(const char *str);

char	*ft_strrchr(const char *str, int c)
{
	size_t	len;

	len = ft_strlen(str);
	while ((len) != 0)
	{
		if (str[len] == (char)c)
			return ((char *)&str[len]);
		len--;
	}
	if (str[0] == (char)c)
		return ((char *)str);
	return (NULL);
}
