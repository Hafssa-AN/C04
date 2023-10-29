/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanebaro <hanebaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 23:44:54 by hanebaro          #+#    #+#             */
/*   Updated: 2023/10/29 04:46:48 by hanebaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	str_len(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	exist_twice(char *str)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (str[i] != '\0')
	{
		j = i + 1;
		while (str[j] != '\0')
		{
			if (str[j] == str[i])
				return (1);
			j++;
		}
		i++;
	}
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '+' || str[i] == '-')
			return (1);
		i++;
	}
	return (0);
}

int	exist_err(char *str)
{
	if (str_len(str) <= 1 || exist_twice(str))
		return (1);
	return (0);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int	ln;

	ln = str_len(base);
	if (exist_err(base))
		return ;
	if (nbr < 0)
	{
		ft_putchar('-');
		ft_putnbr_base(nbr * -1, base);
	}
	else if (nbr >= 0)
	{
		ft_putnbr_base(nbr / ln, base);
		ft_putchar(base[nbr % ln]);
	}
}
