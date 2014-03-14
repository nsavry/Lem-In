/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsavry <nsavry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/02 12:37:40 by nsavry            #+#    #+#             */
/*   Updated: 2014/01/26 13:39:50 by nsavry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "libft.h"

int		ft_get_next_line(const int fd, char **line)
{
	int		i;
	char	buf[2];
	char	*str;
	char	*tmp;

	str = malloc(sizeof(*str) * 2);
	str[0] = 0;
	i = 0;
	buf[0] = 't';
	while (buf[0] != '\n')
	{
		if (read(fd, buf, 1) == 0)
			return (0);
		buf[1] = 0;
		tmp = malloc(sizeof(*str) * (i + 2));
		str[i] = buf[0];
		str[i + 1] = 0;
		tmp = str;
		str = malloc(sizeof(*str) * (i + 2));
		str = tmp;
		i++;
	}
	str[i - 1] = 0;
	*line = str;
	return (1);
}
