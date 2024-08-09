/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atovoman <atovoman@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 15:24:36 by atovoman          #+#    #+#             */
/*   Updated: 2024/07/30 12:53:57 by atovoman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_strlen(char *readed)
{
	int	i;

	i = 0;
	if (!readed)
		return (0);
	while (readed[i] != '\0')
		i++;
	return (i);
}

char	*ft_strdup(char *s)
{
	char	*dest;
	int		i;

	i = ft_strlen(s);
	dest = (char *)malloc(sizeof(char) * (i + 1));
	if (!dest)
		return (0);
	i = 0;
	while (s[i] != '\0')
	{
		dest[i] = s[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*add_to_readed(char *readed, char *buf)
{
	char	*dest;
	int		i;
	int		j;

	i = ft_strlen(readed);
	j = ft_strlen(buf);
	dest = (char *)malloc(sizeof(char) * (i + j + 1));
	if (!dest)
		return (0);
	i = 0;
	while (readed[i] != '\0')
	{
		dest[i] = readed[i];
		i++;
	}
	j = 0;
	while (buf[j] != '\0')
		dest[i++] = buf[j++];
	dest[i] = '\0';
	free(readed);
	return (dest);
}

char	*ft_substr(char *s, int start, int len)
{
	char	*dest;
	int		i;

	if (!s)
		return (0);
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	if (len >= ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	i = 0;
	dest = (char *)malloc(sizeof(char) * (len + 1));
	if (!dest)
		return (0);
	while (s[start] != '\0' && i < len)
	{
		dest[i] = s[start];
		i++;
		start++;
	}
	dest[i] = '\0';
	return (dest);
}
