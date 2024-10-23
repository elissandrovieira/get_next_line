/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eteofilo <eteofilo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 15:23:23 by eteofilo          #+#    #+#             */
/*   Updated: 2024/10/23 15:48:40 by eteofilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void	ft_bzero(void *s, size_t n)
{
	char	*s1;
	char	*end;

	s1 = (char *)s;
	end = s1 + n;
	while (s1 != end)
	{
		*s1 = '\0';
		s1++;
	}
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != 0)
		i++;
	return (i);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	n;
	char	*ptr;

	if (nmemb == 0 || size == 0)
	{
		n = 1;
	}
	else
	{
		n = nmemb * size;
		if (n / nmemb != size)
			return (0);
	}
	ptr = (void *)malloc(n);
	if (!ptr)
		return (0);
	ft_bzero(ptr, n);
	return (ptr);
}

char	*ft_strdup(char *src)
{
	int		i;
	char	*dest;

	i = 0;
	if (src == 0)
		return (0);
	dest = (char *)malloc(sizeof(char) * (ft_strlen(src) + 1));
	if (dest == 0)
		return (0);
	while (src[i] != 0)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strjoin(char *s1, char *s2, int newl)
{
	int		size;
	int		i;
	int		j;
	char	*str;

	size = ft_strlen(s1) + ft_strlen(s2);
	str = (char *)malloc((size + newl + 1) * sizeof(char));
	if (!str)
		return (0);
	i = 0;
	j = 0;

	while (s1[i] != 0)
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[j] != 0)
		str[i++] = s2[j++];
	if (newl == 1)
		str[i++] = '\n';
	str[i] = '\0';
	free(s1);
	return (str);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	size;
	char	*str;

	if (!s)
		return (0);
	size = ft_strlen(s);
	if (start > size)
	{
		start = size;
		size = 0;
	}
	else
		size -= start;
	if (size > len)
		size = len;
	str = (char *)malloc((size + 1) * sizeof(char));
	if (!str)
		return (0);
	i = 0;
	while (s[start] != 0 && i < size)
		str[i++] = s[start++];
	str[i] = '\0';
	return (str);
}
