/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gol.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfatrane <cfatrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/29 13:06:58 by cfatrane          #+#    #+#             */
/*   Updated: 2017/05/29 17:40:08 by cfatrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <stdlib.h>
# include <stdio.h>
# include "../ft_printf/includes/ft_printf.h"

# define USAGE "./gol [collumns] [lines]\n"

int		count_neighbout(int **map)
{
	int	count;

	count = 0;
	return(count);
}
void	fill_tab(int **map, int collumns, int lines)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i++ < lines)
	{
		while (j < collumns)
		{
			map[i][j] = 0;
			j++;
		}
		j = 0;
	}
}

void	print_map(int **map, int collumns, int lines)
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

		map = ft_tabnew_two(lines, collumns);
		fill_tab(map, collumns, lines);
		print_map(map, collumns, lines);
	}
	else
		ft_printf(USAGE);
	return (0);
}
