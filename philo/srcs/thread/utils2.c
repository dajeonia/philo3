/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajeon <dajeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 18:38:06 by dajeon            #+#    #+#             */
/*   Updated: 2023/08/26 12:58:03 by dajeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "thread.h"

int	ft_iseaten(t_philo *philo)
{
	int	ret;

	ret = 0;
	ft_lockstat(philo->iseaten);
	if (philo->dish == philo->info->number_of_times)
	{
		ft_setstat(philo->iseaten, 1);
		ret = 1;
	}
	ft_unlockstat(philo->iseaten);
	return (ret);
}

int	ft_isend(t_info *info)
{
	int	ret;

	ft_lockstat(&(info->isend));
	ret = ft_getstat(&(info->isend));
	ft_unlockstat(&(info->isend));
	return (ret);
}

int	ft_check_myself(t_philo *philo, t_info *info)
{
	if (ft_tvnow(ft_gettime(philo->eaten_time)) >= info->time_to_die)
		ft_kill(philo, info);
	return (0);
}
