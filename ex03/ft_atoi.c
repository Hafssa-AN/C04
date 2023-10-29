/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanebaro <hanebaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 21:08:44 by hanebaro          #+#    #+#             */
/*   Updated: 2023/10/29 04:45:51 by hanebaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	sum_pow(char *str, int n, int sng)
{
	int	nb;
	int	i;
	int	j;
	int	sum;

	i = 0;
	sum = 0;
	while (str[i] != '\0')
	{
		j = i;
		nb = str[i] - 48;
		while (j < n - 1)
		{
			nb *= 10;
			j++;
		}
		sum += nb;
		i++;
	}
	if (sng % 2 == 1)
		sum *= -1;
	return (sum);
}

int	ft_atoi(char *str)
{
	int		signe;
	int		j;
	int		i;
	char	tab[11];

	i = 0;
	j = 0;
	signe = 0;
	while (str[i] != '\0' )
	{
		if (str[i] == '-')
			signe++;
		else if (str[i] >= '0' && str[i] <= '9')
		{
			tab[j] = str[i];
			j++;
		}
		else if (!(str[i] == ' ' || str[i] == '+'))
			break ;
		i++;
	}
	tab[j] = '\0';
	i = sum_pow(tab, j, signe);
	return (i);
}
