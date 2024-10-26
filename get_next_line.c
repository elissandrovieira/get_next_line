/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eteofilo <eteofilo@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 14:44:20 by eteofilo          #+#    #+#             */
/*   Updated: 2024/10/26 00:48:47 by eteofilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <string.h>

int	check_newl(char *str)
{
	int	i;

	if (!str)
		return (-1);
	i = 0;
	while (str[i] != 0 && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		return (i);
	return (0);
}

char	*get_buffer(int fd, char *str_print, char **str)
{
	int		len;
	int		i;
	char	*buff;
	char	*tmp;

	len = 1;
	buff = (char *)ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!buff)
		return (0);
	while (len > 0)
	{
		len = read(fd, buff, BUFFER_SIZE);
		i = 0;
		while (buff[i] != 0)
		{
			if (buff[i] == '\n')
			{
				i++;
				tmp = ft_substr(buff, 0, i);
				str_print = ft_strjoin(str_print, tmp);
				free(tmp);
				tmp = *str;
				*str = ft_substr(buff, i, ft_strlen(buff));
				free(tmp);
				free(buff);
				return (str_print);
			}
			if (len == 0)
			{
				free(buff);
				//free(*str);
				return(str_print);
			}
			i++;
		}
		str_print = ft_strjoin(str_print, buff);

	}
	free(buff);
	free(str_print);
	return (NULL);
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		*str_print;
	char		*tmp;
	int			size;

	str_print = ft_calloc(1, sizeof(char));
	size = check_newl(str);
	if (size < 0)
		str = (char *)ft_calloc(1, sizeof(char));
	else if (size > 0)
	{
		size++;
		str_print = ft_substr(str, 0,size);
		tmp = str;
		str = ft_substr(str,size, ft_strlen(str));
		free(tmp);
		return (str_print);
	}
	str_print = get_buffer(fd, str_print, &str);
	if (str_print == NULL)
	{
		free(str);
		str = NULL;
	}
	return (str_print);
}
