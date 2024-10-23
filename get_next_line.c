// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   get_next_line.c                                    :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: eteofilo <eteofilo@student.42.fr>          +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2024/10/17 14:44:20 by eteofilo          #+#    #+#             */
// /*   Updated: 2024/10/23 14:03:35 by eteofilo         ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

// #include "get_next_line.h"
// #include <stdio.h>
// #include <string.h>

// char	*get_buffer(int fd, char *str_print, char **str)
// {
// 	int			len;
// 	int			i;
// 	 char		*buff;
// 	//char		buff[BUFFER_SIZE + 1];

// 	len = 1;
// 	buff = (char *)ft_calloc(BUFFER_SIZE + 1, sizeof(char));
// 	if (!buff)
// 		return (0);
// 	while (len > 0)
// 	{
// 		len = read(fd, buff, BUFFER_SIZE);
// 		i = 0;
// 		while (i < len && buff[i] != 0)
// 		{
// 			if (buff[i] == '\n')
// 			{
// 				buff[i] = '\0';
// 				str_print = ft_strjoin(str_print, buff, 1);
// 				i++;
// 				*str = ft_strdup(buff + i);
// 				free(buff);
// 				return (str_print);
// 			}
// 			i++;
// 		}
// 		str_print = ft_strjoin(str_print, buff, 0);
// 	}
// 	free(buff);
// 	//free(str_print);
// 	return (0);
// }

// char	*get_next_line(int fd)
// {
// 	static char	*str;
// 	char		*str_print;
// 	char		*tmp;
// 	int			i;

// 	i = 0;
// 	if (!str)
// 	{
// 		str = 0;
// 	}
// 	else
// 	{
// 		while (str)
// 		{
// 			if(str[i] == '\n')
// 			{
// 				str[i] = '\0';
// 				str_print = ft_strjoin("\0", str, 1);
// 				i++;
// 				tmp = str;
// 				str = ft_strdup(str + i);
// 				free(tmp);
// 				return (str_print);
// 			}
// 			i++;
// 		}
// 		free(str);
// 	}
// 	str_print = str;
// 	return (get_buffer(fd, str_print, &str));
// }


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
		while (i <= len && buff[i] != 0)
		{
			if (buff[i] == '\n')
			{
				i++;
				tmp = ft_substr(buff, 0, i);
				str_print = ft_strjoin(str_print, tmp, 0);
				*str = ft_substr(buff, i, ft_strlen(buff));
				free(tmp);
				free(buff);
				return (str_print);
			}
			else if (i == len)
				return(buff);
			i++;
		}
		str_print = ft_strjoin(str_print, buff, 1);

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
	int			i;

	i = 0;
	str_print = ft_calloc(1, sizeof(char));
	if (!str)
		str = "\0";
	else
	{
		while (str[i] != 0)
		{
			if (str[i] == '\n')
			{
				i++;
				str_print = ft_substr(str, 0, i);
				tmp = str;
				str = ft_substr(str, i, ft_strlen(str));
				free(tmp);
				return (str_print);
			}
			i++;
		}
	}
	//str_print = str;
	return (get_buffer(fd, str_print, &str));
}
