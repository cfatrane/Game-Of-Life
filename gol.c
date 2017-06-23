/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gol.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfatrane <cfatrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/29 13:06:58 by cfatrane          #+#    #+#             */
/*   Updated: 2017/05/30 18:36:57 by cfatrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <stdlib.h>
# include <stdio.h>
# include "../ft_printf/includes/ft_printf.h"

# define USAGE "./gol [collumns] [lines]\n"

int		**malloc_map(int lines, int collumns);

int		ft_count(int **map, int i, int j, int lines, int collumns)
{
	int	count;
	int	up;
	int	down;
	int	left;
	int	right;

	up = (i > 0  && (map[i - 1][j] == 0 || map[i - 1][j] == 1) ? 1 : 0);
	down = (i < lines - 1 && (map[i + 1][j] == 0 || map[i + 1][j] == 1) ? 1 : 0);
	left = (j > 0 && (map[i][j - 1] == 0 || map[i][j - 1] == 1) ? 1 : 0);
	right = (j < collumns - 1 && (map[i][j + 1] == 0 || map[i][j + 1] == 1) ? 1 : 0);
	count = up + down + left + right;
	return (count);
}

int		count_neighbour(int **map, int lines, int collumns)
{
	int	count;
	int	i;
	int	j;

	i = 0;
	j = 0;
	count = 0;
	while (i < lines)
	{
		while (j < collumns)
		{
			ft_printf("%d ", ft_count(map, i, j, lines, collumns));
			j++;
		}
		ft_printf("\n");
		j = 0;
		i++;
	}
	return (count);
}

void	fill_tab(int **map, int lines, int collumns)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < lines)
	{
		while (j < collumns)
		{
			map[i][j] = 0;
			j++;
		}
		j = 0;
		i++;
	}
}

void	print_map(int **map, int lines, int collumns)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < lines)
	{
		while (j < collumns)
		{
			ft_printf("%d ", map[i][j]);
			j++;
		}
		ft_printf("\n");
		j = 0;
		i++;
	}
}

int		main(int argc, char **argv)
{
	if (argc > 1)
	{
		int		collumns;
		int		lines;
		int		**map;

		collumns = atoi(argv[1]);
		lines = atoi(argv[2]);

		map = ft_tabnew_two(collumns, lines);
	//	map = malloc_map(lines, collumns);
		fill_tab(map, lines, collumns);
		map[2][2] = 1;
		ft_printf("\n");
		print_map(map, lines, collumns);
		ft_printf("\n");
		count_neighbour(map, lines, collumns);
	}
	else
		ft_printf(USAGE);
	return (0);
}
/*
int		**malloc_map(int lines, int collumns)
{
	int	i;
	int	**ptr;

	ptr = malloc(lines * sizeof(*ptr));       //On alloue 'lines' pointeurs.
	if (ptr == NULL)
		return (NULL);

		for (i = 0 ; i < lines ; i++)
		{
			ptr[i] = malloc(collumns * sizeof(**ptr));       //On alloue des tableaux de 'collumns' variables.
			if (ptr[i] == NULL)
			{                              //En cas d'erreur d'allocation
				return (NULL);
			}
		}
	return (ptr);
}*/
