/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nice_code.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblajan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/03 14:47:29 by vblajan           #+#    #+#             */
/*   Updated: 2015/11/03 15:15:50 by vblajan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char	**alloc(char **world)
{
	int	itterator;

	world = (char**)malloc(255 * sizeof(char*));
	itterator = -1;
	while (++itterator < 6)
		world[itterator] = (char*)malloc(255);
	return (world);
}

void	free_all(char **world)
{
	int itterator;

	itterator = -1;
	while (++itterator < 6)
		free(world[itterator]);
	free(world);
}

void	check_line(char **world)
{
	if (strcmp(world[4], "Cluj") == 0 && atof(world[3]) > 8.0)
		printf("%s %s\n", world[0], world[1]);
}

void	ft_split(char *buffer)
{
	char	**world;
	int		itterator;
	int		nr_cuv;
	int		nr_lit;

	world = alloc(world);
	itterator = -1;
	nr_cuv = 0;
	nr_lit = 0;
	while (buffer[++itterator])
	{
		if (buffer[itterator] == ';')
		{
			world[nr_cuv][nr_lit] = '\0';
			nr_cuv++;
			nr_lit = 0;
		}
		else
		{
			world[nr_cuv][nr_lit] = buffer[itterator];
			nr_lit++;
		}
	}
	check_line(world);
	free_all(world);
}

int		main(void)
{
	FILE	*file;
	char	buffer[255];

	file = fopen("student.csv", "r");
	while (fscanf(file, "%s", buffer) > 0)
	{
		ft_split(buffer);
	}
	return (0);
}
