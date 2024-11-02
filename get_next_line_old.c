/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eteofilo <eteofilo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 11:47:54 by eteofilo          #+#    #+#             */
/*   Updated: 2024/11/02 11:49:57 by eteofilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "get_next_line.h"
#include <stdio.h>

char	*get_buffer(int fd);
int	check_nl(char *s_check);
void	to_free(char **s);

char    *get_next_line(int fd) {
	static char *s_cache;
	char		*s_tmp;
	char		*s_return;
	int		 len;

	s_return = NULL;
	if (!s_cache)
		s_cache = get_buffer(fd);
	if (!s_cache)
		return (NULL);
	len = check_nl(s_cache);
	if (s_cache[len] == '\n') {
		s_return = ft_substr(s_cache, 0, len + 1);
		s_tmp = ft_substr(s_cache, len + 1, ft_strlen(s_cache) - len);
		to_free(&s_cache);
		s_cache = s_tmp;
	} else if (s_cache[len] == '\0' && s_cache[0] != '\0') {
		s_return = ft_substr(s_cache, 0, ft_strlen(s_cache));
		to_free(&s_cache);
	}

	return (s_return);
}

char	*get_buffer(int fd) {
	char	*s_buffer;
	char	*s_return;
	int	 len;

	s_buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!s_buffer)
		return (NULL);
	s_return = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!s_return) {
		to_free(&s_buffer);
		return (NULL);
	}
	len = read(fd, s_buffer, BUFFER_SIZE);
	if (len == 0) {
		to_free(&s_buffer);
		to_free(&s_return);
		return (NULL);
	}
	while (len > 0) {
		s_return = ft_strjoin(s_return, s_buffer);
		to_free(&s_buffer);
		s_buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
		if (!s_buffer)
			return (NULL);
		len = read(fd, s_buffer, BUFFER_SIZE);
	}
	to_free(&s_buffer);
	return (s_return);
}

int check_nl(char *s_check) {
	int i;

	i = 0;
	while (s_check[i] != '\0' && s_check[i] != '\n')
		i++;
	return (i);
}

void to_free(char **s) {
	free(*s);
	*s = NULL;
}
