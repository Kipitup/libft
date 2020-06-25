/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vct_get_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartinod <amartino@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/25 09:54:29 by amartinod         #+#    #+#             */
/*   Updated: 2020/06/25 09:56:21 by amartinod        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"
#include "libft.h"

t_vector		*vct_get_file(char *file_name)
{
	t_vector		*line;
	t_vector		*file;
	int32_t			fd;
	int8_t			ret;

	ret = TRUE;
	line = NULL;
	file = NULL;
	fd = open(file_name, O_RDWR);
	if (fd != FAILURE)
	{
		while (ret == TRUE)
		{
			ret = vct_read_line(fd, &line);
			file = vct_joinfree(&file, &line, BOTH);
			if (file == NULL)
				ret = ft_perror_failure("malloc failed", __FILE__, __LINE__);
		}
		vct_del(&line);
		if (ret == FAILURE)
			vct_del(&file);
	}
	else
		ft_perror("can't open the file", __FILE__, __LINE__);
	return (file);
}
