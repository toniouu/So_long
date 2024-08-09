/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atovoman <atovoman@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 14:09:03 by atovoman          #+#    #+#             */
/*   Updated: 2024/07/30 12:35:26 by atovoman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_next_word_length(char *s, char c)
{
	int	length;

	length = 0;
	while (*s && *s != c)
	{
		length++;
		s++;
	}
	return (length);
}

void	ft_free_tab(char **s)
{
	int	i;

	i = 0;
	while (s[i] != NULL)
	{
		free(s[i]);
		i++;
	}
	free(s);
}

int	ft_word(char *s, char c)
{
	int	word;

	word = 0;
	while (*s != '\0')
	{
		while (*s == c && *s != '\0')
			s++;
		if (*s != '\0')
			word++;
		while (*s != c && *s != '\0')
			s++;
	}
	return (word);
}

char	**ft_split(char *s, char c)
{
	char	**tab;
	int		t_tab;

	t_tab = 0;
	tab = (char **)malloc(sizeof(char *) * (ft_word(s, c) + 1));
	if (!tab || !s)
		return (0);
	while (*s != '\0')
	{
		while (*s == c && *s)
			s++;
		if (*s != '\0')
		{
			tab[t_tab] = ft_substr(s, 0, ft_next_word_length(s, c));
			if (!(tab[t_tab++]))
			{
				ft_free_tab(tab);
				return (0);
			}
			s += ft_next_word_length(s, c);
		}
	}
	tab[t_tab] = 0;
	return (tab);
}
