/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eteofilo <eteofilo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 14:44:20 by eteofilo          #+#    #+#             */
/*   Updated: 2024/10/27 12:41:23 by eteofilo         ###   ########.fr       */
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
	if (i == 0 && str[i] != '\n')
		i = -3;
	return (i + 1);
}

void	to_free(char **str)
{
	free(*str);
	*str = NULL;
}

char	*get_line(char **str, char *buff, char *str_print, int size, int len)
{
	char	*tmp;

	tmp = ft_substr(buff, 0,size);
	str_print = ft_strjoin(str_print, tmp);
	to_free(&tmp);
	to_free(str);
	*str = ft_substr(buff,size, len - size);
	to_free(&buff);
	return (str_print);
}

char	*get_buffer(int fd, char *str_print, char **str)
{
	int		len;
	int		size;
	char	*buff;
	char	*tmp;

	len = 1;
	buff = (char *)ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!buff)
		return (0);
	while (len > 0)
	{
		len = read(fd, buff, BUFFER_SIZE);
		size = check_newl(buff);
		if (size > 0 && buff[size -1] == '\n')
			return(get_line(str, buff, str_print, size, len));
		tmp = ft_substr(buff, 0, len);
		str_print = ft_strjoin(str_print, tmp);
		to_free(&tmp);
	}
	if (buff[0] != 0)
	{
		to_free(&buff);
		to_free(str);
		return (str_print);
	}
	to_free(&buff);
	to_free(&str_print);
	if (*str[0] != 0)
	{
		str_print = ft_substr(*str, 0, ft_strlen(*str));
		to_free(str);
		return (str_print);
	}
	return (NULL);
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		*str_print;
	char		*tmp;
	int			size;

	str_print = ft_calloc(1, sizeof(char));
	if (!str_print)
		return (NULL);
	size = check_newl(str);
	if (size == -1)
	{
		str = (char *)ft_calloc(1, sizeof(char));
		if(!str)
			return (NULL);
	}
	else if (size > 0)
	{
		if (str[size - 1] != '\n')
		{
			to_free(&str_print);
			tmp = ft_substr(str, 0, size);
			return (get_buffer(fd, tmp, &str));
		}
		tmp = ft_substr(str, 0, ft_strlen(str));
		return(get_line(&str, tmp, str_print, size, 0));
	}
	str_print = get_buffer(fd, str_print, &str);
	if (str_print == NULL)
		to_free(&str);
	return (str_print);
}
