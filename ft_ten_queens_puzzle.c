#include <unistd.h>
#include <stdio.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_excl_rows(int col, int *pos, int *rows)
{
	int	i;

	printf("start ft_excl_rows \n");
	i = 0;
	while (i < 10)
	{
		rows[i] = 1;
		i++;
	}
	i = 0;
	while (i < col)
	{
		rows[pos[i]] = 0;
		if (pos[i] + col - i < 10)
		{
			printf("i: %d, col: %d, pos: %d, p+c-i %d\n", i, col, pos [i], pos[i] + col - i);
			rows[pos[i] + col - i] = 0;
		}
		if (pos[i] - col + i >= 0)
		{
			printf("i: %d, col: %d, pos: %d, p-c+i %d\n", i, col, pos [i], pos[i] - col + i);
			rows[pos[i] - col + i] = 0;
		}
		i++;
	}
}

void	ft_put_pos(int *pos)
{
	int	i;

	i = 0;
	while (i < 10)
	{
		ft_putchar(pos[i] + '0');
		i++;
	}
	ft_putchar('\n');
}

void	ft_queen_pos(int *pos, int *count)
{
	int	col;
	int	rows[10];
	int	i;

	col = 0;
	while (pos[col] != 99)
		col++;
	printf("ft_queen_pos col: %d\n", col);
	ft_excl_rows(col, pos, rows);
	i = 0;
	while (i < 10)
	{
		if (rows[i] == 1)
		{
			pos[col] = i;
			ft_queen_pos(pos, count);
			if (col == 9)
			{
				ft_put_pos(pos);
				*count = *count + 1;
			}
		}
		i++;
	}
}

int	ft_ten_queens_puzzle(void)
{
	int	pos[10];
	int	c;
	int	*count;
	int	i;

	i = 0;
	count = &c;
	*count = 0;
	while (i < 10)
	{
		pos[i] = 99;
		i++;
	}
	ft_queen_pos(pos, count);
	return(*count);
}

int	main(void)
{
	ft_ten_queens_puzzle();
	return (0);
}
