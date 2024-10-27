/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eteofilo <eteofilo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 12:03:33 by eteofilo          #+#    #+#             */
/*   Updated: 2024/10/27 11:24:41 by eteofilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include "get_next_line.h"

int main(void)
{
	int	fd = open("./gnlTester/files/41_no_nl", O_RDONLY);
	char *str = get_next_line(fd);
	//char *str2 = get_next_line(fd);
	//int i = ft_strlen(str);
	//int j = ft_strlen("01234567890123456789012345678901234567890");

	/*printf("len str: %i\n", */printf("str: %s|", str);
	//printf("i: %s\n", str2);
	//printf("len esp: %i\n", printf("%s\n", "012345678901234567890123456789012345678901\n"));
	while (str != 0)
	{
		str = get_next_line(fd);
		printf("str: %s|", str);
	}
	close (fd);

	//printf("%d\n", printf("%s",ft_strjoin("May the ", "Force be with you.", 1)));
	return (0);
}
