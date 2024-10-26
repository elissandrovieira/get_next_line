/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eteofilo <eteofilo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 14:44:20 by eteofilo          #+#    #+#             */
/*   Updated: 2024/10/26 15:18:42 by eteofilo         ###   ########.fr       */
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
				*str = ft_substr(buff, i, len - i);
				free(tmp);
				free(buff);
				printf("\n is_print: %zu\n", ft_strlen(str_print));
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
		tmp = ft_substr(buff, 0, len);
		str_print = ft_strjoin(str_print, tmp);
		free(tmp);

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
	//printf("\nis_size: %d\n", size);
	if (size == -1)
		str = (char *)ft_calloc(1, sizeof(char));
	else if (size > 0)
	{
		//size++;
		tmp = str_print;
		str_print = ft_substr(str, 0, size);
		free(tmp);
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
