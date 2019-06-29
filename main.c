/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mqian <mqian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 15:24:36 by grougeau          #+#    #+#             */
/*   Updated: 2019/06/29 14:13:36 by grougeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	solver2(int *nb, char ***array)
{
	char	**board;
	int		*coord;
	int		pn;
	int		width;

	pn = 0;
	coord = coordinates2(*nb, array);
	width = board_width(*nb);
	board = define_boardsize(width);
	while (solver(&*board, coord, *nb, pn) == 0)
		board = resize(&*board);
	print_board(board);
	clear_all(array, coord, *nb, board);
	return (0);
}

int	checker(char *filename)
{
	int		ret;
	int		a;
	int		*nb;
	char	***array;

	nb = &a;
	if (((array = store_tretrimino(filename, nb)) == NULL))
	{
		free_tetrimino(array, *nb);
		return (-1);
	}
	if ((ret = check_tetrimino(array, nb)) == -1)
	{
		free_tetrimino(array, *nb);
		return (-1);
	}
	solver2(nb, array);
	return (0);
}

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		ft_putstr(" usage: ./fillit source_file\n");
		return (-1);
	}
	else
	{
		if (checker(argv[1]) == -1)
		{
			ft_putstr("error\n");
			return (-1);
		}
	}
	return (0);
}
