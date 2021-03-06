/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/09 12:42:34 by zwang             #+#    #+#             */
/*   Updated: 2018/07/15 16:05:57 by zwang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strcmp(const char *s1, const char *s2)
{
	if (!(*s1) && !(*s2))
		return (0);
	if (*s1 != *s2)
		return (*((unsigned char *)s1) - *((unsigned char *)s2));
	return (ft_strcmp(s1 + 1, s2 + 1));
}
