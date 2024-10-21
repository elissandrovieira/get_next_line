/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eteofilo <eteofilo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 14:44:20 by eteofilo          #+#    #+#             */
/*   Updated: 2024/10/21 15:54:30 by eteofilo         ###   ########.fr       */
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
	char		*tmp;

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
				tmp = str_print;
				str_print = ft_strjoin(tmp, buff);
				i++;
				*str = buff + i;
				return (str_print);
			}
			i++;
		}
		tmp = str_print;
		str_print = ft_strjoin(tmp, buff);
	}
	return (0);
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		*str_print;
	int			i;

	i = 0;
	if (!str)
	{
		str = (char *)ft_calloc(BUFFER_SIZE + 1, sizeof(char));
		if (!str)
			return (0);
		str_print = "\0";
	}
	else
	{
		while (str[i] != 0)
		{
			if(str[i] == '\n')
			{
				str[i] = '\0';
				str_print = str;
				i++;
				str = str + i;
				return (str_print);
			}
			i++;
		}
		str_print = str;
	}
	return (get_buffer(fd, str_print, &str));
}
