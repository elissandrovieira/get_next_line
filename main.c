/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eteofilo <eteofilo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 12:03:33 by eteofilo          #+#    #+#             */
/*   Updated: 2024/10/22 14:34:01 by eteofilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"

int main(void)
{
	int	fd = open("1-brouette.txt", O_RDONLY);
	char *str = get_next_line(fd);
	printf("%s", str);
	while (str != 0)
	{
		str = get_next_line(fd);
		printf("%s\n", str);
	}
	close (fd);
	return (0);
}
