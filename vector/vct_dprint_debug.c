/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vct_dprint_debug.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartinod <a.martino@sutdent.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/03 17:45:30 by amartinod         #+#    #+#             */
/*   Updated: 2020/07/19 09:21:15 by fkante           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"
#include "ft_printf.h"

/*
**	Print the vector on the given fd and some debug tool like the len. Return
**	the number of byte written for the vector only not the debug or FAILURE
**	if an error occur.
*/

ssize_t		vct_dprint_debug(int fd, t_vector *vector)
{
	ssize_t		ret;

	ret = FAILURE;
	if (fd >= 0 && vector != NULL && vector->str != NULL)
	{
		ft_dprintf(fd, "{c_green}len [%d]\n|->{c_end}", vector->len);
		ret = write(fd, vector->str, vector->len);
		ft_dprintf(fd, "{c_green}<-|{c_end}\n");
	}
	return (ret);
}
