/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamoulin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 10:43:50 by mamoulin          #+#    #+#             */
/*   Updated: 2023/11/23 12:16:18 by mamoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_words(char const *str, char c)
{
	size_t	count;
	size_t	i;

	count = 0;
	i = 0;
	while (*(str + i))
	{
		if (*(str + i) != c)
		{
			count++;
			while (*(str + i) && *(str + i) != c)
				i++;
		}
		else if (*(str + i) == c)
			i++;
	}
	return (count);
}

static size_t	word_len(char const *str, char c)
{
	size_t	i;

	i = 0;
	while (*(str + i) && *(str + i) != c)
		i++;
	return (i);
}

static void	free_tab(size_t i, char **tab)
{
	while (i > 0)
	{
		i--;
		free(*(tab + i));
	}
	free(tab);
}

static char	**split(char const *s, char c, char **tab, size_t words_count)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (i < words_count)
	{
		while (*(s + j) && *(s + j) == c)
			j++;
		*(tab + i) = ft_substr(s, j, word_len(&*(s + j), c));
		if (!*(tab + i))
		{
			free_tab(i, tab);
			return (NULL);
		}
		while (*(s + j) && *(s + j) != c)
			j++;
		i++;
	}
	*(tab + i) = NULL;
	return (tab);
}

char	**ft_split(char const *s, char c)
{
	char	**strs;
	size_t	words;

	if (!s)
		return (NULL);
	words = count_words(s, c);
	strs = (char **)malloc(sizeof(char *) * (words + 1));
	if (!strs)
		return (NULL);
	strs = split(s, c, strs, words);
	return (strs);
}

/*
int	main(void)
{
	char	**strs;
	char	*str;
	char	c;

	c = ' ';
	str = " tripoulle 42 ";

	strs = ft_split(str, c);

	printf("%s\n", strs[2]);
	return (0);
}*/
