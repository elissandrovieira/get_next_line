/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eteofilo <eteofilo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 14:44:20 by eteofilo          #+#    #+#             */
/*   Updated: 2024/10/27 11:29:51 by eteofilo         ###   ########.fr       */
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
				to_free(&tmp);
				to_free(str);
				*str = ft_substr(buff, i, len - i);
				to_free(&buff);
				return (str_print);
			}
			i++;
		}
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
	size = check_newl(str);
	if (size == -1)
		str = (char *)ft_calloc(1, sizeof(char));
	else if (size > 0)
	{
		if (str[size - 1] != '\n')
		{
			tmp = ft_substr(str, 0, ft_strlen(str));
			to_free(&str_print);
			str_print = get_buffer(fd, tmp, &str);
			return (str_print);
		}
		tmp = str_print;
		str_print = ft_substr(str, 0, size);
		to_free(&tmp);
		tmp = str;
		str = ft_substr(str, size, ft_strlen(str));
		to_free(&tmp);
		return (str_print);
	}
	str_print = get_buffer(fd, str_print, &str);
	if (str_print == NULL)
		to_free(&str);
	return (str_print);
}
