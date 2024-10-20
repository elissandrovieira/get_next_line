/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eteofilo <eteofilo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 14:44:20 by eteofilo          #+#    #+#             */
/*   Updated: 2024/10/20 16:48:18 by eteofilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <string.h>

char	*get_buffer(int fd, char *str_print, char **str)
{
	int			len;
	int			i;
	char		*buff;

	len = 1;
	buff = (char *)ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	while (len > 0)
	{
		len = read(fd, buff, BUFFER_SIZE);
		i = 0;
		while (i < len && buff[i] != 0)
		{
			if (buff[i] == '\n')
			{
				buff[i] = '\0';
				str_print = ft_strjoin(str_print, buff);
				i++;
				*str = ft_strdup(buff + i);
				return (str_print);
			}
			i++;
		}
		str_print = ft_strjoin(str_print, buff);
	}
	return (0);
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		*str_print;

	if (!str)
	{
		str = (char *)ft_calloc(BUFFER_SIZE + 1, sizeof(char));
		if (!str)
			return (0);
		str_print = "\0";
	}
	else
		str_print = ft_strdup(str);
	return (get_buffer(fd, str_print, &str));
}
