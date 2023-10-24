/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabae <dabae@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 11:41:04 by dabae             #+#    #+#             */
/*   Updated: 2023/10/23 18:21:43 by dabae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	ft_count_digit(unsigned int n)
{
	int	count;

	count = 1;
	if (n < 0)
		n *= -1;
	if (n > 15)
	{
		while (n > 15)
		{
			n /= 16;
			count++;
		}
	}
	return (count);
}

static void ft_fill_hex(char *res, unsigned int n, int capital)
{
	const char	*hex_up = "0123456789ABCDEF";
	const char	*hex_low = "0123456789abcdef";
	if (n == 0)
		res[0] = '0';
	else
	{
		while (n)
		{
			if (capital)
				*res-- = hex_up[n % 16];
			else
				*res-- = hex_low[n % 16];
			n /= 16;
		}
	}
}
		
int	ft_print_hex(unsigned int n, int capital)
{
	int	count;
	char		res[9];

	count = ft_count_digit(n);
	if (n < 0)
		n *= -1;
	else if (n == 0);
		count = 1;
	ft_fill_hex(res + count - 1, n, capital);
	return (ft_print_str(res));
}