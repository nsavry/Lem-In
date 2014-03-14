/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr_bool.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsavry <nsavry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 13:04:09 by nsavry            #+#    #+#             */
/*   Updated: 2014/01/26 13:40:25 by nsavry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
static int	ft_solvestr(const char *str, const char *seek);

int			ft_strstr_bool(const char *str, const char *seek)
{
	if (!(*seek))
		return (0);
	else
		return (ft_solvestr(str, seek));
}

static int	ft_solvestr(const char *str, const char *seek)
{
	int		i1;
	int		i2;
	char	*ptr;

	i1 = 0;
	i2 = 0;
	while (str[i1] != 0)
	{
		while (str[i1] == seek[i2])
		{
			i1++;
			i2++;
			if (seek[i2] == 0)
			{
				ptr = (char *)&str[i1 - i2];
				return (1);
			}
		}
		i2 = 0;
		i1++;
	}
	return (0);
}
