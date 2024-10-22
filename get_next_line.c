/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eteofilo <eteofilo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 14:44:20 by eteofilo          #+#    #+#             */
/*   Updated: 2024/10/22 17:42:41 by eteofilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <string.h>

char	*get_buffer(int fd, char *str_print, char **str)
{
	int			len;
	int			i;
	// char		*buff;
	char		buff[BUFFER_SIZE + 1];

	len = 1;
	// buff = (char *)ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	// if (!buff)
	// 	return (0);
	while (len > 0)
	{
		len = read(fd, buff, BUFFER_SIZE);
		i = 0;
		while (i < len && buff[i] != 0)
		{
			if (buff[i] == '\n')
			{
				buff[i] = '\0';
				str_print = ft_strjoin(str_print, buff, 1);
				i++;
				*str = ft_strdup(buff + i);
				// free(buff);
				return (str_print);
			}
			i++;
		}
		str_print = ft_strjoin(str_print, buff, 0);
	}
	// free(buff);
	free(str_print);
	return (0);
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		*str_print;
	char		*tmp;
	int			i;

	i = 0;
	if (!str)
	{
		str = "\0";
		str_print = "\0";
	}
	else
	{
		while (str[i] != 0)
		{
			if(str[i] == '\n')
			{
				str[i] = '\0';
				str_print = ft_strjoin("\0", str, 1);
				i++;
				tmp = str;
				str = str + i;
				free(tmp);
				return (str_print);
			}
			i++;
		}
		str_print = str;
		//free(str);
	}
	return (get_buffer(fd, str_print, &str));
}
