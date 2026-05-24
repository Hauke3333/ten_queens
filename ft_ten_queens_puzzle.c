#include <unistd.h>
#include <stdio.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_put_pos(int *pos)
{
	int	j;

	j = 0;
	while (j < 10)
	{
		ft_putchar(pos[j] + '0');
		j++;
	}
	ft_putchar('\n');
}

int	pos_is_possible(int *pos, int col, int i_check)
{
	int	i;

	i = 0;
	while (i < 10)
	{
		if (i_check == pos[i])
			return (0);
		if (i_check == pos[i] + col - i)
			return (0);
		if (i_check == pos[i] - col + i)
			return (0);
		i++;
	}
	return (1);
}

void	ft_queen_pos(int *pos, int *count)
{
	int	col;
	int	i;

	col = 0;
	while (pos[col] != 99)
		col++;
	i = 0;
	while (i < 10)
	{
		if (pos_is_possible(pos, col, i))
		{
			pos[col] = i;
			if (col == 9)
			{
				ft_put_pos(pos);
				*count = *count + 1;
			}
			else
				ft_queen_pos(pos, count);
		}
		i++;
	}
	pos[col] = 99;
}

int	ft_ten_queens_puzzle(void)
{
	int	pos[10];
	int	c;
	int	*count;
	int	j;

	j = 0;
	c = 0;
	count = &c;
	while (j < 10)
	{
		pos[j] = 99;
		j++;
	}
	ft_queen_pos(pos, count);
	return(*count);
}

int	main(void)
{
	printf("Possible positions: %d\n", ft_ten_queens_puzzle());
	return (0);
}
