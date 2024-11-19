/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrahamsinsard <abrahamsinsard@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 18:17:58 by asinsard          #+#    #+#             */
/*   Updated: 2024/11/20 00:02:45 by abrahamsins      ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_new(t_list *lst, void (*del)(void *))
{
	lst = malloc(sizeof(t_list));
	if (!lst)
	{
		ft_lstclear(&lst, del);
		free(lst);
		return (NULL);
	}
	return (lst);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*new_cont;

	if (!lst || !f || !del)
		return (NULL);
	new_lst = NULL;
	while (lst)
	{
		new_cont = ft_new(f(lst->content), del);
		ft_lstadd_back(&new_lst, new_cont);
		lst = lst->next;
	}
	return (new_lst);
}
