/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stat.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajeon <dajeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 18:38:26 by dajeon            #+#    #+#             */
/*   Updated: 2023/08/25 18:38:27 by dajeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "status.h"

int	ft_lockstat(t_stat *stat)
{
	return (pthread_mutex_lock(&(stat->m_stat)));
}

int	ft_unlockstat(t_stat *stat)
{
	return (pthread_mutex_unlock(&(stat->m_stat)));
}

int	ft_setstat(t_stat *stat, int set)
{
	stat->stat = set;
	return (0);
}

int	ft_getstat(t_stat *stat)
{
	return (stat->stat);
}
