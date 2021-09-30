/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvanden- <jvanden-@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 14:37:21 by jvanden-          #+#    #+#             */
/*   Updated: 2021/09/30 14:41:24 by jvanden-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	is_in_str(char c, char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (c == str[i])
			return (1);
		i++;	
	}
	return (0);
}

int	was_in_str(char c, char *str, int start)
{
	while (start)
	{
		if (c == str[start - 1])
			return (0);
		str--;	
	}
	return (1);
}

int	main(int ac, char **av)
{
	int i;

	i = 0;
	if (ac == 3)
	{
		while (s1[i])
		{
			if (is_in_str(argv[1][i], argv[2]) && was_in_str(argv[1][i], argv[1], i))
				write(1, &argv[1][i], 1);
			i++;
		}
	}
	write(1, "\n", 1);
}
