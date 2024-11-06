/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eteofilo <eteofilo@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 13:04:42 by eteofilo          #+#    #+#             */
/*   Updated: 2024/11/06 11:43:10 by eteofilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*str;
	int			len;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	str = ft_strjoin(0, buffer);
	if (check_nl(buffer) > 0)
		return (str);
	len = read(fd, buffer, BUFFER_SIZE);
	if (len < 0)
	{
		free(str);
		return (NULL);
	}
	while (len > 0)
	{
		str = ft_strjoin(str, buffer);
		if (check_nl(buffer) > 0)
			break ;
		len = read(fd, buffer, BUFFER_SIZE);
	}
	return (str);
}
