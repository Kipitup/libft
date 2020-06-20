/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkante <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 17:57:07 by fkante            #+#    #+#             */
/*   Updated: 2020/05/18 23:33:58 by francis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *s1, const char *s2)
{
	size_t	i;
	size_t	y;

	y = 0;
	i = ft_strlen(s1);
	while (s2[y])
	{
		s1[i] = s2[y];
		y++;
		i++;
	}
	s1[i] = '\0';
	return (s1);
}
