/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   union.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvanden- <jvanden-@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 14:38:18 by jvanden-          #+#    #+#             */
/*   Updated: 2021/09/30 14:44:43 by jvanden-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	was_in_str(char c, char *str, int start)
{
	while (start)
	{
		if (c == str[start - 1])
			return (1);
		start--;
	}
	return (0);
}

void	ft_union(char *s1, char *s2)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (s1[i])
	{
		if (!was_in_str(s1[i], s1, i))
			write(1, &s1[i], 1);
		i++;
	}
	while (s2[j])
	{
		if (was_in_str(s2[j], s1, i) && was_in_str(s2[j], s2, j))
			ft_putchar(s2[j]);
		j++;	
	}
}

int main(int ac, char **av)
{
	if (ac == 3)
		ft_union(av[1], av[2]);
	write(1, "\n", 1);
}
