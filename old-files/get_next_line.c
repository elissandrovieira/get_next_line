/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eteofilo <eteofilo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 14:44:20 by eteofilo          #+#    #+#             */
/*   Updated: 2024/10/31 10:52:29 by eteofilo         ###   ########.fr       */
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

void	to_free(char **s1, char **s2)
{
	if (s1)
	{
		free(*s1);
		*s1 = NULL;
	}
	if (s2)
	{
		free(*s2);
		*s2 = NULL;
	}
}

char	*get_line(char **s, char *b, char *sp, int size, int len, int n)
{
	if (n == 0)
	{
		sp = ft_strjoin(sp, ft_substr(b, 0,size));
		to_free(s, NULL);
		*s = ft_substr(b,size, len - size);
		to_free(&b, NULL);
		return (sp);
	}
	if (n == 1)
	{
		if (b[0] != 0)
		{
			to_free(&b, s);
			return (sp);
		}
		to_free(&b, &sp);
		if (*s[0] != 0)
		{
			sp = ft_substr(*s, 0, ft_strlen(*s));
			to_free(s, NULL);
			return (sp);
		}
	}
	to_free(s, NULL);
	return (NULL);
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
			return(get_line(str, buff, str_print, size, len, 0));
		tmp = ft_substr(buff, 0, len);
		str_print = ft_strjoin(str_print, tmp);
	}
	str_print = get_line(str, buff, str_print, size, len, 1);
	return (str_print);
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		*str_print;
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
			to_free(&str_print, NULL);
			return (get_buffer(fd, ft_substr(str, 0, size), &str));
		}
		return(get_line(&str, ft_substr(str, 0, ft_strlen(str)), str_print, size, 0, 0));
	}
	return (get_buffer(fd, str_print, &str));
}
